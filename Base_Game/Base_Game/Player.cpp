#include "Player.h"


Player::Player(int idx)
{
	playerIdx = idx;
}

void Player::PlayerInit()
{
	position.tPos = position.tStartPos;
}

void Player::PlayerUpdate(char gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	if (myTurn == false) return;
	HandleInput(gameMap);
}

void Player::PlayerRender(string player)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (playerIdx == 0)
			{
				if (position.tPos.x == j &&
					position.tPos.y == i)
				{
					Gotoxy(j * 2, i + MAP_START_Y);
					cout << player;
				}
			}
			else
			{
				if (position.tPos.x == j &&
					position.tPos.y == i)
				{
					Gotoxy((j) * 2, i + MAP_START_Y);
					cout << player;
				}
			}
			
		}
	}
}

void Player::HandleInput(char gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	position.tNewPos = position.tPos;
	Key eKey = KeyController(playerIdx);
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

	/*position.tNewPos.x =
		std::clamp(position.tNewPos.x, 0, MAP_HEIGHT - 2);
	position.tNewPos.y =
		std::clamp(position.tNewPos.y, 0, MAP_WIDTH - 1);*/

	if (gameMap[position.tNewPos.y][position.tNewPos.x]
		!= (char)Tile::WALL)
		position.tPos = position.tNewPos;
}

void Player::Select(char gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	if (gameMap[position.tPos.y][position.tPos.x] >= (int)GimickTile::A &&
		gameMap[position.tPos.y][position.tPos.x] <= (int)GimickTile::Z)
	{
		PlaySoundID(SOUNDID::SELECTWORD);
		GameManager::GetInstance()->wordGimmick->Interact(gameMap[position.tPos.y][position.tPos.x]);
		
	}
	else if (gameMap[position.tPos.y][position.tPos.x] >= (int)ColorGimickTile::Red &&
		 gameMap[position.tPos.y][position.tEndPos.x] <= (int)ColorGimickTile::Mint)
	{
		PlaySoundID(SOUNDID::SELECTCOLOR);
	    
		GameManager::GetInstance()->colorGimmick->Interact(gameMap[position.tPos.y][position.tPos.x]);
	}
	if (gameMap[position.tPos.y][position.tPos.x] == (int)GimickTile::ENTER)
	{
		if (GameManager::GetInstance()->mode == GimmickMode::CORLOR)
		{
			CloseSoundID(SOUNDID::SELECTCOLOR);
			CloseSoundID(SOUNDID::SELECTWORD);
			vector<char> submit;
			for (int i = 0; i < 5; i++)
			{
				submit.push_back((GameManager::GetInstance()->colorGimmick->colorGimickTile[i]));
			}
			GameManager::GetInstance()->CheckAnswer(submit);
		}
		else if(GameManager::GetInstance()->mode == GimmickMode::WORD)
		{
			CloseSoundID(SOUNDID::SELECTWORD);
			CloseSoundID(SOUNDID::SELECTCOLOR);
			vector<char> submit;
			for (int i = 0; i < 5; i++)
			{
				submit.push_back((GameManager::GetInstance()->wordGimmick->submitArr[i]));
			}
			GameManager::GetInstance()->CheckAnswer(submit);
		}
	}
	else if(GameManager::GetInstance()->mode == GimmickMode::SHOOT)
	{
		CloseSoundID(SOUNDID::SELECTWORD);
		CloseSoundID(SOUNDID::SELECTCOLOR);

		GameManager::GetInstance()->shootingGimmick->CheckHitTargets(playerIdx, position.tPos);
	}
}

Player::~Player()
{
	cout << "¼Ò¸êÇÒ°Ô";
}
