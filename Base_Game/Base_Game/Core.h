#pragma once
#include "Console.h"
#include "Player.h"
#include "Map.h"
#include "WordGimmick.h"


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
	Player* player;
	Map* map;
	WordGimmick* wordGimmick;
	
};




