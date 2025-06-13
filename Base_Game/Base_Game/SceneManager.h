#pragma once
#include "Player.h"
#include "MapManager.h"



class SceneData
{
public:
	Player player;
	char gameMap[MAP_HEIGHT][MAP_WIDTH];

	SceneData(Player _player, char _gameMap[MAP_HEIGHT][MAP_WIDTH])
		: player(_player), gameMap(_gameMap[MAP_HEIGHT][MAP_WIDTH])
	{
	}
};


class SceneManager
{
private:
	SceneManager();
	static SceneManager* Instance;

public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}

	SceneData sceneData;

};





