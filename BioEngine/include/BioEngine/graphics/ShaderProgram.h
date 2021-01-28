#pragma once

#include "BioEngine/API.h"
#include <glad/glad.h>
#include <cstdint>

namespace bioengine { namespace graphics {

	class BE_API ShaderProgram
	{
	public:
		ShaderProgram();
		~ShaderProgram();

		void AttachShader(const char* fileName, uint32_t shaderType);
		void Link();
		void Use();

	private:
		uint32_t m_ProgramId;
	};

} }