#include <iostream>
#include <BioEngine.h>

int main()
{
	std::cout << "Hello World" << std::endl;
	bioengine::Hello::SayHello();

	bioengine::Vector2 vec0;
	bioengine::Vector2 vec1 = bioengine::Vector2(7.0f, 5.3f);
	vec0 += vec1;

	std::cout << vec0.x << "," << vec0.y << std::endl;
	std::cout << vec1.x << "," << vec1.y << std::endl;
	std::cout << "\n" << std::endl;

	bioengine::Vector4 vec4_0;
	bioengine::Vector4 vec4_1 = bioengine::Vector4(1.0f, 1.0f, 0.0f, 1.0f);
	std::cout << vec4_0.r << "," << vec4_0.g << "," << vec4_0.b << "," << vec4_0.a << std::endl;
	std::cout << vec4_1.r << "," << vec4_1.g << "," << vec4_1.b << "," << vec4_1.a << std::endl;

	system("pause");
	return 0;
}