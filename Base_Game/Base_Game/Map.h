#pragma once
#include "Console.h"

const int MAP_HEIGHT = 15;
const int MAP_WIDTH = 61;
const int MAP_START_X = 0;
const int MAP_START_Y = GetConsoleResolution().Y - MAP_HEIGHT;

const string stageNames[] = { "stage1.txt", "stage2.txt","stage3.txt" };

#include <fstream>
#include "Enums.h"
#include "Player.h"
class Player;


class Map
{
public:
	char gameMap[MAP_HEIGHT][MAP_WIDTH];
	int mapIdx = 0;
public:
Map(int idx);
	void MapRender(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	void LoadStage(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	bool IsAlphabet(char target);
	bool IsColor(char target);
	//bool IsExclude()
};




















