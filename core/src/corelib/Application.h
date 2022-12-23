#pragma once

#include "Layer.h"

#include "imgui.h"
#include "vulkan/vulkan.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

void check_vk_result(VkResult err);
struct GLFWwindow;

namespace ABC_Name {
	struct AppSpecs {
		std::string Name = "ABC_project";
		uint32_t Width = 1600;
		uint32_t Height = 900;
	};

	class Application {
	public:
		Application(const AppSpecs& specs = AppSpecs());
		~Application();

	public:
		void Run();
		void SetMenubarCallback(const std::function<void()>& menubarCallback) {
			m_menubarCallback = menubarCallback;
		}

		template<typename T>
		void PushLayer() {
			static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!!");
			m_layerStack.emplace_back(std::make_shared<T>())->OnAttach();
		}

		void PushLayer(const std::shared_ptr<Layer>& layer) {
			m_layerStack.emplace_back(layer);
			layer->OnAttach();
		}

		void Close();

#if defined(ABC_WINDOWS) || defined(ABC_LINUX)
		static VkInstance GetInstance();
		static VkPhysicalDevice GetPhysicalDevice();
		static VkDevice GetDevice();

		static VkCommandBuffer GetCommandBuffer(bool begin);
		static void FlushCommandBuffer(VkCommandBuffer commandBuffer);
#elif defined(ABC_MACOS)
#endif

	private:
		void Init();
		void Shutdown();

	private:
		AppSpecs appSpecs;
		GLFWwindow* m_windowHandle = nullptr;
		bool running = false;

		std::vector<std::shared_ptr<Layer>> m_layerStack;
		std::function<void()> m_menubarCallback;
	};

	Application* CreateApplication(int argc, char** argv);
}
