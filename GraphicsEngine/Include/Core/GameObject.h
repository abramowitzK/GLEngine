#pragma once
#include <vector>
#include "../Core/Component.h"
class GameObject
{
public:
	GameObject();
	~GameObject();
private:
	GameObject* m_parent;
	std::vector<Component*> m_components;
	std::vector<GameObject*> m_childrent;
};

