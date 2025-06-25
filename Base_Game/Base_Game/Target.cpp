#include "Target.h"

Target::Target(POS initPos)
{
	myPos = initPos;
}

Target::~Target()
{
	Clear();
}

void Target::Render()
{
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);

	Gotoxy(myPos.x-2, myPos.y-2 + MAP_START_Y);
	for (int i = 0; i < 5; i++)
	{
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

bool Target::CheckHit(POS hitPos)
{

	int dx[] = { -2,-1,0,1,-2 };
	int dy[] = { 2,1,0,-1,-2 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (hitPos.x == (myPos.x + dx[i]) && hitPos.y == (myPos.y + dy[j]))
			{
				return true;

			}
		}
	}

	return false;
}
