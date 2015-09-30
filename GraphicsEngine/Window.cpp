#include "Window.h"
void Window::Create(int width, int height, const std::string & title)
{
	s_isCloseRequested = false;

	Window::s_width = width;
	Window::s_height = height;
	Window::s_title = title;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	CreateSDLWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	}
}

void Window::SwapBuffers()
{
	SDLSwapBuffers();
}

void Window::Dispose()
{
	SDLDestroyWindow();
	SDL_Quit();
}

void Window::SetMousePosition(int x, int y)
{
	SDLSetMousePosition(x, y);
}

void Window::SetFullScreen(bool fullscreen)
{
	SDLSetWindowFullscreen(fullscreen);
}
bool Window::IsCloseRequested()
{
	return s_isCloseRequested;
}

void Window::SetIsCloseRequested(bool value)
{
	s_isCloseRequested = value;
}

int Window::GetWidth()
{
	return s_width;
}

int Window::GetHeight()
{
	return s_height;
}

float Window::GetAspect()
{
	return (float)GetWidth() / (float)GetHeight();
}

const std::string & Window::GetTitle()
{
	return s_title;
}

void Window::SetCursorVisible(bool visible)
{
	if (visible)
		SDL_ShowCursor(1);
	else
		SDL_ShowCursor(0);
}

void Window::SetMousePosition(Vector2f pos)
{
	SDLSetMousePosition((int)pos.GetX(), (int)pos.GetY());
}

void Window::CreateSDLWindow(const char * title, int x, int y, int width, int height, bool fullscreen)
{
	int mode = 0;

	if (fullscreen)
		mode = SDL_WINDOW_FULLSCREEN;

	s_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | mode);
	s_glContext = SDL_GL_CreateContext(s_window);

	SDL_GL_SetSwapInterval(1);
}

void Window::SDLSetWindowFullscreen(bool value)
{
	int mode = 0;
	if (value)
		mode = SDL_WINDOW_FULLSCREEN;
	else
		mode = 0;

	SDL_SetWindowFullscreen(s_window, mode);
}

void Window::SDLSwapBuffers()
{
	SDL_GL_SwapWindow(s_window);
}

void Window::SDLDestroyWindow()
{
	if (!s_window)
		return;

	SDL_GL_DeleteContext(s_glContext);
	SDL_DestroyWindow(s_window);
}

void Window::SDLSetMousePosition(int x, int y)
{
	SDL_WarpMouseInWindow(s_window, x, y);
}
