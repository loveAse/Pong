#include "BioEngine/math/Vector2.h"

namespace bioengine {

	Vector2::Vector2()
	{
		x = y = 0.0f;
	}
	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 Vector2::operator+(const Vector2& vector2)
	{
		Vector2 temp;
		temp.x = this->x + vector2.x;
		temp.y = this->y + vector2.y;

		return temp;
	}
	Vector2 Vector2::operator-(const Vector2& vector2)
	{
		Vector2 temp;
		temp.x = this->x - vector2.x;
		temp.y = this->y - vector2.y;

		return temp;
	}

	void Vector2::operator+= (const Vector2& vector2)
	{
		this->x += vector2.x;
		this->y += vector2.y;
	}
	void Vector2::operator-= (const Vector2& vector2)
	{
		this->x -= vector2.x;
		this->y -= vector2.y;
	}

}