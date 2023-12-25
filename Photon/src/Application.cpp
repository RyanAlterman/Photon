#include "Application.h"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_vulkan.h>

#include <stdio.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Photon
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& spec)
	{
		s_Instance = this;

		Init();
	}

	Application::~Application()
	{
		Shutdown();

		s_Instance = nullptr;
	}

	Application& Application::Instance()
	{
		return *s_Instance;
	}

	void Application::Run()
	{
		// TODO: Implement Application::Run();
	}

	template <typename T>
	void Application::PushLayer()
	{
		static_assert(std::is_base_of<Layer, T>::value, "The pushed layer's type is not a child of the Layer class!");
		m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
	}

	void Application::PushLayer(const std::shared_ptr<Layer>& layer)
	{
		m_LayerStack.emplace_back(layer);
		layer->OnAttach();
	}

	void Application::Close()
	{
		// TODO: Implement Application::Close()
	}

	float Application::GetTime()
	{
		// TODO: Implement Application::GetTime()
		return 0.0f;
	}

	VkInstance Application::GetInstance()
	{
		// TODO: Implement Application::GetInstance();
		return nullptr;
	}

	VkPhysicalDevice Application::GetPhysicalDevice()
	{
		// TODO: Implement Application::GetPhysicalDevice()
		return nullptr;
	}

	VkDevice Application::GetDevice()
	{
		// TODO: Implement Application::GetDevice()
		return nullptr;
	}

	VkCommandBuffer Application::GetCommandBuffer(bool begin)
	{
		// TODO: Implement Application::GetCommandBuffer(bool begin)
		return nullptr;
	}

	void Application::FlushCommandBuffer(VkCommandBuffer commandBuffer)
	{
		// TODO: Implement Application::FlushCommandBuffer(VkCommandBuffer commandBuffer)
	}

	void Application::SubmitResourceFree(std::function<void()>&& func)
	{
		// TODO: Implement Application::SubmitResourceFree(std::function<void()>&& func)
	}

	void Application::Init()
	{
		// TODO: Implement Application::Init()
	}

	void Application::Shutdown()
	{
		// TODO: Implement Application::Shutdown()
	}
}
