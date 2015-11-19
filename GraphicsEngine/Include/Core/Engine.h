#pragma once
#include <SDL.h>
#include <GL\glew.h>
#include <iostream>
#include "Window.h"
#include "../Util/Time.h"
#include "Input.h"
#include "../Util/RenderUtil.h"

extern "C"
{
#include <Lua/lua.h>
#include <Lua/lauxlib.h>
#include <Lua/lualib.h>
}
#include "../Scripting/LuaBridge/LuaBridge.h"
#include "../Scripting/LuaEngine.h"
class Engine
{
public:
	Engine(int width, int height, const char* title);
	~Engine();
	void Start();
	void Stop();
	void Run();
	void Update();
	static void Engine::register_lua(lua_State* L)
	{
		using namespace luabridge;
		getGlobalNamespace(L) //global namespace to lua
			.beginNamespace("Engine") //our defined namespace (w.e we want to call it)
			.beginClass<Engine>("Engine") //define class object
			.addConstructor<void(*) (int, int, const char*)>()
			.addFunction("start", &Engine::Start)
			.endClass() //end class
			.endNamespace(); //end namespace
	}
private:
	int m_height;
	int m_width;
	const char* m_title;
	bool m_isRunning = false;

	LuaEngine* m_luaEngine;
};