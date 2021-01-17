#include "BioEngine/math/Vector4.h"

namespace bioengine {

	Vector4::Vector4()
	{
		r = g = b = a = 0.0f;
	}
	Vector4::Vector4(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

}