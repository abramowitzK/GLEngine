#include <iostream>
#include <Include\Engine.h>
#undef main
int main(int argc, char* argv[])
{
	Engine* engine = new Engine(1920, 1080, "3DEngine");
	engine->Start();
	delete engine;
	return 0;
}