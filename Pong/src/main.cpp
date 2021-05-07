#include <BioEngine.h>
#include <iostream>
#include "Player.h"
#include "Ball.h"

using namespace bioengine;

class PongGame : public Application, public EventSystem
{
public:
	PongGame()
	{
		m_Player1 = new Player(0);
		m_Player2 = new Player(1);
		m_Ball = new Ball(m_Player1, m_Player2);
		m_Ball->SetDirection(150.0f);

		SetEventListener(this);
	}
	~PongGame()
	{
		delete m_Player1;
		delete m_Player2;
		delete m_Ball;
	}

	void Render() override
	{
		m_Player1->Update();
		m_Player2->Update();
		m_Ball->Update();

		m_Player1->Render();
		m_Player2->Render();
		m_Ball->Render();
	}

	void OnKeyDown(int keyCode) override
	{
		switch (keyCode)
		{
		case GLFW_KEY_UP:
			m_Player1->SetDirection(1);
			break;
		case GLFW_KEY_DOWN:
			m_Player1->SetDirection(-1);
			break;

		case GLFW_KEY_W:
			m_Player2->SetDirection(1);
			break;
		case GLFW_KEY_S:
			m_Player2->SetDirection(-1);
			break;
		}
	}
	void OnKeyUp(int keyCode) override
	{
		switch (keyCode)
		{
		case GLFW_KEY_UP:
			if (m_Player1->GetDirection() == 1)
				m_Player1->SetDirection(0);
			break;
		case GLFW_KEY_DOWN:
			if (m_Player1->GetDirection() == -1)
				m_Player1->SetDirection(0);
			break;

		case GLFW_KEY_W:
			if (m_Player2->GetDirection() == 1)
				m_Player2->SetDirection(0);
			break;
		case GLFW_KEY_S:
			if (m_Player2->GetDirection() == -1)
				m_Player2->SetDirection(0);
			break;
		}
	}

private:
	Player* m_Player1; 
	Player* m_Player2;
	Ball* m_Ball;
};

int main()
{
	PongGame* game = new PongGame();
	game->Run();

	delete game;
	
	return 0;
}