#include "Ball.h"

Ball::Ball()
{
	m_Speed = 0.4f;

	SetPosition(0.0f, 0.0f);
	SetDimension(0.07f, 0.07f);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	Init();
}

void Ball::Update()
{
	bioengine::Vector2 newPos = GetPosition();
	newPos.x += cos((m_Angle * PI) / 180.0f) * m_Speed * (float)bioengine::Time::deltaTime;
	newPos.y += sin((m_Angle * PI) / 180.0f) * m_Speed * (float)bioengine::Time::deltaTime;
	SetPosition(newPos);
}
