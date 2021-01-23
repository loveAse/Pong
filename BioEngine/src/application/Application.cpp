#include "BioEngine/application/Application.h"

namespace bioengine {

	Application::Application() { }
	Application::~Application() { }
	void Application::Render() { }
	void Application::Run()
	{
		while (true)
		{
			Render();
		}
	}

}