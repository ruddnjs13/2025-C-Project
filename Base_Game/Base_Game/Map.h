#pragma once
#include "SceneManager.h"
#include "Console.h"
#include <fstream>
class Player;

class Map
{
public:
	char gameMap[MAP_HEIGHT][MAP_WIDTH];
public:

	void LoadStage(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	void MapRender(char gameMap[MAP_HEIGHT][MAP_WIDTH], Player* player);
	bool IsAlphabet(char target);
};

