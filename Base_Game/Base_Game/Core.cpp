#include "Core.h"
char gameMap[40][41]{};
void Core::Run()
{

	while (true)
	{
		Update();
		Gotoxy(0, 0);
		Render();
		FrameSync(60);
	}
}

void Core::Update()
{
	player.PlayerUpdate(gameMap);
}

void Core::Render()
{
	player.PlayerRender("¡×");
}
