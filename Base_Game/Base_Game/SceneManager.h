#pragma once
#include "MapManager.h"
#include "Player.h"


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


};





