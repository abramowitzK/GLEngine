#pragma once

#include "Math3D.h"
#include "GameComponent.h"
#include "Input.h"

class FreeLook : public GameComponent
{
public:
	FreeLook(float sensitivity = 1.5f, int unlockMouseKey = Input::KEY_ESCAPE);

	virtual void Input(float delta);
protected:
private:
	float m_sensitivity;
	int m_unlockMouseKey;
};
