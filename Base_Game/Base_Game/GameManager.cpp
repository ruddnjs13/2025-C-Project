#include "GameManager.h"
#include <algorithm>
#include <random>
GameManager* GameManager::Instance = nullptr;


GameManager::GameManager()
	: wordGimmick(nullptr)
	, colorGimmick(nullptr)
	,player1(nullptr)
	,player2(nullptr)
	,map1(nullptr)
	,map2(nullptr)
	,map3(nullptr)
{
	wordGimmick = new WordGimmick;
	colorGimmick = new ColorGimmick;
	player1 = new Player(0);
	player2 = new Player(1);
	map1 = new Map(0);
	map2 = new Map(1);
	map3 = new Map(2);
}

GameManager::~GameManager()
{
}

void GameManager::ShuffleAnswer(vector<char>& answer)
{
	std::random_device rd;
	std::mt19937 generator(rd());

	if (mode == GimmickMode::CORLOR)
	{
		vector<int> arr = {'2','3','4','5','6','7'};

		std::shuffle(arr.begin(), arr.end(),rd);

	    answer.clear();
		for (int i = 0; i < 5; i++)
		{
			answer.push_back(arr[i]);
		}
	}
	else
	{
	}
}

void GameManager::CheckAnswer(vector<char> submit)
{
	bool isSelect = true;

	if (mode == GimmickMode::CORLOR)
	{
		for (int i = 0; i < MAX_ANSWER_LENGTH; ++i)
		{
			if (answer[i] != submit[i])
			{
				for (int j = 0; j < Color_HEIGHT; ++j)
				{
					SetColor(COLOR::RED, COLOR::BLACK);
					Gotoxy(RESULT_X + (Color_WIDTH * i), RESULT_Y + j);
					cout << "¡á¡á¡á¡á¡á¡á" << "\n";

				}
				isSelect = false;
			}
			else
			{
				for (int j = 0; j < Color_HEIGHT; ++j)
				{
					SetColor(COLOR::GREEN, COLOR::BLACK);
					Gotoxy(RESULT_X + (Color_WIDTH * i), RESULT_Y + j);
					cout << "¡á¡á¡á¡á¡á¡á" << "\n";

				}
			}
		}
				SetColor(COLOR::WHITE, COLOR::BLACK);
	}
	else if (mode == GimmickMode::WORD)
	{
	}

	if (isSelect)
	{
		// ¸ÂÀ½
	}
	else
	{
		Sleep(2000);
		Reset();
		ChangeTurn(player1, player2);
	}
}

void GameManager::Init()
{
	colorGimmick->Init();
	wordGimmick->Init();
	player1->myTurn = true;
	player2->myTurn = false;

	player1->PlayerInit();
	player2->PlayerInit();

	map1->LoadStage(map1->gameMap);
	map2->LoadStage(map2->gameMap);
	//map3->LoadStage(map3->gameMap);

	ShuffleAnswer(answer);
}

void GameManager::Update()
{
	if (mode == GimmickMode::CORLOR)
	{
		player1->PlayerUpdate(map1->gameMap);
		player2->PlayerUpdate(map1->gameMap);
	}
	else if (mode == GimmickMode::WORD)
	{
		player1->PlayerUpdate(map2->gameMap);
		player2->PlayerUpdate(map2->gameMap);
	}

}


void GameManager::Render()
{
	if (mode == GimmickMode::CORLOR)
	{
		colorGimmick->GimmickRender();
		map1->MapRender(map1->gameMap);
		player1->PlayerRender("¢Â");
		player2->PlayerRender("¢Â");

	}
	else if(mode == GimmickMode::WORD)
	{
		wordGimmick->GimmickRender();
		map2->MapRender(map2->gameMap);
		player1->PlayerRender("¢Â");
		player2->PlayerRender("¢Â");
	}
}

void GameManager::Reset()
{
	colorGimmick->Init();
	system("cls");
}


void GameManager::ChangeTurn(Player* p1, Player* p2)
{
	p1->myTurn = !p1->myTurn;
	p2->myTurn = !p2->myTurn;
}


