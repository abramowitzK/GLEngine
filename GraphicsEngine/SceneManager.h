#pragma once
#include "GameObject.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void InitScene();
private:
	GameObject* m_root;
};

