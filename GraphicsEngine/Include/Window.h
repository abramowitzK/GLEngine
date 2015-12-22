#pragma once
#include <SDL.h>
#include <string>
#define GLEW_STATIC
#include <GL\glew.h>

class Window
{
public:
	static void Create(const int & width, const int & height, const std::string & title);
	static void SwapBuffers();
	static void Dispose();
	static void SetFullScreen(bool fullscreen);
	static void SetMousePosition(int x, int y);
	static inline bool IsCloseRequested()
	{
		return s_isCloseRequested;
	}
	static void SetIsCloseRequested(bool value);
	static int GetWidth();
	static int GetHeight();
	static float GetAspect();
	static const std::string& GetTitle();	
	static void SetCursorVisible(bool visible);
	static void SetMousePosition(float x, float y);
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

