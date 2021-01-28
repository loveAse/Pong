#include "BioEngine/utils/FileUtils.h"
#include <fstream>

namespace bioengine { namespace utils {

	std::string FileUtils::LoadFile(const char* fileName)
	{
		std::string data;
		char readedChar;

		std::ifstream stream(fileName);

		if (stream.is_open())
		{
			while ((readedChar = stream.get()) != EOF)
			{
				data += readedChar;
			}
		}

		stream.close();

		return data;
	}

} }