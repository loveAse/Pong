#pragma once

#include "BioEngine/API.h"
#include "BioEngine/math/Vector2.h"
#include "BioEngine/math/Vector4.h"
#include "ShaderProgram.h"
#include "Buffer.h"
#include <vector>

namespace bioengine { namespace graphics {

	class BE_API Rectangle
	{
	public:
		Rectangle();
		Rectangle(float x, float y, float w, float h);
		Rectangle(const Vector2& position, const Vector2& dimension);
		~Rectangle();

		void Render();

		// Getter
		inline Vector2 GetPosition() { return m_Position; }
		inline Vector2 GetDimension() { return m_Dimension; }
		inline Vector4 GetColor() { return m_Color; }

		// Setter
		void SetPosition(float x, float y);
		void SetPosition(const Vector2 position);
		void SetDimension(float x, float y);
		void SetDimension(const Vector2 dimension);
		void SetColor(float r, float g, float b, float a);
		void SetColor(const Vector4& color);

	private:
		void Init();

	private:
		Vector2 m_Position;
		Vector2 m_Dimension;

		Vector4 m_Color;

		Buffer* m_Buffer;
		ShaderProgram* m_Program;

		std::vector<Vertex2D> m_Vertices;
		std::vector<uint32_t> m_Indices;
	};

} }