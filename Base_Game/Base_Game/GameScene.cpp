#include "GameScene.h"

void GameScene::GamePlayerScene()
{
	GameManager::GetInstance()->Update();
	GameSceneRender();
	FrameSync(60);
}

void GameScene::GameSceneRender()
{
	GameManager::GetInstance()->Render();
}
