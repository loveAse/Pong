#include <BioEngine.h>
#include <iostream>

using namespace bioengine;

class PongGame : public Application, public EventSystem
{
public:
	PongGame()
	{
		m_Rectangle = new graphics::Rectangle(0.5f, 0.3f, 0.5f, 1.0f);
		m_Rectangle->SetColor(0.4f, 0.6f, 1.0f, 1.0f);

		SetEventListener(this);
	}
	~PongGame()
	{
		delete m_Rectangle;
	}

	void Render() override
	{
		m_Rectangle->Render();
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
	graphics::Rectangle* m_Rectangle;
};

int main()
{
	PongGame* game = new PongGame();
	game->Run();

	delete game;
	
	return 0;
}