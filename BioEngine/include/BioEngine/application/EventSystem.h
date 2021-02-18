#pragma once

#include "BioEngine/API.h"
#include "Application.h"

namespace bioengine {

	class BE_API EventSystem
	{
	public:
		void SetEventListener(Application* app);

		virtual void OnKeyDown(int keyCode);
		virtual void OnKeyUp(int keyCode);

	private:
		class GLFWevents
		{
		public:
			static EventSystem* eventSystem;
			static void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods);
		};
	};

}