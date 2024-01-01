#pragma once

#include <vulkan/vulkan.h>

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_vulkan.h>

#include <vector>

namespace Photon
{
#ifdef _DEBUG
#define IMGUI_VULKAN_DEBUG_REPORT
#endif

	/// <summary>
	/// Checks if the status code returned from a vulkan API call
	/// resulted in an error.
	/// </summary>
	/// <param name="err">The return code from a vulkan API call.</param>
	void checkVkResult(VkResult err);

#ifdef IMGUI_VULKAN_DEBUG_REPORT
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugReport(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData);
#endif

	/// <summary>
	/// Performs any necessary setup for using the Vulkan API.
	/// </summary>
	/// <param name="extensions">A list of vulkan extensions to enable.</param>
	static void initializeVulkan(std::vector<const char*> extensions);

	// TODO: Add comments to the functions below here
	static void shutdownVulkan();

	static void setupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height);

	static void cleanupVulkanWindow();

	static void frameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* drawData);

	static void framePresent(ImGui_ImplVulkanH_Window* wd);
}