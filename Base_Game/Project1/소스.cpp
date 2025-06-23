#include <windows.h>
#include <string>
COORD GetConsoleResolution()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;
	//COORD coord  {width, height};
	return { width, height };
	//return COORD{ width, height };
}

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
		MoveWindow(hwnd, 0, 0, _width, _height, true);
	}
}

int main()
{
	SetConsoleSettings(1280, 720, false, L"Game");
	COORD a = GetConsoleResolution();
	int b = 0; 
}