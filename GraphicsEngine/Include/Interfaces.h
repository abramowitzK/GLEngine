#pragma once
#include "Component.h"
//Renderable interface
class IRenderableComponent : public Component
{
public:
	IRenderableComponent() : Component(Component::Type::MESH_RENDERER)
	{}
	virtual void Render() = 0;
};
//Interface for all subsystem managers
class IManager
{
public:
	virtual void StartUp() = 0;
	virtual void ShutDown() = 0;
};