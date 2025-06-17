#include "Map.h"

void Map::LoadStage(char gameMap[MAP_HEIGHT][MAP_WIDTH])
{
	std::ifstream mapFile("Stage1.txt");

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
		cout << "맵 파일 초기화 실패" << endl;
	}
}

void Map::MapRender(char gameMap[MAP_HEIGHT][MAP_WIDTH], Player* player)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (j == player->position.tPos.x && i == player->position.tPos.y)
				cout << "◈";
			else if (gameMap[i][j] == (char)Tile::WALL)
				cout << "■";
			else if (gameMap[i][j] == (char)Tile::ROAD)
				cout << "  ";
			else if (IsAlphabet(gameMap[i][j]))
				cout << ' ' << gameMap[i][j];
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
				case (char)ColorGimickTile::Black:
					SetColor(COLOR::BLACK);
					break;
				case (char)ColorGimickTile::Gray:
					SetColor(COLOR::GRAY);
					break;
				case (char)ColorGimickTile::Mint:
					SetColor(COLOR::MINT);
					break;
				default:
					SetColor();
				}
				cout << "■";
				SetColor(COLOR::WHITE);
			}
			else
				cout << ' ' << gameMap[i][j];
		}

		cout << endl;
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
