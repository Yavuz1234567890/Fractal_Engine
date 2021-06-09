#pragma once

#ifndef FR_ENGINE
#define FR_ENGINE

#include "Objects/DepthBuffer.h"
#include "Objects/SamplerBuffer.h"

namespace fr {
	const int SHADOW_WIDTH = 1024;
	const int SHADOW_HEIGHT = 1024;

	class Engine {

	public:
		~Engine();
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		static Engine& Ref() {
			static Engine reference;
			return reference;
		}

		void OnQuit(const Event& e) {
			isRuning = false;
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		void OnViewportResized(const Event& e) {
			auto event = Dispatcher.Cast<ViewportResizedEvent>(e);
			viewSize.x = event.Width();
			viewSize.y = event.Height();
			outputBuffer->SetSize(viewSize.x, viewSize.y);
			glViewport(0, 0, viewSize.x, viewSize.y);

			std::cout << "viewport resised! " << viewSize.x << "\n";
		}

		void SetViewport(glm::vec2 size) {
			viewSize = size;
			outputBuffer->SetSize(size.x, size.y);
			glViewport(0, 0, size.x, size.y);
		}

		void LockCursor() {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}

		void Update();
		void Render();
		void StopGame();
		void StartGame();
		void Initialize();
		void SetCommandLineArgs(CommandLineArgs args) { commandLineArguments = args; }

		inline glm::vec2 ViewSize() const { return viewSize; }
		inline DepthBuffer* ShadowBuffer() const { return shadowBuffer; }
		inline SamplerBuffer* GetSceneBufferID() const { return outputBuffer; }

		inline GLFWwindow* Window() { return window; }
		inline const bool Run() const { return isRuning; }

	private:
		Engine();

	private:
		bool isRuning;
		bool isGameRunnig;
		CommandLineArgs commandLineArguments;
		GLFWwindow* window;

		glm::ivec2 viewSize;
		DepthBuffer* shadowBuffer;
		SamplerBuffer* outputBuffer;
	};

	static Engine& Core = Engine::Ref();
}

#endif
