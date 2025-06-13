#pragma once
#include<iostream>
#include<algorithm>
#include "Console.h"
#include "Enums.h"
#include "KeyController.h"
#include "Player.h"

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
} Player, * PPLAYER;

class Player
{
public:
	Player();
	PLAYERPOS position{};    // ��ġ ����

	void PlayerInit();

	void PlayerUpdate(char _gameMap[40][41]);

	void PlayerRender(string player);

	void HandleInput(char _gameMap[40][41]);
	~Player();
};



