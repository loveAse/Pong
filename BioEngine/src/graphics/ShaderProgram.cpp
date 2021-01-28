#include "BioEngine/graphics/ShaderProgram.h"
#include "BioEngine/utils/FileUtils.h"
#include <iostream>

namespace bioengine { namespace graphics {

	ShaderProgram::ShaderProgram()
	{
		m_ProgramId = glCreateProgram();
	}
	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_ProgramId);
	}

	void ShaderProgram::AttachShader(const char* fileName, uint32_t shaderType)
	{
		uint32_t shaderId = glCreateShader(shaderType);
		
		std::string shaderSource = utils::FileUtils::LoadFile(fileName);
		const char* chShaderSource = &shaderSource[0];

		glShaderSource(shaderId, 1, &chShaderSource, NULL);
		
		glCompileShader(shaderId);
		
		// Compile error handling
		int isCompiled;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
		if (!isCompiled)
		{
			switch (shaderType)
			{
			case GL_VERTEX_SHADER:
				std::cout << "Failed to compile Vertex Shader" << std::endl;
				break;
			case GL_FRAGMENT_SHADER:
				std::cout << "Failed to compile Fragment Shader" << std::endl;
				break;
			}
			std::cout << "File: " << fileName << std::endl;

			char* log;
			int logSize;
			
			glGetShaderiv(m_ProgramId, GL_INFO_LOG_LENGTH, &logSize);

			log = (char*)malloc(logSize);

			glGetShaderInfoLog(m_ProgramId, logSize, &logSize, log);

			std::cout << log << "\n\n";

			free(log);

			throw "Shader Compile Error!";
			return;
		}

		glAttachShader(m_ProgramId, shaderId);
		glDeleteShader(shaderId);
	}

	void ShaderProgram::Link()
	{
		glLinkProgram(m_ProgramId);

		int isLinked;
		glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &isLinked);
		if (!isLinked)
		{
			std::cout << "Shader Program Linking Error!" << std::endl;

			int logLength;
			char* log;

			glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &logLength);

			log = (char*)malloc(logLength);

			glGetProgramInfoLog(m_ProgramId, logLength, &logLength, log);

			std::cout << log << "\n\n";

			free(log);

			throw "Program Linking Error";
		}
	}

	void ShaderProgram::Use()
	{
		glUseProgram(m_ProgramId);
	}

} }