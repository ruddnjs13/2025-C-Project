#pragma once
#include "Console.h";

const int MAP_HEIGHT = 15;
const int MAP_WIDTH = 61;
const int MAP_START_X = 0;
const int MAP_START_Y = GetConsoleResolution().Y - MAP_HEIGHT;

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

