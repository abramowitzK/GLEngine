#pragma once
#include <vector>
#include "../Core/Component.h"
#include "../Scripting/ScriptCommon.h"
class GameObject
{
public:
	GameObject();
	GameObject(GameObject* parent);
	~GameObject();
	void Update();
	void Render();
private:
	GameObject* m_parent;
	std::vector<Component*>* m_components;
	std::vector<GameObject*>* m_children;
};

