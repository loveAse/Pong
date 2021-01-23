#pragma once

#include "BioEngine/API.h"

namespace bioengine {

	class BE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void Render();
	};

}