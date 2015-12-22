#pragma once
#include <vector>
#include <cstdint>
#include "Component.h"
class GameObject
{
public:
	GameObject();
	GameObject(GameObject* parent);
	~GameObject();
	void Update();
	void Render();
private:
	uint32_t m_id;
	GameObject* m_parent;
	std::vector<Component*>* m_components;
	std::vector<GameObject*>* m_children;
};

