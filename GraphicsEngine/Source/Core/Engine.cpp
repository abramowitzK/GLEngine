#include "../../Include/Core/Engine.h"
#include <math.h>
Engine::Engine(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
	Window::Create(m_width, m_height, m_title);
	GLint res = glewInit();
	if (GLEW_OK != res)
	{
		std::cerr << "Error initializing glew" << std::endl;
		SDL_Quit();
		exit(1);
	}
	m_managers.push_back(ScriptingManager::instance);
}

Engine::~Engine()
{
}

void Engine::Start()
{
	RenderUtil::InitGraphics();
	m_isRunning = true;
	Run();
}

void Engine::Stop()
{
	m_isRunning = false;
}

void Engine::Run()
{
	//Need to start main loop
	double t = 0.0;
	const double dt = 0.01;
	double currentTime = Time::GetTime();
	double accumulator = 0.0;
#ifdef _DEBUG
	double frameCounter = 0;
	int frames = 0;
#endif
	while (m_isRunning)
	{
		double newTime = Time::GetTime();
		double frameTime = newTime - currentTime;
		if (frameTime > 0.25)
			frameTime = 0.25;
		currentTime = newTime;
		accumulator += frameTime;
#ifdef _DEBUG
		frameCounter += frameTime;
		if (frameCounter >= 1.0)
		{
			std::cout << frameTime << std::endl;
			frames = 0;
			frameCounter = 0.0;
		}
#endif
		while (accumulator >= dt)
		{
			//Close window if necessary
			if (Window::IsCloseRequested())
				Stop();		
			//Process input
			Input::Update();
			//Step physics simulation here when i get around to it...
			t += dt;
			accumulator -= dt;
		}
		//All rendering done. Flip buffers
		Window::SwapBuffers();
#ifdef _DEBUG
		frames++;
#endif
	}
}

void Engine::Update()
{
}
