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
	Player();
	PPLAYER pPlayer;
	void PlayerInit();

	void PlayerUpdate(char _gameMap[40][40]);

	void PlayerRender(char player);

	void HandleInput(char _gameMap[40][40]);
	~Player();
};



