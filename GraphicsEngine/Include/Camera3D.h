#pragma once
#include <glm\mat4x4.hpp>
#include "Transform.h"
#include "GameObject.h"
class Camera3D : public GameObject
{
public:
	Camera3D(float fovY, float aspect, float zNear, float zFar);
	~Camera3D();
	Matrix4 GetProjectionMatrix() const
	{
		return m_projection;
	}
	Matrix4 GetViewMatrix() const
	{
		return m_view;
	}
	void Update(Vector3 direction);
private:
	Matrix4 m_projection;
	Matrix4 m_view;
	float m_fovY;
	float m_aspectRatio;
	float m_zNear;
	float m_zFar;
	Vector3 m_up;
	Vector3 m_position;
};

