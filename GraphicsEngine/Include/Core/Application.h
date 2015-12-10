#pragma once
#include "GameObject.h"
class Application
{
public:
	void Update();
	void Input();
	void Render(GLRenderer* renderer);
private:
	//Root of the scene graph. Might add a scene class later on
	GameObject* m_root;

};