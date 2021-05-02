#include "BioEngine/application/Window.h"

namespace bioengine {

	Window::Window(const char* title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;

		if (!Init())
			glfwTerminate();
	}
	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			throw "Failed to Initialize GLFW!";
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			throw "Failed to Create Window";
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw "Failed to Load GL";
			return false;
		}
	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::IsOpen()
	{
		return glfwWindowShouldClose(m_Window) == 0;
	}

}