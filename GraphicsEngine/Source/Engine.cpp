#include "..\Include\Engine.h"
#include <math.h>
GLuint vbo;
static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}
static void CreateVertexBuffer()
{
	Vector3f Vertices[3];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}
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
}

Engine::~Engine()
{
	Window::Dispose();
}

void Engine::Start()
{
	RenderUtil::InitGraphics();
	m_isRunning = true;
	CreateVertexBuffer();
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
		Time::DeltaTime = frameTime;
		if (frameTime > 0.25)
			frameTime = 0.25;
		currentTime = newTime;
		accumulator += frameTime;
#ifdef _DEBUG
		frameCounter += frameTime;
		if (frameCounter >= 1.0)
		{
			std::cout << 1.0/frameTime << std::endl;
			frames = 0;
			frameCounter = 0.0;
		}
#endif
		while (accumulator >= dt)
		{
			//Close window if necessary
			if (Window::IsCloseRequested())
				Stop();		
			//Step physics simulation here when i get around to it...
			t += dt;
			accumulator -= dt;
		}
		RenderSceneCB();
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
