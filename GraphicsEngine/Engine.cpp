#include "Engine.h"
#include <math.h>
Engine::Engine(int width, int height, char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
	m_sceneManager = new SceneManager();

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

}

Engine::~Engine()
{
	delete m_sceneManager;
}

void Engine::Start()
{
	m_isRunning = true;
	m_sceneManager->InitScene();
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
			m_physicsWorld->stepSimulation((btScalar)dt);
			//Step physics simulation here when i get around to it...
			t += dt;
			accumulator -= dt;
		}

		//Temp immediate mode to test triangle...
		glBegin(GL_TRIANGLES);
		glVertex2f(-1.0, -1.0);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(0.0, 1.0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(1.0, -1.0);
		glColor3f(0.0, 0.0, 1.0);
		glEnd();
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
