#include "MapManager.h"
#include "Console.h"
#include <fstream>



void LoadStage(char gameMap[MAP_HEIGHT][MAP_WIDTH])
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
		cout << "�� ���� �ʱ�ȭ ����" << endl;
	}
}

void SetMap()
{
}
