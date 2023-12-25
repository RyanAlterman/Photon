#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "Editor/Layers/Layer.h"

#include <vulkan/vulkan.h>

// NOTE: Forward declaration of GLFW Window struct.
struct GLFWwindow;

namespace Photon
{
	struct ApplicationSpecification
	{
		std::string Name = "Not Set";
		uint32_t Width = 1280;
		uint32_t Height = 720;
	};

	/// <summary>
	/// A class that represent an instance of the running application.
	/// </summary>
	class Application
	{
	public:
		/// <summary>
		/// Constructs a new application with the provided application specification.
		/// </summary>
		/// <param name="spec">The specification used to create the application.</param>
		Application(const ApplicationSpecification& spec = ApplicationSpecification());

		/// <summary>
		/// Destroys the application instance.
		/// </summary>
		~Application();

		/// <summary>
		/// Retrieves the current instance of the Application class if one exists.
		/// </summary>
		/// <returns>Returns a reference to the current instance. If no instance exists, then
		/// the function returns a nullptr.</returns>
		static Application& Instance();

		/// <summary>
		/// Called to start running the application.
		/// </summary>
		void Run();

		/// <summary>
		/// Sets the callback function used to control the menubar for the application.
		/// </summary>
		/// <param name="menubarCallback">A function that has no parameters and doesn't return anything.</param>
		inline void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }

		// TODO: Add documentation comments to members of Application class
		template <typename T>
		void PushLayer();

		void PushLayer(const std::shared_ptr<Layer>& layer);

		void Close();

		float GetTime();

		GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }

		static VkInstance GetInstance();
		static VkPhysicalDevice GetPhysicalDevice();
		static VkDevice GetDevice();

		static VkCommandBuffer GetCommandBuffer(bool begin);
		static void FlushCommandBuffer(VkCommandBuffer commandBuffer);

		static void SubmitResourceFree(std::function<void()>&& func);

	protected:
	private:
		void Init();
		void Shutdown();

		ApplicationSpecification m_Spec;
		GLFWwindow* m_WindowHandle = nullptr;
		bool m_Running;

		float m_TimeStep;
		float m_FrameTime;
		float m_LastFrameTime;

		std::vector<std::shared_ptr<Layer>> m_LayerStack;
		std::function<void()> m_MenubarCallback;

		static Application* s_Instance;
	};
}
