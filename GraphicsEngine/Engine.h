#pragma once
#include <SDL.h>
#include <GL\glew.h>
#include <Bullet\btBulletDynamicsCommon.h>
#include <iostream>
#include "Window.h"
#include "Time.h"
#include "Input.h"
#include "SceneManager.h"

class Engine
{
public:
	Engine(int width, int height, char* title);
	~Engine();
	void Start();
	void Stop();
	void Run();
	RenderingEngine* GetRenderingEngine();
private:
	int m_height;
	int m_width;
	const char* m_title;
	bool m_isRunning = false;
	btDiscreteDynamicsWorld* m_physicsWorld;
	SceneManager* m_sceneManager;
	RenderingEngine* m_rendering;
	const double FPS = 60.0;
};