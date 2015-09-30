#pragma once
#include <SDL.h>
class Window
{
public:
	void Create();
private:
	static SDL_Window* s_window;
	static int s_width;
	static int s_height;
};

