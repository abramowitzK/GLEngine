#pragma once
#define GLEW_STATIC
#include <SDL.h>
#include <GL\glew.h>
#include <iostream>
#include "Window.h"
#include "Time.h"
#include "Input.h"
#include "RenderUtil.h"
#include "Interfaces.h"
#include "Math3D.h"
#include "GameObject.h"
#include "MeshRenderer.h"
#include "Camera3D.h"
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
	/**
	Do all the things we need to do before the start of each frame
	*/
	void BeginFrame();
	/**
	Do all the things we need to do to end the current frame
	-Swap buffers
	-Manage our static time variable and keyboard state
	-Possibly more?
	*/
	void EndFrame();
private:
	GameObject* m_root;
	Camera3D* m_cam;
	MeshRenderer* m_mesh;
	int m_height;
	int m_width;
	const char* m_title;
	bool m_isRunning = false;
};