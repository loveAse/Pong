#include "BioEngine/Time.h"
#include <GLFW/glfw3.h>

namespace bioengine {

	double Time::deltaTime = 0.0;
	double Time::currentFrame = 0.0;
	double Time::lastFrame = 0.0;

	void Time::UpdateTime()
	{
		lastFrame = currentFrame;
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
	}

}