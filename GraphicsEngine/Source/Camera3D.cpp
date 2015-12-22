#include "..\Include\Camera3D.h"

Camera3D::Camera3D(float fovY, float aspect, float zNear, float zFar) : m_fovY(fovY), m_aspectRatio(aspect), m_zNear(zNear), m_zFar(zFar)
{
	m_projection = glm::perspective(fovY, aspect, zNear, zFar);
	m_view = glm::lookAt(GetTranform().GetTranslation(), Vector3(0.0f), Vector3(0.0f, 1.0f, 0.0f));
}

Camera3D::~Camera3D()
{
}
