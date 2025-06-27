#include "KeyController.h"
#include<Windows.h>
Key KeyController(int idx, bool isNotdelay)
{

	if (idx == 1)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			//Sleep(50);
			return Key::UP;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			//Sleep(50);
			return Key::DOWN;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			//Sleep(50);
			return Key::LEFT;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			//Sleep(50);
			return Key::RIGHT;
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if(isNotdelay == false)
				Sleep(200);
			return Key::SPACE;
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{

			return Key::ESC;
		}
		return Key::FAIL;
	}
	else
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			//Sleep(50);
			return Key::UP;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			//Sleep(50);
			return Key::DOWN;
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			//Sleep(50);
			return Key::LEFT;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			//Sleep(50);
			return Key::RIGHT;
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (isNotdelay == false)
				Sleep(200);
			return Key::SPACE;
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{

			return Key::ESC;
		}
		return Key::FAIL;
	}
}
