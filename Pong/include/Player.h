#pragma once

#include <BioEngine.h>

class Player : public bioengine::graphics::Rectangle
{
public:
	Player(bool index);

	void Update();

	inline int GetDirection() { return m_Direction; }
	void SetDirection(int direction) { m_Direction = direction; }
	
private:
	float m_Speed;
	int m_Direction;
	bool m_Index;
};