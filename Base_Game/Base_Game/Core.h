#pragma once
#include "Console.h"
#include "Player.h"
#include "Map.h"
#include "MainMenu.h"
#include "ColorGimmick.h"
#include "WordGimmick.h"
#include "GimmickManager.h"

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
	//MainMenu* mainMenu;
	Player* player1;
	Player* player2;
	Map* map1;
};




