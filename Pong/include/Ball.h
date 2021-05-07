#pragma once

#include <BioEngine.h>

class Ball : public bioengine::graphics::Rectangle
{
public:
	Ball();

	void Update();

	inline float GetDirection() { return m_Angle; }
	void SetDirection(float direction) { m_Angle = direction; }

private:
	float m_Speed;
	float m_Angle;
};
