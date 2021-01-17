#include <iostream>
#include <Hello.h>
#include <math/Vector2.h>

int main()
{
	std::cout << "Hello World" << std::endl;
	bioengine::Hello::SayHello();

	bioengine::Vector2 vec0;
	bioengine::Vector2 vec1 = bioengine::Vector2(7.0f, 5.3f);
	vec0 += vec1;

	std::cout << vec0.x << "," << vec0.y << std::endl;
	std::cout << vec1.x << "," << vec1.y << std::endl;

	system("pause");
	return 0;
}