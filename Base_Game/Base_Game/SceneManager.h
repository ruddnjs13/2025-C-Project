#pragma once
#include "Player.h"
#include "Map.h"

const int MAP_HEIGHT = 40;
const int MAP_WIDTH = 41;


class SceneData
{
public:
	char gameMap[MAP_HEIGHT][MAP_WIDTH];
	Player player;
	//Map map;

	SceneData(Player _player, char _gameMap[MAP_HEIGHT][MAP_WIDTH])
		: player(_player), gameMap(_gameMap[MAP_HEIGHT][MAP_WIDTH])
	{
	}
public:
	void Render();
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





