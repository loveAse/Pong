#pragma once

#include "BioEngine/API.h"
#include "BioEngine/math/Vector2.h"

namespace bioengine { namespace graphics {

	struct BE_API Vertex2D
	{
		Vertex2D(float x, float y);

		Vector2 position;
	};

} }