#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "SceneManager.h"
#include "Console.h"
#include <unordered_map>
using std::string;
class PlayerWinCheck
{
public:
	int player1Win = 0;
	int player2Win = 0;
	bool isPlayer1Win = false;
	bool isPlayer2Win = false;
	std::unordered_map<int, std::vector<std::wstring>> playerWinCheckMessage;
	std::unordered_map<int, std::vector<std::wstring>> playerWinMessage;

public:
	PlayerWinCheck();
	void PlayerWinInit();
	void PlayerWinCheckScene(int player1Win, int Player2Win);
	void PlayerWinChecker(int player1Win,int Player2Win);
	void PlayerWinCheckRender();
	void PlayerWinCheckAscii();
	~PlayerWinCheck();
};

