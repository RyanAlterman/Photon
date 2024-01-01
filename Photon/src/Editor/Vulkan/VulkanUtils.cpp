#include "VulkanUtils.h"

#include <iostream>

namespace Photon
{
	// Static Global Declarations
	static VkAllocationCallbacks* g_Allocator = nullptr;
	static VkInstance g_Instance = VK_NULL_HANDLE;
	static VkDebugReportCallbackEXT g_DebugReport = VK_NULL_HANDLE;
	static VkPhysicalDevice g_PhysicalDevice = VK_NULL_HANDLE;
	static uint32_t g_QueueFamily = (uint32_t)-1;
	static VkQueue g_Queue = VK_NULL_HANDLE;
	static VkDevice g_Device = VK_NULL_HANDLE;
	static VkDescriptorPool g_DescriptorPool = VK_NULL_HANDLE;

	void checkVkResult(VkResult err)
	{
		if (err == 0)
			return;

		fprintf(stderr, "[Vulkan] Error: VkResult = %d\n", err);
		if (err < 0)
			abort();
	}

#ifdef IMGUI_VULKAN_DEBUG_REPORT
	VKAPI_ATTR VkBool32 VKAPI_CALL debugReport(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData) {
		fprintf(stderr, "[Vulkan] Debug report from ObjectType: %i\nMessage: %s\n\n", objectType, pMessage);
		return VK_FALSE;
	}
#endif // IMGUI_VULKAN_DEBUG_REPORT

	void initializeVulkan(std::vector<const char*> extensions)
	{
		VkResult err;

		// Create a Vulkan instance
		{
			VkInstanceCreateInfo createInfo = {};
			createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			createInfo.enabledExtensionCount = (uint32_t)extensions.size();
			createInfo.ppEnabledExtensionNames = extensions.data();
#ifdef IMGUI_VULKAN_DEBUG_REPORT
			// Enabling validation layers
			std::vector<const char*> validationLayers = {
				"VK_LAYER_KHRONOS_validation"
			};

			createInfo.enabledLayerCount = (uint32_t)validationLayers.size();
			createInfo.ppEnabledLayerNames = validationLayers.data();
			extensions.emplace_back("VK_EXT_debug_report");
			createInfo.enabledExtensionCount = (uint32_t)extensions.size();
			createInfo.ppEnabledExtensionNames = extensions.data();

			// Create Vulkan Instance
			err = vkCreateInstance(&createInfo, g_Allocator, &g_Instance);
			checkVkResult(err);

			// Get the function pointer
			auto vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(g_Instance, "vkCreateDebugReportCallbackEXT");
			IM_ASSERT(vkCreateDebugReportCallbackEXT != nullptr);

			// Setup the debug report callback
			VkDebugReportCallbackCreateInfoEXT debugReportCI = {};
			debugReportCI.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
			debugReportCI.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
			debugReportCI.pfnCallback = debugReport;
			debugReportCI.pUserData = nullptr;
			err = vkCreateDebugReportCallbackEXT(g_Instance, &debugReportCI, g_Allocator, &g_DebugReport);
			checkVkResult(err);
#else
			err = vkCreateInstance(&createInfo, g_Allocator, &g_Instance);
			checkVkResult(err);
			IM_UNUSED(g_DebugReport);
#endif // IMGUI_VULKAN_DEBUG_REPORT
		}

		// Select GPU
		{
			uint32_t gpuCount;
			err = vkEnumeratePhysicalDevices(g_Instance, &gpuCount, nullptr);
			checkVkResult(err);
			IM_ASSERT(gpuCount > 0);

			std::vector<VkPhysicalDevice> gpus(gpuCount);
			err = vkEnumeratePhysicalDevices(g_Instance, &gpuCount, gpus.data());
			checkVkResult(err);

			// Look for dedicated GPU or use the firt one available
			int selectedGPU = 0;
			for (int i = 0; i < gpuCount; i++)
			{
				VkPhysicalDeviceProperties properties;
				vkGetPhysicalDeviceProperties(gpus[i], &properties);
				if (properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
				{
					selectedGPU = i;
					break;
				}
			}

			g_PhysicalDevice = gpus[selectedGPU];
		}

		// Select graphics queue family
		{
			uint32_t count;
			vkGetPhysicalDeviceQueueFamilyProperties(g_PhysicalDevice, &count, nullptr);
			std::vector<VkQueueFamilyProperties> queues(count);
			vkGetPhysicalDeviceQueueFamilyProperties(g_PhysicalDevice, &count, queues.data());
			for (int i = 0; i < count; i++)
			{
				if (queues[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
				{
					g_QueueFamily = i;
					break;
				}
			}

			IM_ASSERT(g_QueueFamily != (uint32_t)-1);
		}

		// Create logical device
		{
			int deviceExtensionCount = 1;
			std::vector<const char*> deviceExtensions = {
				"VK_KHR_swapchain"
			};

			std::vector<float> queuePriority = {
				1.0f
			};

			std::vector<VkDeviceQueueCreateInfo> queueInfo(1);
			queueInfo[0] = {};
			queueInfo[0].sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
			queueInfo[0].queueFamilyIndex = g_QueueFamily;
			queueInfo[0].queueCount = 1;
			queueInfo[0].pQueuePriorities = queuePriority.data();
			
			VkDeviceCreateInfo deviceCI = {};
			deviceCI.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
			deviceCI.queueCreateInfoCount = queueInfo.size();
			deviceCI.pQueueCreateInfos = queueInfo.data();
			deviceCI.enabledExtensionCount = deviceExtensionCount;
			deviceCI.ppEnabledExtensionNames = deviceExtensions.data();
			
			err = vkCreateDevice(g_PhysicalDevice, &deviceCI, g_Allocator, &g_Device);
			checkVkResult(err);
			vkGetDeviceQueue(g_Device, g_QueueFamily, 0, &g_Queue);
		}

		// Create Descriptor Pool
		{
			VkDescriptorPoolSize poolSizes[] =
			{
				{ VK_DESCRIPTOR_TYPE_SAMPLER, 1000 },
				{ VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1000 },
				{ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, 1000 },
				{ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, 1000 },
				{ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, 1000 },
				{ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, 1000 },
				{ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1000 },
				{ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1000 },
				{ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, 1000 },
				{ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, 1000 },
				{ VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, 1000 }
			};

			VkDescriptorPoolCreateInfo poolInfo = {};
			poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
			poolInfo.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
			poolInfo.maxSets = 1000 * IM_ARRAYSIZE(poolSizes);
			poolInfo.poolSizeCount = (uint32_t)IM_ARRAYSIZE(poolSizes);
			poolInfo.pPoolSizes = poolSizes;
			err = vkCreateDescriptorPool(g_Device, &poolInfo, g_Allocator, &g_DescriptorPool);
			checkVkResult(err);
		}
	}

	void shutdownVulkan()
	{
		// TODO: Implement shutdownVulkan()
	}

	void setupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height)
	{
		// TODO: Implement setupVulkanWindow(ImGui_ImplVulkanH* wd, VkSurfaceKHR surface, int width, int height)
	}

	void cleanupVulkanWindow()
	{
		// TODO: Implement cleanupVulkanWindow()
	}

	void frameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* drawData)
	{
		// TODO: Implement frameRender(ImGui_ImpleVulkanH_Window* wd, ImDrawData* drawData)
	}

	void framePresent(ImGui_ImplVulkanH_Window* wd)
	{
		// TODO: Implement framePresent(ImGui_ImplVulkanH_Window* wd)
	}
}