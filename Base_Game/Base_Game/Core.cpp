#include "Core.h"

Core::Core()
	: isRunning(true)
	, player(nullptr)
	,map(nullptr)
	,wordGimmick(nullptr)
	, colorGimmick(nullptr)
{
	player = new Player;
	map = new Map;
	colorGimmick = new ColorGimmick;
	wordGimmick = new WordGimmick;
	
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
	SetConsoleSettings(1600, 700, false, L"Game");
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
	//colorGimmick->GimmickRender();
	//wordGimmick->GimmickRender();

}
