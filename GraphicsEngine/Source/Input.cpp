#include "../Include/Input.h"
KeyState Input::s_keyState = KeyState();
SDL_Event Input::s_e;
void Input::ProcessInput()
{

	while (SDL_PollEvent(&s_e))
	{
		if (s_e.type == SDL_QUIT)
			Window::SetIsCloseRequested(true);

		//if (e.type == SDL_MOUSEMOTION)
		//{
		//	mouseX = e.motion.x;
		//	mouseY = e.motion.y;
		//}

		if (s_e.type == SDL_KEYDOWN)
		{
			s_keyState.KeyDown(s_e.key.keysym.scancode);
		}
		if (s_e.type == SDL_KEYUP)
		{
			s_keyState.KeyUp(s_e.key.keysym.scancode);
		}
		//if (e.type == SDL_MOUSEBUTTONDOWN)
		//{
		//	int value = e.button.button;

		//	mouseInput[value] = true;
		//	downMouse[value] = true;
		//}
		//if (e.type == SDL_MOUSEBUTTONUP)
		//{
		//	int value = e.button.button;

		//	mouseInput[value] = false;
		//	upMouse[value] = true;
		//}
	}
}

bool Input::GetKey(int keyCode)
{
	return s_keyState.IsKeyPressed(keyCode);
}

bool Input::GetKeyDown(int keyCode)
{
	return GetKey(keyCode);
}

bool Input::GetKeyUp(int keyCode)
{
	return !GetKey(keyCode);
}

//bool Input::GetMouse(int button)
//{
//	return mouseInput[button];
//}
//
//bool Input::GetMouseDown(int button)
//{
//	return downMouse[button];
//}
//
//bool Input::GetMouseUp(int button)
//{
//	return upMouse[button];
//}
//
//Vector2f Input::GetMousePosition()
//{
//	return Vector2f(mouseX, mouseY);
//}
void Input::SetCursor(bool visible)
{
	if (visible)
		SDL_ShowCursor(1);
	else
		SDL_ShowCursor(0);
}

void Input::SetMousePosition(Vector2f pos)
{
	Window::SetMousePosition((int)pos.GetX(), (int)pos.GetY());
}
