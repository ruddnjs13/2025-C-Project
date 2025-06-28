#include "Core.h"

Core::Core()
	: isRunning(true)
	, mainMenu(nullptr)
	, stageSelect(nullptr)
	, playerWinCheck(nullptr)
	, gameScene(nullptr)
	, infoScene(nullptr)
{
	mainMenu = new MainMenu;
	stageSelect = new StageSelect;
	playerWinCheck = new PlayerWinCheck;
	gameScene = new GameScene;
	infoScene = new InfoScene;
}
Core::~Core()
{
	delete mainMenu;
	delete stageSelect;
	delete playerWinCheck;
	delete gameScene;
	delete infoScene;
}

void Core::Run()
{
	Init();
	while (isRunning)
	{
		Update();
		FrameSync(60);
	}
}

void Core::Init()
{
	srand((unsigned int)time(nullptr));
	SetConsoleSettings(1200, 800,false, L"Game");
	SetLockResize();
	SetCursorVisual(false,50);
	if (!InitAllSounds())
	{
		cout << "사운드 초기화 실패" << endl;
		return;
	}
	PlaySoundID(SOUNDID::BGM, true);

	GameManager::GetInstance()->Init();

}

void Core::Update()
{
	switch (SceneManager::GetInstance()->currentScene)
	{
	case Scene::TITLE:
		system("cls");
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
		system("cls");
		infoScene->Info();
		break;
	case Scene::QUIT:
		exit(0);
		break;
	case Scene::END:
		isRunning = false;
		break;
	}
	
	
}

