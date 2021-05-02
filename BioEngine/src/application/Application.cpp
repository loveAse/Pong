#include "BioEngine/application/Application.h"

namespace bioengine {

	Application::Application() 
	{ 
		m_Window = new Window("BioEngine App", 650, 650);
	}
	Application::~Application() 
	{ 
		delete m_Window;
	}
	void Application::Render() { }
	void Application::Run()
	{
		while (m_Window->IsOpen())
		{
			Time::UpdateTime();

			m_Window->Clear();
			Render();
			m_Window->Update();
		}
	}

}