#pragma once

#include "BioEngine/API.h"
#include <cstdint>
#include <vector>
#include "VertexTypes.h"

namespace bioengine { namespace graphics {

	class BE_API Buffer
	{
	public:
		Buffer();
		~Buffer();

		void Init(	const std::vector<Vertex2D>& vertices,
					const std::vector<uint32_t>& indices);

		void Activate();
		void Deactivate();

	private:
		uint32_t m_Vao;
		uint32_t m_Vbo;
		uint32_t m_Ibo;
	};

} }