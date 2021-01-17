#pragma once

#include "BioEngine/API.h"

namespace bioengine {

	struct BE_API Vector4
	{
		float r, g, b, a;

		Vector4();
		Vector4(float r, float g, float b, float a);
	};

}