#pragma once
#include <glm\mat4x4.hpp>
#include "Transform.h"
#include "GameObject.h"
class Camera3D : public GameObject
{
public:
	Camera3D(float fovY, float aspect, float zNear, float zFar);
	~Camera3D();
private:
	Matrix4 m_projection;
	Matrix4 m_view;
	float m_fovY;
	float m_aspectRatio;
	float m_zNear;
	float m_zFar;
};

