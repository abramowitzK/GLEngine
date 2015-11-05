#include "Engine.h"
#include <math.h>
Engine::Engine(int width, int height, char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

Engine::~Engine()
{
}

void Engine::Start()
{
	m_isRunning = true;
	Window::Create(m_width, m_height, m_title);
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
	const double dt = 1 / 60.0;

	double currentTime = Time::GetTime();
	double accumulator = 0.0;

	while (m_isRunning)
	{
		double newTime = Time::GetTime();
		double frameTime = newTime - currentTime;
		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt)
		{
			//Close window if necessary
			if (Window::IsCloseRequested())
				Stop();

			//Process input
			Input::Update();

			float deltaTime = std::fmin(frameTime, dt);
			//Step physics simulation here when i get around to it...
			accumulator -= dt;
			t += dt;
		}

		//All rendering done. Flip buffers
		Window::SwapBuffers();
	}

}
