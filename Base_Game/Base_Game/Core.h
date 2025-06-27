#pragma once
#include "Console.h"
#include "Player.h"
#include "Map.h"
#include "StageSelect.h"
#include "MainMenu.h"
#include "ColorGimmick.h"
#include "WordGimmick.h"
#include "GameManager.h"
#include "PlayerWinCheck.h"
#include "GameScene.h"
#include "InfoScene.h"
#include "Mci.h"

class Core
{
public:
	Core();
	~Core();

public:
	void Run();
private:
	void Init();
	void Update();
	void Render();

private:
	bool isRunning;
	int playerTurn = 1;
	MainMenu* mainMenu;
	StageSelect* stageSelect;
	PlayerWinCheck* playerWinCheck;
	Player* player1;
	Player* player2;
	GameScene* gameScene;
	Map* map1;
	InfoScene* infoScene;

};




