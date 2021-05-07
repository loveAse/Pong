#include "Ball.h"
#include <iostream>

Ball::Ball(Player* p1, Player* p2)
{
	m_Speed = 0.4f;
	player1 = p1;
	player2 = p2;

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

	if (CollisionTest())
	{

	}
}

bool Ball::CollisionTest()
{
	bioengine::Vector2 pos = GetPosition();
	bioengine::Vector2 p1Pos = player1->GetPosition();
	bioengine::Vector2 p2Pos = player2->GetPosition();

	// Player1
	if (abs(pos.x - p1Pos.x) < player1->GetDimension().x / 2.0f)
	{
		if (abs(pos.y - p1Pos.y) < player1->GetDimension().y / 2.0f)
		{
			std::cout << "Player 1 collision" << std::endl;
			return true;
		}
	}

	// Player2
	else if (abs(pos.x - p2Pos.x) < player1->GetDimension().x / 2.0f)
	{
		if (abs(pos.y - p2Pos.y) < player1->GetDimension().y / 2.0f)
		{
			std::cout << "Player 2 collision" << std::endl;
			return true;
		}
	}

	return false;
}
