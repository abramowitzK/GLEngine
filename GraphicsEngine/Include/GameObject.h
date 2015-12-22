#pragma once
#include <vector>
#include <cstdint>
#include "Component.h"
#include "Transform.h"
class GameObject
{
public:
	GameObject();
	GameObject(GameObject* parent);
	virtual ~GameObject();
	void Update();
	void Render();
	Transform GetTranform() const;
private:
	Transform m_transform;
	uint32_t m_id;
	GameObject* m_parent;
	std::vector<Component*>* m_components;
	std::vector<GameObject*>* m_children;
};

