#include "..\Include\Engine.h"
#include <math.h>
#include "../Include/MeshRenderer.h"
#include <glm\gtc\type_ptr.hpp>
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
//	Window::SetFullScreen(true);
	Window::ConfineMouseCursor(true);
	m_isRunning = true;
	m_root = new GameObject();
	m_mesh = new MeshRenderer("buddha.obj");
	m_root->AddRenderingComponent(m_mesh);
	m_cam = new Camera3D(70.0f, (float)m_width / (float)m_height, 0.1f, 1000.0f);
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
		Time::SetDeltaTime(frameTime);
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
			if (Input::GetKey(Input::Keys::KEY_ESCAPE))
				Window::SetIsCloseRequested(true);
			//Close window if necessary
			if (Window::IsCloseRequested())
				Stop();
			Input::ProcessInput();
			//Step physics simulation here when i get around to it...
			t += dt;
			accumulator -= dt;
		}

		//All rendering done. Flip buffers
		Update();
		Input::ResetRelativePosition();
		Window::SwapBuffers();
#ifdef _DEBUG
		frames++;
#endif
	}
}

void Engine::Update()
{
	if (Input::GetKey(Input::Keys::KEY_0))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if (Input::GetKey(Input::Keys::KEY_1))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	//Hack just to test rendering
	RenderUtil::ClearScreen();
	Matrix4 view = m_cam->GetViewMatrix();
	Matrix4 proj = m_cam->GetProjectionMatrix();
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));
	Matrix4 mvp = proj * view * model;

	GLint loc = glGetUniformLocation(m_mesh->GetProgram(), "MVP");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mvp));
	m_root->Render();

	m_cam->Update();

	
}

void Engine::BeginFrame()
{
}
void Engine::EndFrame()
{
}

