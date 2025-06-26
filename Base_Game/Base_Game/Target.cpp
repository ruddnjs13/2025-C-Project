#include "Target.h"

Target::Target(POS initPos)
{
	myPos = initPos;
	spawnTime = time(nullptr);
}

Target::~Target()
{
	Clear();
}

void Target::Update()
{
	lifeTime = time(nullptr) - spawnTime;
	
}

void Target::Render()
{
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);

	for (int i = 0; i < 5; i++)
	{
		Gotoxy(myPos.x * 2 - 2, myPos.y - 2 + MAP_START_Y + i);
		wcout << target[i] << '\n';
	}
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
}

void Target::Clear()
{
	Gotoxy(myPos.x - 2, myPos.y - 2 + MAP_START_Y);
	for (int i = 0; i < 5; i++)
	{
		cout << " " << '\n';
	}
}

void Target::ClearSpawnMap(char spawnMap[MAP_HEIGHT][MAP_WIDTH])
{
	int dx[] = { -2,-1,0,1,2 };
	int dy[] = { 2,1,0,-1,-2 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			spawnMap[myPos.x + dx[i]][myPos.y + dy[j]] = 0;
		}
	}
}

bool Target::CheckHit(POS hitPos)
{

	int dx[] = { -2,-1,0,1,2 };
	int dy[] = { -2,1,0,-1,2 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int checkX = myPos.x + dx[i];
			int checkY = myPos.y + dy[j];


			if (hitPos.x == checkX && hitPos.y == checkY)
				return true;
		}
	}
	return false;
}
