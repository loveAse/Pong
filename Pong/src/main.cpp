#include <BioEngine.h>
#include <iostream>
#include "Player.h"

using namespace bioengine;

class PongGame : public Application, public EventSystem
{
public:
	PongGame()
	{
		m_Player1 = new Player(0);
		m_Player2 = new Player(1);

		SetEventListener(this);
	}
	~PongGame()
	{
		delete m_Player1;
		delete m_Player2;
	}

	void Render() override
	{
		m_Player1->Update();
		m_Player2->Update();

		m_Player1->Render();
		m_Player2->Render();

		std::cout << "DT: " << Time::GetDeltaTime() << std::endl;
	}

	void OnKeyDown(int keyCode) override
	{
		std::cout << "Key Down: " << keyCode << std::endl;
	}
	void OnKeyUp(int keyCode) override
	{
		std::cout << "Key Up: " << keyCode << std::endl;
	}

private:
	Player* m_Player1; 
	Player* m_Player2;
};

int main()
{
	PongGame* game = new PongGame();
	game->Run();

	delete game;
	
	return 0;
}