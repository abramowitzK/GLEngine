#pragma once
/*
Defines the Component interface which all game components must implement
*/
//Forward declarations
class GameObject;

class Component
{
public:
	enum class Type
	{
		LUA_SCRIPT,
		LIGHT,
		UI_TEXT,
		UI_BUTTON,
		UI_TEXTURE,
		MESH,
		CAMERA,
		PHYSICS_RIGIDBODY
	};
	Component(Type type)
	{
		m_type = type;
	}
	virtual ~Component() { };
	virtual void OnInit() = 0;
	virtual void OnEnable() = 0;
	virtual void Update() = 0;
	virtual void OnDisable() = 0;
	virtual void OnDestroy() = 0;
	virtual void BindParent(GameObject* parent)
	{
		m_parent = parent;
	}
	virtual Component::Type GetType()
	{
		return m_type;
	}

protected:
	GameObject* m_parent;
	Type		m_type;
};