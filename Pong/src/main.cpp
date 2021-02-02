#include <BioEngine.h>
#include <iostream>

using namespace bioengine;

class PongGame : public Application
{
public:
	PongGame()
	{
		m_Rectangle = new graphics::Rectangle(0.5f, 0.3f, 0.5f, 1.0f);
		m_Rectangle->SetColor(0.4f, 0.6f, 1.0f, 1.0f);
	}
	~PongGame()
	{
		delete m_Rectangle;
	}

	void Render() override
	{
		m_Rectangle->Render();
	}

private:
	graphics::Rectangle* m_Rectangle;
};

int main()
{
	PongGame* game = new PongGame();
	game->Run();

	delete game;
	
	return 0;
}