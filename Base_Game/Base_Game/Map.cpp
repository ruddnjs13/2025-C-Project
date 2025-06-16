#include "Map.h"

//void Map::LoadStage(char gameMap[MAP_HEIGHT][MAP_WIDTH])
//{
//	std::ifstream mapFile("Stage1.txt");
//
//	if (mapFile.is_open())
//	{
//		for (int i = 0; i < MAP_HEIGHT; i++)
//		{
//			mapFile.getline(gameMap[i], MAP_WIDTH);
//		}
//		mapFile.close();
//		return;
//	}
//	else
//	{
//		cout << "맵 파일 초기화 실패" << endl;
//	}
//}
//
//void Map::MapRender(char gameMap[MAP_HEIGHT][MAP_WIDTH])
//{
//	for (int i = 0; i < MAP_HEIGHT; ++i)
//	{
//		for (int j = 0; j < MAP_WIDTH; ++j)
//		{
//			if (gameMap[i][j] == (char)Tile::WALL)
//				cout << "■";
//			else if (gameMap[i][j] == (char)Tile::ROAD)
//				cout << "  ";
//		}
//		cout << endl;
//	}
//}
