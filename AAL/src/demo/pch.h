#pragma once

#ifdef _DEBUG
	#pragma comment(lib, "../Core/Build/Debug/Core.lib")
	#pragma comment(lib, "../Render/Build/Debug/Render.lib")
	#pragma comment(lib, "../Engine/Build/Debug/Engine.lib")
#else
	#pragma comment(lib, "../Core/Build/Release/Core.lib")
	#pragma comment(lib, "../Render/Build/Release/Render.lib")
	#pragma comment(lib, "../Engine/Build/Release/Engine.lib")
#endif

#include <SDKDDKVer.h>
#include "../Engine/engine.h"

class Ship;

#include "App.h"
