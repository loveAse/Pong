#include "BioEngine/application/EventSystem.h"

namespace bioengine {

	void EventSystem::SetEventListener(Application* app)
	{
		GLFWevents::eventSystem = this;
		glfwSetKeyCallback(app->GetGLFWwindow(), GLFWevents::key_callback);
	}

	void EventSystem::OnKeyDown(int keyCode) { }
	void EventSystem::OnKeyUp(int keyCode) { }

	EventSystem* EventSystem::GLFWevents::eventSystem = nullptr;
	void EventSystem::GLFWevents::key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods)
	{
		if (action == GLFW_PRESS)
			eventSystem->OnKeyDown(key);
		else if (action == GLFW_RELEASE)
			eventSystem->OnKeyUp(key);
	}

}