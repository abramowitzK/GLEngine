#include "..\Include\MeshRenderer.h"



MeshRenderer::MeshRenderer() : Component(Component::Type::MESH_RENDERER)
{

}


MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::Render()
{
	m_shader->Bind();
}
