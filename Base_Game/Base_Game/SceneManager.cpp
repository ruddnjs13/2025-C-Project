#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

void SceneData::Render()
{
	//player.PlayerRender()
	map.MapRender(gameMap);

}
