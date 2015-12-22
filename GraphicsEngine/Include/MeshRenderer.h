#pragma once
#include "Component.h"
#include "Shader.h"
#include "Interfaces.h"
#include "Mesh.h"
class MeshRenderer : public IRenderableComponent
{
public:
	MeshRenderer(const std::string & filename);
	~MeshRenderer();
	virtual void Render();
	GLuint GetProgram() const
	{
		return m_shader->GetProgram();
	}

private:
	Shader* m_shader;
	Mesh* m_mesh;

	// Inherited via Component
	virtual void OnInit() override;
	virtual void OnEnable() override;
	virtual void Update() override;
	virtual void OnDisable() override;
	virtual void OnDestroy() override;
};

