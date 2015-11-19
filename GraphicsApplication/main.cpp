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
	luaL_dofile(lua->L(), "C:\\Users\\Kyle_Windows10\\Documents\\GitHubVisualStudio\\GLEngine\\GraphicsApplication\\Scripts\\Test2.lua");
	luabridge::LuaRef ref = luabridge::getGlobal(lua->L(), "update");
	luabridge::LuaRef ref2 = luabridge::getGlobal(lua->L(), "update2");

	if(!ref.isNil())
		ref();
	if (!ref2.isNil())
		ref2();
	if(!ref.isNil())
		ref();
	return 0;
}