#pragma once

#include <iostream>

#include <Renderer/Shaders/ShaderObjects/VAO.h>
#include <Renderer/Shaders/ShaderObjects/VBO.h>
#include <Renderer/Shaders/ShaderObjects/EBO.h>

namespace Renderer
{

	class Renderer
	{

	public:

		Renderer(VBO::VBO VBO, EBO::EBO EBO, VAO::VAO VAO);
		virtual ~Renderer();

	};

}
