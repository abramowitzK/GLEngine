#include"../Include/GameObject.h"

GameObject::GameObject()
{
	m_parent = nullptr;
	m_components = new std::vector<Component*>;
	m_children = new std::vector<GameObject*>;
}

GameObject::GameObject(GameObject* parent)
{
	m_parent = parent;
	m_components = new std::vector<Component*>;
	m_children = new std::vector<GameObject*>;
}

GameObject::~GameObject()
{
	delete m_components;
	delete m_children;
}
