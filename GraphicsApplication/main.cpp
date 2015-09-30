#include <Engine.h>
#include <Vector.h>

#include <iostream>
#undef main
int main(int argc, char* argv[])
{
	Engine e = Engine();
	Vector2f floatVector = Vector2f(2.0f, 4.0f);
	std::cout << floatVector.ToString() << std::endl;
	std::cout << floatVector.Dot(floatVector) << std::endl;
	return 0;
}