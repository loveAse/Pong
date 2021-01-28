#pragma once

#include "BioEngine/API.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace bioengine { namespace graphics {

	class BE_API Window
	{
	public:
		Window(const char* title, int width, int height);
		~Window();

		void Clear();
		void Update();

		inline bool IsOpen();

	private:
		const char* m_Title;
		int m_Width;
		int m_Height;

		GLFWwindow* m_Window;

	private:
		bool Init();
	};

} }