#include "BioEngine/graphics/Buffer.h"
#include <glad/glad.h>

namespace bioengine { namespace graphics {

	Buffer::Buffer()
	{
		m_Vao = m_Vbo = m_Ibo = 0;
	}
	Buffer::~Buffer()
	{
		glDeleteVertexArrays(1, &m_Vao);
		glDeleteBuffers(1, &m_Vbo);
		glDeleteBuffers(1, &m_Ibo);

		m_Vao = m_Vbo = m_Ibo = 0;
	}

	void Buffer::Init(	const std::vector<Vertex2D>& vertices,
						const std::vector<uint32_t>& indices)
	{
		// Vertex Buffer
		glGenBuffers(1, &m_Vbo);
		glGenVertexArrays(1, &m_Vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
		glBindVertexArray(m_Vao);

		glBufferData(	GL_ARRAY_BUFFER, 
						sizeof(Vertex2D) * vertices.size(),
						&vertices[0],
						GL_STATIC_DRAW);
		glVertexAttribPointer(	0,
								2,
								GL_FLOAT,
								GL_FALSE,
								sizeof(Vertex2D),
								(const void*)0);

		glEnableVertexAttribArray(0);

		// Index Buffer
		glGenBuffers(1, &m_Ibo);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);

		glBufferData(	GL_ELEMENT_ARRAY_BUFFER,
						sizeof(uint32_t) * indices.size(),
						&indices[0],
						GL_STATIC_DRAW);
	}

	void Buffer::Activate()
	{
		glBindVertexArray(m_Vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
	}
	void Buffer::Deactivate()
	{
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

} }