#pragma once
#include<iostream>
#include "Player.h"
#include "Console.h"
#include "Enums.h"
#include "KeyController.h"
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
	PPLAYER pPlayer;
	void PlayerInit();

	void PlayerUpdate(char _gameMap[40][40]);

	void PlayerRender(char player);

	void HandleInput(char _gameMap[40][40]);
	~Player();
};



