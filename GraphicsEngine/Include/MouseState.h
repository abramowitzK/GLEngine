#pragma once
#include "Transform.h"
class MouseState
{
public:
	MouseState();
	~MouseState();
	void SetPosition(const int x, const int y);
	void SetRelativeMotion(const int relX, const int relY);
	Vector2 GetPosition() const;
	Vector2 GetRelativeMotion() const;
private:
	const static size_t NUM_MOUSE_BUTTONS = 4;
	char m_mouseButtonState[NUM_MOUSE_BUTTONS];
	int m_x;
	int m_y;
	int m_xRel;
	int m_yRel;
};

