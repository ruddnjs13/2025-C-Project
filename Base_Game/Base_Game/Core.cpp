#include "Core.h"

void Core::Run()
{
	player.PlayerInit();

	while (true)
	{
		Update();
		Render();
		FrameSync(30);
	}
}

void Core::Update()
{
	//player.PlayerUpdate();
}

void Core::Render()
{
	player.PlayerRender('$');
}
