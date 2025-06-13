#include "MapManager.h"
#include "Player.h"

#pragma once


class SceneData
{
public:
	PPLAYER pPlayer;
	char gameMap[MAP_HEIGHT][MAP_WIDTH];

	SceneData(PPLAYER _player, char _gameMap[MAP_HEIGHT][MAP_WIDTH])
		: pPlayer(_player), gameMap(_gameMap[MAP_HEIGHT][MAP_WIDTH])
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





