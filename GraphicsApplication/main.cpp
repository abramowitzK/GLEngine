#include <iostream>
#include <Include\Util\Time.h>
#include <Include\Core\Engine.h>
#include <Include\Scripting\LuaEngine.h>
#undef main
int main(int argc, char* argv[])
{
	//Engine* engine = new Engine(800, 600, "3DEngine");
	LuaEngine* lua = new LuaEngine();
	luaL_dofile(lua->L(), "C:\\Users\\Kyle_Windows10\\Documents\\GitHubVisualStudio\\GLEngine\\GraphicsApplication\\Scripts\\Test.lua");
	Engine::register_lua(lua->L());
	luabridge::LuaRef ref = luabridge::getGlobal(lua->L(), "update");
	//luabridge::push(lua->L(), engine);

	if(!ref.isNil())
		ref();
	return 0;
}