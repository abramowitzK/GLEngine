#include "..\Include\MouseState.h"

MouseState::MouseState() : m_x(0), m_y(0), m_xRel(0), m_yRel(0)
{
	memset(m_mouseButtonState, 0, NUM_MOUSE_BUTTONS);
}

MouseState::~MouseState()
{
}

void MouseState::SetPosition(const int x, const int y)
{
	m_x = x;
	m_y = y;
}

void MouseState::SetRelativeMotion(const int relX, const int relY)
{
	m_xRel = relX;
	m_yRel = relY;
}

Vector2 MouseState::GetPosition() const
{
	return Vector2(m_x, m_y);
}

Vector2 MouseState::GetRelativeMotion() const
{
	return Vector2(m_xRel, m_yRel);
}
