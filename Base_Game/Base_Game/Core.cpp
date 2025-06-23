#include "Core.h"

Core::Core()
	: isRunning(true)
{
}
Core::~Core()
{
}

void Core::Run()
{
	Init();
	while (isRunning)
	{
		Update();
		Gotoxy(0, 0);
		Render();
		FrameSync(60);
	}
}

void Core::Init()
{
	srand((unsigned int)time(nullptr));
	SetConsoleSettings(1242, 800,false, L"Game");
	SetLockResize();
	SetCursorVisual(false,50);
	GameManager::GetInstance()->Init();
}

void Core::Update()
{
	GameManager::GetInstance()->Update();
}

void Core::Render()
{
	
	GameManager::GetInstance()->Render();
}
