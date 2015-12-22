#include"../Include/GameObject.h"

GameObject::GameObject()
{
	m_parent = nullptr;
	m_components = new std::vector<Component*>;
	m_children = new std::vector<GameObject*>;
	m_renderableComponents = new std::vector<IRenderableComponent*>;
	m_transform = Transform();
}

GameObject::GameObject(GameObject* parent)
{
	m_parent = parent;
	m_components = new std::vector<Component*>;
	m_children = new std::vector<GameObject*>;
	m_renderableComponents = new std::vector<IRenderableComponent*>;
}

GameObject::~GameObject()
{
	for (auto c : *m_components)
		delete c;
	delete m_components;
	for (auto c : *m_children)
		delete c;
	delete m_children;
	for (auto r : *m_renderableComponents)
		delete r;
	delete m_renderableComponents;
}

void GameObject::Update()
{
	for (auto c : *m_components)
		c->Update();
}

void GameObject::Render()
{
	for (auto r : *m_renderableComponents)
		r->Render();
}

Transform GameObject::GetTransform() const
{
	return m_transform;
}
