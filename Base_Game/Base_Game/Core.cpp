#include "Core.h"
#include "SceneManager.h"

void Core::Run()
{
	//player.PlayerInit();
	SceneManager::GetInstance()->sceneData.map
		.LoadStage(SceneManager::GetInstance()->sceneData.gameMap);


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
	SceneManager::GetInstance()->sceneData.Render();
}
