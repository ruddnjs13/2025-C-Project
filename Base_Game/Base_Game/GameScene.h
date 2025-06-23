#pragma once
#include "Map.h"
class GameScene
{
private:
	Map* map;
	Player* player1;
	Player* player2;
public:
	void GamePlayerScene(Map* map, Player* player1, Player* Player2);
};

