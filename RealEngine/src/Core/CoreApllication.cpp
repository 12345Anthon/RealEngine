#include "CoreApllication.h"

namespace Core
{

	Shaders::Shaders shaderProgram("./Renderer/Shaders/GLSL/vertextShader.vert", "./Renderer/Shaders/GLSL/fragmentShader.frag");

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	int CoreApplication::run()
	{

		float col[3] = { 2, 4, 7 };

		Log::Log log;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifndef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		log.info("Initializing GLFW...");

		GLFWwindow* window = glfwCreateWindow(1200, 900, "RealEngine", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}

		log.info("Initializing GLAD...");

		log.info("Initializing ImGui...");

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

		// Our state
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window, true);

		ImGui_ImplOpenGL3_Init();

		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		glClearColor(17.6f, 3.5f, 0.17f, 0.5f);

		while (!glfwWindowShouldClose(window))
		{

			glfwPollEvents();
			if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
			{
				ImGui_ImplGlfw_Sleep(10);
				continue;
			}

			// Start the Dear ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
			if (show_demo_window)
				ImGui::ShowDemoWindow(&show_demo_window);
			{
				static float f = 0.0f;
				static int counter = 0;

				ImGui::Begin("jjg");

				ImGui::MenuItem("Block");

				{

					ImGui::ColorPicker3("Color", col, NULL);

				}

				ImGui::End();
			}

			// Rendering
			ImGui::Render();
			int display_w, display_h;
			glfwGetFramebufferSize(window, &display_w, &display_h);
			glViewport(0, 0, display_w, display_h);
			//glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
			glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			// Tell OpenGL which Shader Program we want to use
			shaderProgram.Activate();
			// Bind the VAO so OpenGL knows to use it
			VAO::VAO VAO;
			VAO.Bind();
			// Draw primitives, number of indices, datatype of indices, index of indices
			glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(window);

		}

		// Cleanup

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		// Delete all the objects we've created
		VAO::VAO VAO;
		VAO.Delete();
		VBO::VBO VBO;
		VBO.Delete();
		EBO::EBO EBO;
		EBO.Delete();
		shaderProgram.Delete();

		glfwDestroyWindow(window);
		glfwTerminate();

	}

	CoreApplication::CoreApplication()
	{

		
		

		
	}

	CoreApplication::~CoreApplication()
	{
		return;
	}

}