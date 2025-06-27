#pragma once
#include <vector>
#include "Player.h"
#include "Target.h"

typedef struct _pos
{
	int x;
	int y;
	bool operator == (const _pos& other) const
	{
		return (x == other.x && y == other.y);
	}
}POS, * PPOS;

typedef struct _excludeData
{
	Player* player;
	std::vector<Target*> targets;
}EXCLUDEDATA;
