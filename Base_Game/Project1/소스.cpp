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
	// 제목 설정
	SetConsoleTitle(_title.c_str());

	HWND hwnd = GetConsoleWindow();
	// 풀스크린 할지
	if (_isFullscreen)
	{
		// 위에 타이틀바 제거
		//SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);
		ShowWindow(hwnd, SW_MAXIMIZE);
	}

	// 해상도 설정
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