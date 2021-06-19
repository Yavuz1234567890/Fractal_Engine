#pragma once

#ifndef FR_PCH_H
#define FR_PCH_H

#include <set>
#include <map>
#include <array>
#include <tuple>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <stdio.h>
#include <memory>
#include <cassert>
#include <sstream>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>

#if defined(_WIN32)
#define FR_WINDOWS
#define FR_OS "Windows"
#elif defined(__linux__)
#define FR_LINUX
#define FR_OS "Linux"
#elif defined(__APPLE__)
#define FR_APPLE
#define FR_OS "OSX"
#else
#error Not Supported Platform!
#endif

#define VERSION "BETA 1.14"
#define EDITOR_VERSION "17.06.2021"
#define WINDOW_NAME "Game"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGH 720

#define BIND_FUNC(fn) std::bind(&fn, this, _1)
#define STRING(x) #x 

#define FR_NULL 0
#define FR_TRUE true
#define FR_FALSE false
#define TERMS 7

#define BIT(x) 1<<x

#if defined(FR_WINDOWS)
	#include <windows.h>
	#pragma comment(lib, "Engine/Source/Vendor/Lua535/liblua53.a")
#elif defined(FR_LINUX)
	#include <bits/stdc++.h>
#endif

#include "Vendor/Lua535/include/lua.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std::placeholders;

namespace fr {

	using FRuint = unsigned int;
	using FRuchar = unsigned char;
	using FRboolean = bool;
	using FRchar = char;
	using FRint = int;
	using FRfloat = float;
	using FRlong = long;
	using FRvoid = void;
	using FRsize = long unsigned int;
	using func = std::function<void()>;
	using FRfunc = func;
		
	struct CommandLineArgs { int argc; char** args; };
}

// other includes :

#include "Math/Math.h"
#include "Core/Errors/Errors.h"
#include "Events/EventSystem.h"

#include "Core/Resource/Resource.h"
#include "Core/ECS/ECS.h"
#include "Core/Engine.h"
#include "Core/Timer/Timer.h"

#include "Core/ECS/Base/BaseComponent.h"
#include "Core/ECS/Base/BaseSystem.h"
#include "Core/ECS/Base/EntityManager.h"
#include "Core/ECS/Components/CsScript.h"
#include "Core/ECS/Components/EntityName.h"
#include "Editor/UiLayer.h"

#include "Serializer/XMLSerializer.h"
#include "Serializer/ModelsAndTextures.h"

#include "Events/AppEvents.h"
#include "Events/Dispatcher.h"
#include "Events/Event.h"
#include "Events/GLFWImp.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Events/WindowEvents.h"
#include "Editor/UiLayer.h"
#include "Core/Inputs/KeyCodes.h"

#include "Renderer/ColorBuffer.h"
#include "Renderer/DepthBuffer.h"
#include "Renderer/GLMesh.h"
#include "Renderer/GLQuad.h"
#include "Renderer/Material.h"
#include "Renderer/Model.h"
#include "Renderer/SamplerBuffer.h"
#include "Renderer/Shader.h"
#include "Renderer/Vertex.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Grid.h"

#endif
