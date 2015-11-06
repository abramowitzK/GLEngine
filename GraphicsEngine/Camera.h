#pragma once

#include "Math3d.h"
#include "GameComponent.h"
#include "Camera.h"
#include "RenderingEngine.h"
#include "Engine.h"

class Camera : public GameComponent
{
public:
	Camera(const Matrix4f& projection);

	Matrix4f GetViewProjection() const;
	virtual void AddToEngine(Engine* engine);
protected:
private:
	Matrix4f m_projection;
};
