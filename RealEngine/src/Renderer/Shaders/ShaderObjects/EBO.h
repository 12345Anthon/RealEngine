#pragma once

#include <realpch.h>

namespace EBO
{

	class EBO
	{
	public:

		EBO();

		// ID reference of Elements Buffer Object
		GLuint ID;
		// Constructor that generates a Elements Buffer Object and links it to indices
		EBO(GLuint* indices, GLsizeiptr size);

		// Binds the EBO
		void Bind();
		// Unbinds the EBO
		void Unbind();
		// Deletes the EBO
		void Delete();
	};


}