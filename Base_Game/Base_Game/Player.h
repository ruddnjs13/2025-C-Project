#pragma once
#include<iostream>
#include<algorithm>
#include "Console.h"
#include "KeyController.h"
#include "Map.h"
#include "ColorGimmick.h"
#include "WordGimmick.h"

using std::cin;
using std::cout;

typedef struct _pos
{
	int x;
	int y;
	bool operator == (const _pos& other) const
	{
		return (x == other.x && y == other.y);
	}
}POS, * PPOS;

// ��ġ ���� ����ü
typedef struct _tagplayerpos
{
	POS tPos;// ���� ��ġ
	POS tNewPos;// ���� ��ġ
	POS tStartPos; // ���� ��ġ
	POS tEndPos;   // ��ǥ ��ġ
} PLAYERPOS, * PPLAYERPOS;

typedef struct _tagplayer
{
	PLAYERPOS position;    // ��ġ ����
} PLAYER, * PPLAYER;

class Player
{
public:
	Player();
	PLAYERPOS position{};    // ��ġ ����
	ColorGimmick* colorGimick;
	WordGimmick* wordGimick;
	char alphabet = ' ';
	char colorGimickTile;
	void PlayerInit();

	void PlayerUpdate(char gameMap[MAP_HEIGHT][MAP_WIDTH]);

	void PlayerRender(string player);

	void HandleInput(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	
	void Select(char gameMap[MAP_HEIGHT][MAP_WIDTH]);
	~Player();
};



