#pragma once
#include "Enums.h"
#include "Console.h"
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
	GimmickMode mode;
	int player1Win = 0;
	int player2Win = 0;
	void EnterAnimation();
};

