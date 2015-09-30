#pragma once
#include <SDL.h>
#include <string>
#include <GL\glew.h>
class Window
{
public:
	static void Create(int width, int height, const std::string& title);
	static void SwapBuffers();
	static void Dispose();
	static void SetFullScreen(bool fullscreen);
	static void SetMousePosition(int x, int y);
	static bool IsCloseRequested();
	static void SetIsCloseRequested(bool value);
	static int GetWidth();
	static int GetHeight();
	static float GetAspect();
	static const std::string& GetTitle();
private:
	static SDL_Window* s_window;
	static SDL_GLContext s_glContext;
	static int s_width;
	static int s_height;
	static std::string s_title;
	static bool s_isCloseRequested;
	static void CreateSDLWindow(const char* title, int x, int y, int width, int height, bool fullscreen);
	static void SDLSetWindowFullscreen(bool value);
	static void SDLSwapBuffers();
	static void SDLDestroyWindow();
	static void SDLSetMousePosition(int x, int y);
};
