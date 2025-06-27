#pragma once

#include <vector>
#include "Target.h"
#include "Player.h"

class Player;
class Target;

typedef struct _excludeData
{
	Player* player1;
	Player* player2;
	std::vector<Target*> targets;
}EXCLUDEDATA;
