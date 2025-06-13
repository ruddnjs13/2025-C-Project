#pragma once
#include "Console.h"
#include "Player.h"


class Core
{
public:
	void Run();
private:
	void Update();
	void Render();
	Player player;
};




