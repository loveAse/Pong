#pragma once

#include <BioEngine.h>
#include "Player.h"

class Ball : public bioengine::graphics::Rectangle
{
public:
	Ball(Player* p1, Player* p2);

	void Update();

	inline float GetDirection() { return m_Angle; }
	void SetDirection(float direction) { m_Angle = direction; }

	bool CollisionTest();

private:
	float m_Speed;
	float m_Angle;
	Player* player1;
	Player* player2;
};
