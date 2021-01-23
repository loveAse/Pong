#pragma once

#include "BioEngine/API.h"
#include "BioEngine/graphics/Window.h"

namespace bioengine {

	class BE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void Render();

	private:
		graphics::Window* m_Window;
	};

}