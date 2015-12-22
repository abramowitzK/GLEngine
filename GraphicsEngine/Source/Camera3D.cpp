#include "..\Include\Camera3D.h"
#include <GL\glew.h>
Camera3D::Camera3D(float fovY, float aspect, float zNear, float zFar) : m_fovY(fovY), m_aspectRatio(aspect), m_zNear(zNear), m_zFar(zFar), m_up(Vector3(0.0, 1.0, 0.0)), m_position(GetTransform().GetTranslation())
{
	m_projection = glm::perspective(fovY, aspect, zNear, zFar);
	m_view = glm::lookAt(GetTransform().GetTranslation(), Vector3(0.0, 0.0, -4.0), m_up);
}

Camera3D::~Camera3D()
{
}

void Camera3D::Update(Vector3 direction)
{
	m_view = glm::lookAt(GetTransform().GetTranslation(), Vector3(0.0, 0.0, -4.0), m_up);
}
