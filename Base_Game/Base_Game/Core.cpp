#include "Core.h"
#include "Player.h"

PLAYER player = {};
char gameMap[40][40] = {};
void Core::Run()
{
	PlayerInit(&player);
	while (true)
	{
		Update();
		Render();
		// FrameSync
	}
}

void Core::Update()
{
	PlayerUpdate(gameMap, &player);
}

void Core::Render()
{
	PlayerRender('ขา', &player);
}
