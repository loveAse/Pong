#include <iostream>
#include <Hello.h>

int main()
{
	std::cout << "Hello World" << std::endl;
	bioengine::Hello::SayHello();

	system("pause");
	return 0;
}