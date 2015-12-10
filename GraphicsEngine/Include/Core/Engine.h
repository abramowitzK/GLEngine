#pragma once
#define GLEW_STATIC
#include <SDL.h>
#include <GL\glew.h>
#include <iostream>
#include "Window.h"
#include "../Util/Time.h"
#include "Input.h"
#include "../Util/RenderUtil.h"
#include "../Interfaces.h"
#include "../../Include/Scripting/ScriptingManager.h"
#include "../../Include/Rendering/GLRenderer.h"
#include "Application.h"
#include <vector>

class Engine
{
public:
	Engine(int width, int height, const char* title);
	~Engine();
	void Start();
	void Stop();
	void Run();
	void Update();
private:
	int m_height;
	int m_width;
	const char* m_title;
	bool m_isRunning = false;
	GLRenderer* m_renderer;
	Application* m_application;
};