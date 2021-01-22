#include <iostream>
#include <BioEngine.h>

void printMatrix(bioengine::Matrix3 mat)
{
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << mat[0 + i * 3] << ", ";
		std::cout << mat[1 + i * 3] << ", ";
		std::cout << mat[2 + i * 3] << std::endl;
	}
	std::cout << "\n" << std::endl;
}

int main()
{
	bioengine::Matrix3 mat;
	printMatrix(mat);

	bioengine::Matrix3 identity = bioengine::Matrix3::Identity();
	printMatrix(identity);

	bioengine::Matrix3 translate = bioengine::Matrix3::Translate(bioengine::Vector2(2, 5));
	printMatrix(translate);

	identity *= translate;
	printMatrix(identity);

	identity *= mat;
	printMatrix(identity);

	system("pause");
	return 0;
}