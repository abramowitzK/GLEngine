#pragma once
#include "../Include/Scripting/lua-5.2.0/src/lua.hpp"
//Renderable interface
class IRenderable
{
public:
	virtual void Render() = 0;
};
//Interface for all subsystem managers
class IManager
{
public:
	virtual void StartUp() = 0;
	virtual void ShutDown() = 0;
};
//Interface to implement when class should be exposed to scripting api
class IScriptable
{
	static void register_lua(lua_State* L) {};
};