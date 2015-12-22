#pragma once
#include "Component.h"
#include "Shader.h"
#include "Interfaces.h"
class MeshRenderer : public Component, public IRenderable
{
public:
	MeshRenderer();
	~MeshRenderer();
	virtual void Render();

private:
	Shader* m_shader;
};

