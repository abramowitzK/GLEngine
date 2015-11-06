#include <Window.h>
#include <Engine.h>

#include <iostream>
#undef main

int main(int argc, char* argv[])
{
	Engine* e = new Engine(800, 600, "3D Engine");
	e->Start();
	return 0;
}