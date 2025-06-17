#include "Player.h"
Player::Player()
	:position{}
{
}


void Player::PlayerInit()
{
	position.tStartPos = { 0, 0 };
	position.tPos = position.tStartPos;
}

void Player::PlayerUpdate(char _gameMap[40][41])
{
	HandleInput(_gameMap);
}

void Player::PlayerRender(string player)
{
	for (int i = 0; i < 40; ++i)
	{
		for (int j = 0; j < 41; ++j)
		{
			if (position.tPos.x == j &&
				position.tPos.y == i) {
				Gotoxy(j, i);
				cout << player;
			}
		}
	}
}

void Player::HandleInput(char _gameMap[40][41])
{
	position.tNewPos = position.tPos;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::UP:
		--position.tNewPos.y;
		break;
	case Key::DOWN:
		++position.tNewPos.y;
		break;
	case Key::LEFT:
		--position.tNewPos.x;
		break;
	case Key::RIGHT:
		++position.tNewPos.x;
	case Key::SPACE:
		Select();
		break;
	}


	position.tNewPos.x =
		std::clamp(position.tNewPos.x, 0, 41 - 2);
	position.tNewPos.y =
		std::clamp(position.tNewPos.y, 0, 40 - 1);

	if (_gameMap[position.tNewPos.y][position.tNewPos.x]
		!= (char)Tile::WALL)
		position.tPos = position.tNewPos;
}

void Player::Select()
{
}

Player::~Player()
{
	cout << "¼Ò¸êÇÒ°Ô";
}
