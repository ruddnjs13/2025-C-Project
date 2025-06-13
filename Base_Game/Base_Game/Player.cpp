#include "Player.h"


Player::Player()
{
	
}

void Player::PlayerInit()
{
	pPlayer->position.tStartPos = { 1, 1 };
	pPlayer->position.tPos = pPlayer->position.tStartPos;

}

void Player::PlayerUpdate(char _gameMap[40][40])
{
	HandleInput(_gameMap);
}

void Player::PlayerRender(char player)
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

void Player::HandleInput(char _gameMap[40][40])
{
	pPlayer->position.tNewPos = pPlayer->position.tPos;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::UP:
		--pPlayer->position.tNewPos.y;
		break;
	case Key::DOWN:
		++pPlayer->position.tNewPos.y;
		break;
	case Key::LEFT:
		--pPlayer->position.tNewPos.x;
		break;
	case Key::RIGHT:
		++pPlayer->position.tNewPos.x;
		break;
	}
	/*_pPlayer->position.tNewPos.x =
		std::clamp(_pPlayer->position.tNewPos.x, 0, MAP_WIDTH - 2);
	_pPlayer->position.tNewPos.y =
		std::clamp(_pPlayer->position.tNewPos.y, 0, MAP_HEIGHT - 1);

	if (_gameMap[_pPlayer->position.tNewPos.y][_pPlayer->position.tNewPos.x]
		!= (char)Tile::WALL)
		_pPlayer->position.tPos = _pPlayer->position.tNewPos;*/
	pPlayer->position.tPos = pPlayer->position.tNewPos;
}

Player::~Player()
{
	cout << "¼Ò¸êÇÒ°Ô";
}
