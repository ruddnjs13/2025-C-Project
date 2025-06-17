#pragma once

const int MAP_HEIGHT = 40;
const int MAP_WIDTH = 41;

#include "Console.h"
#include <fstream>
#include "Enums.h"
#include "Player.h"
class Player;



class Map
{
public:
	char gameMap[MAP_HEIGHT][MAP_WIDTH];
public:

	void LoadStage(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	void MapRender(char gameMap[MAP_HEIGHT][MAP_WIDTH], Player* player);
	bool IsAlphabet(char target);
	bool IsColor(char target);
};

