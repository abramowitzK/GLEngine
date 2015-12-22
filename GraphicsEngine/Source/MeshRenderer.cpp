#include "..\Include\MeshRenderer.h"



MeshRenderer::MeshRenderer(const std::string & filename) : IRenderableComponent()
{
	m_shader = new Shader();
	m_mesh = new Mesh(filename);
}


MeshRenderer::~MeshRenderer()
{
	delete m_shader;
	delete m_mesh;
}

void MeshRenderer::Render()
{
	m_shader->Bind();
	m_mesh->Draw();
}

void MeshRenderer::OnInit()
{
}

void MeshRenderer::OnEnable()
{
}

void MeshRenderer::Update()
{
}

void MeshRenderer::OnDisable()
{
}

void MeshRenderer::OnDestroy()
{
}
