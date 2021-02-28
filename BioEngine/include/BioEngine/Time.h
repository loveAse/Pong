#pragma once

#include "BioEngine/API.h"

namespace bioengine {

	class BE_API Time
	{
	public:
		static inline double GetDeltaTime() { return currentFrame - lastFrame; }

	protected:
		static void Update();

	private:
		static double lastFrame;
		static double currentFrame;

	friend class Application;
	};

}