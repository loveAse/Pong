#pragma once

#include "BioEngine/API.h"
#include "Window.h"

namespace bioengine {

	class BE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void Render();

	private:
		Window* m_Window;

	protected:
		inline GLFWwindow* GetGLFWwindow() { return m_Window->GetGLFWwindow(); }

	friend class EventSystem;
	};

}