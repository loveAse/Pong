#include "BioEngine/graphics/Rectangle.h"

namespace bioengine { namespace graphics {

	Rectangle::Rectangle()
	{
		m_Position = Vector2();
		m_Dimension = Vector2(0.1f, 0.1f);
		Init();
	}
	Rectangle::Rectangle(float x, float y, float w, float h)
	{
		m_Position = Vector2(x, y);
		m_Dimension = Vector2(w, h);
		Init();
	}
	Rectangle::Rectangle(const Vector2& position, const Vector2& dimension)
	{
		m_Position = position;
		m_Dimension = dimension;
		Init();
	}

	Rectangle::~Rectangle()
	{
		delete m_Buffer;
		delete m_Program;
	}

	void Rectangle::Render()
	{
		m_Program->Use();
		m_Buffer->Activate();

		glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, (const void*)0);
	}

	void Rectangle::SetPosition(float x, float y)
	{
		m_Position = Vector2(x, y);
		m_Program->SetUniformVec2("uPosition", m_Position);
	}

	void Rectangle::SetPosition(const Vector2 position)
	{
		m_Position = position;
		m_Program->SetUniformVec2("uPosition", m_Position);
	}

	void Rectangle::SetDimension(float x, float y)
	{
		m_Dimension = Vector2(x, y);
	}

	void Rectangle::SetDimension(const Vector2 dimension)
	{
		m_Dimension = dimension;
	}

	void Rectangle::SetColor(float r, float g, float b, float a)
	{
		m_Color = Vector4(r, g, b, a);
		m_Program->SetUniformVec4("uColor", m_Color);
	}

	void Rectangle::SetColor(const Vector4& color)
	{
		m_Color = color;
		m_Program->SetUniformVec4("uColor", m_Color);
	}

	void Rectangle::Init()
	{
		m_Program = new ShaderProgram();
		m_Program->AttachShader("Resources/basic.vert", GL_VERTEX_SHADER);
		m_Program->AttachShader("Resources/basic.frag", GL_FRAGMENT_SHADER);
		m_Program->Link();
		m_Program->Use();

		m_Program->AddUniform("uPosition");
		m_Program->AddUniform("uColor");
		m_Program->SetUniformVec2("uPosition", m_Position);
		m_Program->SetUniformVec4("uColor", m_Color);

		m_Vertices = {
			Vertex2D(-m_Dimension.x / 2.0f, -m_Dimension.y / 2.0f),
			Vertex2D( m_Dimension.x / 2.0f, -m_Dimension.y / 2.0f),
			Vertex2D( m_Dimension.x / 2.0f,  m_Dimension.y / 2.0f),
			Vertex2D(-m_Dimension.x / 2.0f,  m_Dimension.y / 2.0f)
		};
		m_Indices = { 0, 1, 2, 0, 2, 3 };

		m_Buffer = new Buffer();
		m_Buffer->Init(m_Vertices, m_Indices);
	}

} }