#include "Core.h"

Core::Core()
	: isRunning(true)
	, player1(nullptr)
	, player2(nullptr)
	,map1(nullptr)
{
	player1 = new Player(0);
	player1->myTurn = true;
	player2 = new Player(1);
	player2->myTurn = false;
	map1 = new Map;
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
	SetConsoleSettings(1242, 700,false, L"Game");
	SetLockResize();
	SetCursorVisual(false,50);
	map1->LoadStage(map1->gameMap);
	player1->PlayerInit();
	player2->PlayerInit();
	GimmickManager::GetInstance()->Init();
}

void Core::Update()
{
		player1->PlayerUpdate(map1->gameMap);
		player2->PlayerUpdate(map1->gameMap);
}

void Core::Render()
{
	map1->MapRender(map1->gameMap, player1);
	player1->PlayerRender("¢Â");
	player2->PlayerRender("¢Â");
	GimmickManager::GetInstance()->Render();
}
