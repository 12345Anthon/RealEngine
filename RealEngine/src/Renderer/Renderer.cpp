#include "Renderer.h"

namespace Renderer
{

	Renderer::Renderer(VBO::VBO VBO, EBO::EBO EBO, VAO::VAO VAO)
	{
		std::cout << "Renderer Constructed" << std::endl;
	}

	Renderer::~Renderer()
	{
		std::cout << "Renderer Destructed" << std::endl;
	}

}