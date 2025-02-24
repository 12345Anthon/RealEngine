#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cerrno>
#include <Log/Log.h>

namespace Shaders
{

	std::string ReadFile(const std::string& filePath);

	class Shaders
	{
	public:

		GLuint ID;

		Log::Log log;

		Shaders(const char* vertexFile, const char* fragmentFile);

		virtual ~Shaders();

		void Activate();
		void Delete();

		void compileShaders(GLuint shader) {

			log.info("Compiling Shaders...");
			glCompileShader(shader);

		}	

	private:

	};

}

#endif