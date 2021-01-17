#pragma once
#include "BioEngine/API.h"

namespace bioengine {

	struct BE_API Vector2
	{
		// VALUES
		float x, y;

		// CONSTRUCTORS
		Vector2();
		Vector2(float x, float y);

		// OPERATOR OVERLOADS
		Vector2 operator+ (const Vector2& vector2);
		Vector2 operator- (const Vector2& vector2);
		void operator+= (const Vector2& vector2);
		void operator-= (const Vector2& vector2);
	};

}