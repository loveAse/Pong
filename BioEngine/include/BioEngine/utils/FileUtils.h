#pragma once

#include "BioEngine/API.h"
#include <string>

namespace bioengine { namespace utils {

	class BE_API FileUtils
	{
	public:
		static std::string LoadFile(const char* fileName);
	};

} }