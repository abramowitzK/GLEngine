#include <Engine.h>
#include <Vector.h>

#include <iostream>
#undef main
int main(int argc, char* argv[])
{
	Engine e = Engine();
	Vector2f floatVector = Vector2f(2.1f, 4.0f);
	std::cout << floatVector.ToString() << std::endl;
	return 0;
}