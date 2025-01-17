#include "Shaders.h"

namespace Shaders
{

	Log log;

	std::string ReadFile(const std::string& filePath) {
		std::ifstream file(filePath);
		if (!file) {
			std::cerr << "Failed to open file: " << filePath << std::endl;
			return "";
		}

		std::stringstream buffer;
		buffer << file.rdbuf();  // Read the whole file into buffer
		return buffer.str();
	}

	// Constructor that build the Shader Program from 2 different shaders
	Shaders::Shaders(const char* vertexFile, const char* fragmentFile)
	{
		// Read vertexFile and fragmentFile and store the strings
		std::string vertexCode = ReadFile("./GLSL/vertextShader.vert");
		std::string fragmentCode = ReadFile("./GLSL/fragmentShader.frag");

		// Convert the shader source strings into character arrays
		const char* vertexSource = vertexCode.c_str();
		const char* fragmentSource = fragmentCode.c_str();

		// Create Vertex Shader Object and get its reference
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		// Attach Vertex Shader source to the Vertex Shader Object
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		// Compile the Vertex Shader into machine code
		Shaders::compileShaders(vertexShader);

		// Create Fragment Shader Object and get its reference
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// Attach Fragment Shader source to the Fragment Shader Object
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		// Compile the Vertex Shader into machine code
		Shaders::compileShaders(fragmentShader);

		// Create Shader Program Object and get its reference
		ID = glCreateProgram();
		// Attach the Vertex and Fragment Shaders to the Shader Program
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		// Wrap-up/Link all the shaders together into the Shader Program
		glLinkProgram(ID);

		// Delete the now useless Vertex and Fragment Shader objects
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}

	Shaders::~Shaders()
	{
		log.info("Shaders destroied...");
	}

	void Shaders::Activate()
	{
		glUseProgram(ID);
	}


	void Shaders::Delete()
	{
		// Delete the now useless Vertex and Fragment Shader objects
		glDeleteProgram(ID);
	}

}