#include<iostream>
#include "Player.h"
#include "Enums.h"
#include "KeyController.h"
using std::cout;
using std::cout;

void PlayerInit(PPLAYER pPlayer)
{
	pPlayer->position.tStartPos = { 1, 1 };
	pPlayer->position.tPos = pPlayer->position.tStartPos;
}

void PlayerUpdate(char _gameMap[40][40], PPLAYER _pPlayer)
{
	HandleInput(_gameMap,_pPlayer);
}

void PlayerRender(char player, PPLAYER pPlayer)
{

	for (int i = 0; i < 40; ++i)
	{
		for (int j = 0; j < 40; ++j)
		{
			if (pPlayer->position.tPos.x == j &&
				pPlayer->position.tPos.y == i)
				cout << player;
		}
	}
}

void HandleInput(char _gameMap[40][40], PPLAYER _pPlayer)
{
	_pPlayer->position.tNewPos = _pPlayer->position.tPos;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::UP:
		--_pPlayer->position.tNewPos.y;
		break;
	case Key::DOWN:
		++_pPlayer->position.tNewPos.y;
		break;
	case Key::LEFT:
		--_pPlayer->position.tNewPos.x;
		break;
	case Key::RIGHT:
		++_pPlayer->position.tNewPos.x;
		break;
	}
	/*_pPlayer->position.tNewPos.x =
		std::clamp(_pPlayer->position.tNewPos.x, 0, MAP_WIDTH - 2);
	_pPlayer->position.tNewPos.y =
		std::clamp(_pPlayer->position.tNewPos.y, 0, MAP_HEIGHT - 1);

	if (_gameMap[_pPlayer->position.tNewPos.y][_pPlayer->position.tNewPos.x]
		!= (char)Tile::WALL)
		_pPlayer->position.tPos = _pPlayer->position.tNewPos;*/

}
