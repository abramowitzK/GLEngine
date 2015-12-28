#include "..\Include\Camera3D.h"
#include "..\Include\Input.h"
#include "..\Include\Time.h"
#include <GL\glew.h>
Camera3D::Camera3D(float fovY, float aspect, float zNear, float zFar)
	:
	m_fovY(fovY),
	m_aspectRatio(Window::GetAspect()),
	m_zNear(zNear),
	m_zFar(zFar),
	m_up(Vector3(0.0, 1.0, 0.0)),
	m_position(GetTransform().GetPosition()),
	m_cameraDirection(Vector3(0.0f, 0.0f, -1.0f)),
	m_yaw(-90.0f),
	m_pitch(0.0f)
{
	m_projection = glm::perspective(fovY, aspect, zNear, zFar);
	m_view = glm::lookAt(m_position, m_position + m_cameraDirection, m_up);
}

Camera3D::~Camera3D()
{
}
void Camera3D::Update()
{
	GLfloat speed = (float)((double)1.0f * Time::DeltaTime());
	if (Input::GetKey(Input::Keys::KEY_W))
	{
		m_position += speed * m_cameraDirection;
	}
	if (Input::GetKey(Input::Keys::KEY_S))
	{
		m_position -= speed * m_cameraDirection;
	}
	if (Input::GetKey(Input::Keys::KEY_A))
	{
		m_position -= glm::normalize(glm::cross(m_cameraDirection, m_up)) * speed;
	}
	if (Input::GetKey(Input::Keys::KEY_D))
	{
		m_position += glm::normalize(glm::cross(m_cameraDirection, m_up)) * speed;
	}
	m_view = glm::lookAt(m_position, m_position + m_cameraDirection, m_up);
	Vector2 rel = Input::GetRelativeMouseMotion();
	GLfloat xoffset = rel.x;
	GLfloat yoffset = -rel.y;
	if (xoffset != 0 || yoffset != 0)
	{
		GLfloat sensitivity = 0.4f;
		GLfloat ySense = 0.7f;
		xoffset *= sensitivity;
		yoffset *= ySense;

		m_yaw += xoffset;
		m_pitch += yoffset;
		if (m_pitch > 89.0f)
			m_pitch = 89.0f;
		if (m_pitch < -89.0f)
			m_pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		front.y = sin(glm::radians(m_pitch));
		front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_cameraDirection = glm::normalize(front);
	}

	m_view = glm::lookAt(m_position, m_position + m_cameraDirection, m_up);
}
