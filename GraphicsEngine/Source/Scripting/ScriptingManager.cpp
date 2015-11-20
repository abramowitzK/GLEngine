#include "../../Include/Scripting/ScriptingManager.h"

void ScriptingManager::StartUp()
{
	m_engine = LuaEngine();
	lua_State* state = m_engine.L();
	//Need to register all the classes we want to use with the scripting api
	Vector2f::register_lua(state);
}
void ScriptingManager::ShutDown()
{}