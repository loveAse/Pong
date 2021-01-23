#include <BioEngine.h>
#include <iostream>

class PongGame : public bioengine::Application
{
public:
	PongGame()
	{

	}
	~PongGame()
	{

	}

	void Render() override
	{
		std::cout << "Render" << std::endl;
	}
};

int main()
{
	PongGame* game = new PongGame();
	game->Run();

	delete game;
	
	return 0;
}