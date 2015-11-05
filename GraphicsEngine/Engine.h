#include <SDL.h>
#include <GL\glew.h>
#include "Window.h"
#include "Time.h"
#include "Input.h"

class Engine
{
public:
	Engine(int width, int height, char* title);
	~Engine();
	void Start();
	void Stop();
	void Run();
	bool isRunning();
private:
	int m_height;
	int m_width;
	char* m_title;
	bool m_isRunning = false;
};