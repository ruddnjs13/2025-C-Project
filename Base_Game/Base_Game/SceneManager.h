#pragma once
#include "Enums.h"
#include "Console.h"
#include "GameManager.h"
class SceneManager
{
private:
	static SceneManager* Instance;
	SceneManager();
	~SceneManager();
	void FlashAnimation(COORD _resolution, int _cnt, int _delaytime);
	void CrossAnimation(COORD _resolution, int _delaytime);
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}
	Scene currentScene = Scene::TITLE;
	bool isReset = false;
	int player1Win = 0;
	int player2Win = 0;
	void EnterAnimation();
};

