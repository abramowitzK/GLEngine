#pragma once
#include <vector>
#include <cstdint>
#include "Interfaces.h"
#include "Component.h"
#include "Transform.h"
class GameObject
{
public:
	GameObject();
	GameObject(GameObject* parent);
	virtual ~GameObject();
	virtual void Update();
	virtual void Render();
	void AddComponent(Component* comp)
	{
		m_components->push_back(comp);
		//comp->BindParent(this);
	}
	void AddRenderingComponent(IRenderableComponent* render)
	{
		m_renderableComponents->push_back(render);
	//	render->BindParent(this);
	}
	Transform GetTransform() const;
	void Translate(float x, float y, float z)
	{
		m_transform.Translate(x, y, z);
	}
private:
	Transform m_transform;
	uint32_t m_id;
	GameObject* m_parent;
	std::vector<IRenderableComponent*>* m_renderableComponents;
	std::vector<Component*>* m_components;
	std::vector<GameObject*>* m_children;
};

