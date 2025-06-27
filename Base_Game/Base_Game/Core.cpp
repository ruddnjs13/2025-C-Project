#include "Core.h"

Core::Core()
	: isRunning(true)
	, player1(nullptr)
	, player2(nullptr)
	,map1(nullptr)
	, mainMenu(nullptr)
	, stageSelect(nullptr)
	, playerWinCheck(nullptr)
	, gameScene(nullptr)
{
	player1 = new Player(0);
	player2 = new Player(1);
	map1 = new Map(0);
	mainMenu = new MainMenu;
	stageSelect = new StageSelect;
	playerWinCheck = new PlayerWinCheck;
	gameScene = new GameScene;
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
	SetConsoleSettings(1100, 800,true, L"Game");
	SetLockResize();
	SetCursorVisual(false,50);
	if (!InitAllSounds())
	{
		cout << "사운드 초기화 실패" << endl;
		return;
	}
	PlaySoundID(SOUNDID::BGM, true);
	/*map1->LoadStage(map1->gameMap);
	player1->PlayerInit();
	player2->PlayerInit();
	GimmickManager::GetInstance()->Init();*/

	GameManager::GetInstance()->Init();

}

void Core::Update()
{
	if (SceneManager::GetInstance()->isReset) 
	{
		stageSelect->StageSelectInit();
		playerWinCheck->PlayerWinInit();
		
	}
	switch (SceneManager::GetInstance()->currentScene)
	{
	case Scene::TITLE:
		mainMenu->MainMenuScene();
		break;
	case Scene::STAGESLECT:
		system("cls");
		stageSelect->StageSelectScene();
		break;
	case Scene::WINCHECK:
		system("cls");
		playerWinCheck->PlayerWinCheckScene(SceneManager::GetInstance()->player1Win, SceneManager::GetInstance()->player2Win);
		break;
	case Scene::GAME:
		gameScene->GamePlayerScene();
		break;
	case Scene::INFO:
		break;
	case Scene::QUIT:
		exit(0);
		break;
	case Scene::END:
		isRunning = false;
		break;
	}
	/*if (playerTurn == 0)
	{
		player1->PlayerUpdate(map1->gameMap);
	}
	else
	{
		player2->PlayerUpdate(map1->gameMap);
	}*/
	
}

void Core::Render()
{
	/*map1->MapRender(map1->gameMap, player1);
	player1->PlayerRender("��");
	player2->PlayerRender("��");
	GimmickManager::GetInstance()->Render();*/
	
}
