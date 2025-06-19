#include "Player.h"
Player::Player()
	:position{},
	colorGimick(nullptr),
	wordGimick(nullptr)
{
}


void Player::PlayerInit(ColorGimmick* color , WordGimmick* word)
{
	this->colorGimick = color;
	this->wordGimick = word;
	position.tStartPos = { 5, 5 };
	position.tPos = position.tStartPos;
}

void Player::PlayerUpdate(char gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	HandleInput(gameMap);
}

void Player::PlayerRender(string player)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (position.tPos.x == j &&
				position.tPos.y == i) {
				Gotoxy(j*2, i);
				cout << player;
			}
		}
	}
}

void Player::HandleInput(char gameMap[MAP_HEIGHT][MAP_WIDTH])
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
		break;
	case Key::SPACE:
		Select(gameMap);
		break;
	}


	position.tNewPos.x =
		std::clamp(position.tNewPos.x, 0, MAP_HEIGHT - 2);
	position.tNewPos.y =
		std::clamp(position.tNewPos.y, 0, MAP_WIDTH - 1);

	if (gameMap[position.tNewPos.y][position.tNewPos.x]
		!= (char)Tile::WALL)
		position.tPos = position.tNewPos;
}

void Player::Select(char gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	if (gameMap[position.tPos.y][position.tPos.x] >= (int)GimickTile::A &&
		gameMap[position.tPos.y][position.tPos.x] <= (int)GimickTile::Z)
	{
		wordGimick->Interact(gameMap[position.tPos.y][position.tPos.x]);
		
	}
	else if (gameMap[position.tPos.y][position.tPos.x] >= (int)ColorGimickTile::Red &&
		gameMap[position.tPos.y][position.tEndPos.x] <= (int)ColorGimickTile::Yellow)
	{
		colorGimick->Interact(gameMap[position.tPos.y][position.tPos.x]);
	}
	if (gameMap[position.tPos.y][position.tPos.x] == (int)GimickTile::ENTER)
	{
			wordGimick->Submit();
			colorGimick->Submit();
	}
}

Player::~Player()
{
	cout << "¼Ò¸êÇÒ°Ô";
}
