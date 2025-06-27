#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() 
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::FlashAnimation(COORD _resolution, int _cnt, int _delaytime)
{
	for (int c = 0; c < _cnt; ++c)
	{
		SetColor(COLOR::BLACK, COLOR::WHITE);
		system("cls");
		Sleep(_delaytime);
		SetColor();
		system("cls");
	}
}

void SceneManager::CrossAnimation(COORD _resolution, int _delaytime)
{
	SetColor(COLOR::BLACK, COLOR::WHITE);
	for (int i = 0; i < _resolution.X / 2; ++i)
	{
		for (int j = 0; j < _resolution.Y; j += 2)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		for (int j = 1; j < _resolution.Y; j += 2)
		{
			Gotoxy(_resolution.X - 2 - i * 2, j);
			cout << "  ";
		}
		Sleep(_delaytime);
	}
	SetColor();
}

void SceneManager::EnterAnimation()
{
	COORD resolution = GetConsoleResolution();
	int delaytime = 20;
	int flashCnt = 5;
	FlashAnimation(resolution, flashCnt, delaytime);
	CrossAnimation(resolution, delaytime);
	//SetColor(COLOR::WHITE, COLOR::MINT);
	system("cls");
	GameManager::GetInstance()->Init();
}
