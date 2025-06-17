#include "Core.h"

Core::Core()
	: isRunning(true)
	, player(nullptr)
	,map(nullptr)
{
	player = new Player;
	map = new Map;
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
	SetConsoleSettings(1000, 1000, false, L"Game");
	SetLockResize();
	SetCursorVisual(false,50);
	map->LoadStage(map->gameMap);
	player->PlayerInit();
}

void Core::Update()
{
	player->PlayerUpdate(map->gameMap);
}

void Core::Render()
{
	map->MapRender(map->gameMap, player);
	player->PlayerRender("¢Â");
}
