#pragma once

#include "BioEngine/API.h"

namespace bioengine {

	class BE_API Time
	{
	public:
		static double deltaTime;

	protected:
		static void UpdateTime();

	private:
		static double lastFrame;
		static double currentFrame;

	friend class Application;
	};

}