#pragma once
#include<iostream>
#include <string>
#include "SceneManager.h"
#include "Console.h"
using std::string;
class PlayerWinCheck
{
public:
	int player1Win = 0;
	int player2Win = 0;
	bool isPlayer1Win = false;
	bool isPlayer2Win = false;

public:
	void PlayerWinCheckScene(int player1Win, int Player2Win);
	void PlayerWinChecker(int player1Win,int Player2Win);
	void PlayerWinCheckRender();
};

