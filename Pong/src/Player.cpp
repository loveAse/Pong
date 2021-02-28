#include "Player.h"

Player::Player(bool index)
{
	m_Index = index;
	m_Speed = 0.05f;
	m_Direction = 0;

	SetPosition(m_Index ? -0.85f : 0.85f, 0.0f);
	SetDimension(0.07f, 0.4f);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	Init();
}

void Player::Update()
{
	bioengine::Vector2 newPosition = GetPosition();
	newPosition.y += m_Speed * m_Direction;
}