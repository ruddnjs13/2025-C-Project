#include "Core.h"

void Core::Run()
{
	while (true)
	{
		Update();
		Render();
		FrameSync(30);
	}
}

void Core::Update()
{
}

void Core::Render()
{
}
