#pragma once
#include<iostream>
#include<algorithm>
#include "Console.h"
#include "KeyController.h"
#include "Map.h"
#include "ColorGimmick.h"
#include "WordGimmick.h"
#include "GameManager.h"
#include "Enums.h"
#include "Mci.h"

using std::cin;
using std::cout;

const int START_X = 10;
const int START_Y = 5;

typedef struct _pos
{
	int x;
	int y;
	bool operator == (const _pos& other) const
	{
		return (x == other.x && y == other.y);
	}
}POS, * PPOS;

// 위치 관련 구조체
typedef struct _tagplayerpos
{
	POS tPos;// 현재 위치
	POS tNewPos;// 다음 위치
	POS tStartPos; // 시작 위치
	POS tEndPos;   // 목표 위치
} PLAYERPOS, * PPLAYERPOS;

typedef struct _tagplayer
{
	PLAYERPOS position;    // 위치 정보
} PLAYER, * PPLAYER;

class Player
{
public:
	int playerIdx = 0;
	bool myTurn = false;

	Player(int idx);
	PLAYERPOS position{};  // 위치 정보
	char alphabet = ' ';
	//char colorGimickTile;
	void PlayerInit();

	void PlayerUpdate(char gameMap[MAP_HEIGHT][MAP_WIDTH]);

	void PlayerRender(string player);

	void HandleInput(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	
	void Select(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	~Player();
};



