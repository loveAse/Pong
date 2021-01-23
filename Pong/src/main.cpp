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
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glEnd();
	}
};

int main()
{
	PongGame* game = new PongGame();
	game->Run();

	delete game;
	
	return 0;
}