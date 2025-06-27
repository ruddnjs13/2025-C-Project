#include "Map.h"


Map::Map(int idx)
{
	mapIdx = idx;
}

void Map::LoadStage(char gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	std::ifstream mapFile(stageNames[mapIdx]);

	if (mapFile.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			mapFile.getline(gameMap[i], MAP_WIDTH);
		}
		mapFile.close();
		return;
	}
	else
	{
		cout << "·Îµå ¾ÈµÊ" << endl;
	}
}

void Map::MapRender(char gameMap[MAP_HEIGHT][MAP_WIDTH], EXCLUDEDATA exData)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			Gotoxy(MAP_START_X+j*2, MAP_START_Y+i);

			bool isFlag = false;

			for (auto& target : exData.targets)
			{
				if (target->CheckHit({ j,i }))
				{
					isFlag = true;
					break;
				}
			}
			if (isFlag) continue;

			else if (exData.player1->position.tPos.x == j && exData.player1->position.tPos.y == i 
				|| exData.player2->position.tPos.x == j && exData.player2->position.tPos.y == i)
				continue;
			
			else if (gameMap[i][j] == (char)Tile::WALL)
				cout << "¡á";
			else if (gameMap[i][j] == (char)Tile::ROAD)
				cout << "  ";
			else if (IsAlphabet(gameMap[i][j]))
				cout << ' ' << gameMap[i][j];
			else if (gameMap[i][j] == (char)GimickTile::ENTER)
				cout << "¢ß";
			else if (gameMap[i][j] == (char)Tile::SHOOT)
				cout << "  ";
			else if (IsColor(gameMap[i][j]))
			{
				switch (gameMap[i][j])
				{
				case (char)ColorGimickTile::Red:
					SetColor(COLOR::RED);
					break;
				case (char)ColorGimickTile::Green:
					SetColor(COLOR::GREEN);
					break;
				case (char)ColorGimickTile::Blue:
					SetColor(COLOR::BLUE);
					break;
				case (char)ColorGimickTile::Yellow:
					SetColor(COLOR::YELLOW);
					break;
				case (char)ColorGimickTile::White:
					SetColor(COLOR::WHITE);
					break;
				case (char)ColorGimickTile::Mint:
					SetColor(COLOR::MINT);
					break;
				default:
					SetColor();
				}
				cout << "¡á";
				SetColor(COLOR::WHITE);
			}
		
		}
	}
}

bool Map::IsAlphabet(char target)
{
	if (target >= (int)GimickTile::A && target <= (int)GimickTile::Z)
		return true;
	return false;
}

bool Map::IsColor(char target)
{
	if (target >= (int)ColorGimickTile::Red && target <= (int)ColorGimickTile::Mint)
		return true;
	if (target == (char)ColorGimickTile::ENTER)
		return true;
	return false;
}
