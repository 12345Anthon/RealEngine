#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <fstream>

#include <Core/Core.h>

#include <string>

#include <Renderer/Renderer.h>

#include <Log/Log.h>
#include <Core/CoreApllication.h>

#include <GLFW/glfw3.h>

#include <glad/glad.h>

#include <Renderer/OpenGLContext.h>
#include <Renderer/Layers/Layers.h>
#include <Renderer/Layers/ImGuiLayer.h>
#include <Renderer/Layers/RendereringLayer.h>
#include <Renderer/Layers/ShaderLayer.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
//#include <imgui_impl_opengl3_loader.h>

#include <Renderer/Shaders/Shaders.h>
#include <Renderer/Shaders/ShaderObjects/VAO.h>
#include <Renderer/Shaders/ShaderObjects/VBO.h>
#include <Renderer/Shaders/ShaderObjects/EBO.h>

#if defined(_WIN64)
	
#include <Core/Windows/Windows.h>

#endif

#if defined(__APPLE__) && defined(__MACH__)
	
#include <Core/Mac/Mac.h>

#endif
