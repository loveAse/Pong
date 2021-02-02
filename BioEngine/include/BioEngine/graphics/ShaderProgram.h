#pragma once

#include "BioEngine/API.h"
#include <glad/glad.h>
#include <cstdint>
#include <map>
#include <string>
#include "BioEngine/math/Vector2.h"
#include "BioEngine/math/Vector4.h"

namespace bioengine { namespace graphics {

	class BE_API ShaderProgram
	{
	public:
		ShaderProgram();
		~ShaderProgram();

		void AttachShader(const char* fileName, uint32_t shaderType);
		void Link();
		void Use();

		// Uniforms
		void AddUniform(const std::string& varName);
		void SetUniformVec2(const std::string& varName, const Vector2& value);
		void SetUniformVec4(const std::string& varName, const Vector4& value);

	private:
		uint32_t m_ProgramId;

		std::map<std::string, uint32_t> m_Uniforms;
	};

} }