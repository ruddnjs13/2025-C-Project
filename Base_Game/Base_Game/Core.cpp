#include "Core.h"

Core::Core()
	: isRunning(true)
	, player(nullptr)
	,map(nullptr)
	,wordGimmick(nullptr)
{
	player = new Player;
	map = new Map;
	wordGimmick = new WordGimmick;
}
Core::~Core()
{
}

void Core::Run()
{
	Init();
	while (true)
	{
		Update();
		Gotoxy(0, 0);
		Render();
		FrameSync(60);
	}
}

void Core::Init()
{
	SetConsoleSettings(1400, 700, false, L"Game");
	SetLockResize();
	SetCursorVisual(false,50);
	map->LoadStage(map->gameMap);
	player->PlayerInit();
	wordGimmick->Init();
}

void Core::Update()
{
	player->PlayerUpdate(map->gameMap);
}

void Core::Render()
{
	map->MapRender(map->gameMap, player);
	player->PlayerRender("¢Â");
	wordGimmick->GimmickRender();
}
