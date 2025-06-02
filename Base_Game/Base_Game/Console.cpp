#include "Console.h"


void SetConsoleSettings(int _width, int _height, bool _isFullscreen, const std::wstring& _title)
{
	// ���� ����
	SetConsoleTitle(_title.c_str());

	HWND hwnd = GetConsoleWindow();
	// Ǯ��ũ�� ����
	if (_isFullscreen)
	{
		// ���� Ÿ��Ʋ�� ����
		//SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);
		ShowWindow(hwnd, SW_MAXIMIZE);
	}

	// �ػ� ����
	else
	{
		//LONG style = GetWindowLong(hwnd, GWL_STYLE);
		//style &= ~WS_CAPTION;
		//SetWindowLong(hwnd, GWL_STYLE, style);
		MoveWindow(hwnd, 0,0,_width, _height, true);
	}
}

void SetLockResize()
{
	HWND hwnd = GetConsoleWindow();
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_SIZEBOX &~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

COORD GetConsoleResolution()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	short width  = info.srWindow.Right - info.srWindow.Left  + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top  + 1;
	//COORD coord  {width, height};
	return { width, height };
	//return COORD{ width, height };
}

void Gotoxy(int _x, int _y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { _x, _y };
	//Cur.X = _x;
	SetConsoleCursorPosition(handle, Cur);
}

BOOL IsGotoxy(int _x, int _y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { _x, _y };
	//Cur.X = _x;
	return SetConsoleCursorPosition(handle, Cur);
}

COORD CursorPos()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	return info.dwCursorPosition;
}

void SetCursorVisual(bool _isVis, DWORD _size)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = {_size, _isVis};
	// size : 1 ~ 100, 
	// isvis= false�ϰ� ������ size�� �ּ� 1�� �־�� �մϴ�.
	//info.dwSize = _size;
	SetConsoleCursorInfo(handle, &info);
}

void SetColor(COLOR _textcolor, COLOR _bgcolor)
{
	int textcolor = (int)_textcolor;
	int bgcolor = (int)_bgcolor;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 
		(bgcolor << 4) | textcolor);
}

void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight)
{
	// �ܼ� �ڵ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ����ü �ʱ�ȭ
	CONSOLE_FONT_INFOEX cf = {};
	cf.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// ���� ��Ʈ ���� Get
	GetCurrentConsoleFontEx(handle, false, &cf);
	cf.dwFontSize = _size; // ��, ����
	cf.FontWeight = _weight; // FW~
	wcscpy_s(cf.FaceName, _fontname); // ��Ʈ�̸� ����
	// ��Ʈ ���� Set
	SetCurrentConsoleFontEx(handle, false, &cf);
}

void FrameSync(unsigned int _frame)
{
	clock_t oldtime, curtime;
	oldtime = clock();
	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / _frame)
		{
			oldtime = curtime;
			break;
		}
	}
}