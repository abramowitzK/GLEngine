#include "Engine.h"
#include "Game.h"
#include "RenderingEngine.h"
#include <math.h>
Engine::Engine(int width, int height, char* title, Game* game)
{
	m_width = width;
	m_height = height;
	m_title = title;
	m_sceneManager = new SceneManager();
	Window::Create(m_width, m_height, m_title);
	GLint res = glewInit();
	if (GLEW_OK != res)
	{
		std::cerr << "Error initializing glew" << std::endl;
		SDL_Quit();
		exit(1);
	}
	m_rendering = new RenderingEngine();
	///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();

	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	btCollisionDispatcher* dispatcher = new	btCollisionDispatcher(collisionConfiguration);

	///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
	btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();

	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

	btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

	dynamicsWorld->setGravity(btVector3(0, -10, 0));

	// Set our physics world
	m_physicsWorld = dynamicsWorld;

	m_game = game;
	m_game->SetEngine(this);

}

Engine::~Engine()
{
	delete m_sceneManager;
}

void Engine::Start()
{
	RenderUtil::InitGraphics();
	m_isRunning = true;
	m_sceneManager->InitScene();

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
	const double targetFrameTime = 1 / FPS;
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
#ifdef _DEBUG //This doesn't work. Need to figure out why
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
			m_game->Input(dt);
			m_game->Render(m_rendering);
			m_physicsWorld->stepSimulation((btScalar)dt);
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

RenderingEngine * Engine::GetRenderingEngine()
{
	return m_rendering;
}
