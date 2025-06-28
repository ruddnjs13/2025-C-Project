#include "GameManager.h"
#include <algorithm>
#include <random>
GameManager* GameManager::Instance = nullptr;


GameManager::GameManager()
	: wordGimmick(nullptr)
	, colorGimmick(nullptr)
	,shootingGimmick(nullptr)
	,player1(nullptr)
	,player2(nullptr)
	,map1(nullptr)
	,map2(nullptr)
	,map3(nullptr)
{
	wordGimmick = new WordGimmick;
	colorGimmick = new ColorGimmick;
	shootingGimmick = new ShootingGimmick;

	player1 = new Player(0);
	player2 = new Player(1);

	map1 = new Map(0);
	map2 = new Map(1);
	map3 = new Map(2);
}

GameManager::~GameManager()
{
	delete wordGimmick;
	delete colorGimmick;
	delete shootingGimmick;
	delete player1;
	delete player2;
	delete map1;
	delete map2;
	delete map3;
}

void GameManager::ChooseAnswer(vector<char>& answer)
{
	answer.clear();
	std::random_device rd;
	std::mt19937 generator(rd());

	if (mode == GimmickMode::CORLOR)
	{
		vector<int> arr = {'2','3','4','5','6','7'};

		std::shuffle(arr.begin(), arr.end(),rd);

		for (int i = 0; i < 5; i++)
		{
			answer.push_back(arr[i]);
		}
	}
	else if (mode == GimmickMode::WORD)
	{
		std::uniform_int_distribution<> dis(1, 20);

		string arr = wordList.list[dis(rd)];

		for (int i = 0; i < 5; i++)
		{
			answer.push_back(arr[i]);
		}

		int a = 0;
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
				DrawColorBox(i,COLOR::RED);
				isSelect = false;
			}
			else
			{
				DrawColorBox(i, COLOR::GREEN);
			}
		}
		SetColor(COLOR::WHITE, COLOR::BLACK);
	}
	else if (mode == GimmickMode::WORD)
	{
		for (int i = 0; i < MAX_ANSWER_LENGTH; ++i)
		{
			if (answer[i] != submit[i])
			{
				bool isExist = false;

				for (auto c : answer)
				{
					if (c == submit[i])
					{
						DrawColorBox(i, COLOR::YELLOW);

						isExist = true;
						break;
					}
				}
				if (isExist == false)
				{
					DrawColorBox(i, COLOR::RED);
				}
				isSelect = false;
			}
			else
			{
				DrawColorBox(i, COLOR::GREEN);
			}
		}
		SetColor(COLOR::WHITE, COLOR::BLACK);
	}

	if (isSelect)
	{
		if (player1->myTurn)
		{
		  SceneManager::GetInstance()->player1Win++;
		  SceneManager::GetInstance()->currentScene = Scene::STAGESLECT;
		}
		else
		{
			SceneManager::GetInstance()->player2Win++;
			SceneManager::GetInstance()->currentScene = Scene::STAGESLECT;
			ChangeTurn(player1, player2);
		}
		Reset();
	}
	else
	{
		Sleep(2000);
		Reset();
		ChangeTurn(player1, player2);
	}
}

void GameManager::DrawColorBox(int i ,COLOR color)
{
	for (int j = 0; j < Color_HEIGHT; ++j)
	{
		SetColor(color, COLOR::BLACK);
		Gotoxy(RESULT_X + (Color_WIDTH * i), RESULT_Y + j);
		cout << "¡á¡á¡á¡á¡á¡á" << "\n";

	}
}

void GameManager::Init()
{
	exData.player1 = GameManager::GetInstance()->player1;
	exData.player2 = GameManager::GetInstance()->player2;
	
	if (mode == GimmickMode::CORLOR)
	{
		map1->LoadStage(map1->gameMap);
		colorGimmick->Init();
		player1->myTurn = true;
		player2->myTurn = false;
		player1->isShootingMode = false;
		player2->isShootingMode = false;
		PlalyersInit();

		ChooseAnswer(answer);
	}
	else if (mode == GimmickMode::WORD)
	{
		map2->LoadStage(map2->gameMap);
		wordGimmick->Init();
		player1->myTurn = true;
		player2->myTurn = false;
		player1->isShootingMode = false;
		player2->isShootingMode = false;
		PlalyersInit();

		ChooseAnswer(answer);
	}
	else if (mode == GimmickMode::SHOOT)
	{
		map3->LoadStage(map3->gameMap);
		shootingGimmick->Init();
		player1->myTurn = true;
		player2->myTurn = true;
		player1->isShootingMode = true;
		player2->isShootingMode = true;

		PlalyersInit();
	}
}

void GameManager::PlalyersInit()
{
	player1->position.tStartPos = { 7,6 };
	player2->position.tStartPos = { 55,6 };

	player1->PlayerInit();
	player2->PlayerInit();
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
	else if (mode == GimmickMode::SHOOT)
	{
		player1->PlayerUpdate(map3->gameMap);
		player2->PlayerUpdate(map3->gameMap);
		shootingGimmick->Update();
		exData.targets = GameManager::GetInstance()->shootingGimmick->targets;
	}
}

void GameManager::Render()
{
	if (mode == GimmickMode::CORLOR)
	{
		map1->MapRender(map1->gameMap, exData);
		player1->PlayerRender("¢Â");
		player2->PlayerRender("¢Â");
		colorGimmick->GimmickRender();

	}
	else if(mode == GimmickMode::WORD)
	{

		map2->MapRender(map2->gameMap, exData);
		player1->PlayerRender("¢Â");
		player2->PlayerRender("¢Â");
		wordGimmick->GimmickRender();
	}
	else if (mode == GimmickMode::SHOOT)
	{

		map3->MapRender(map3->gameMap, exData);
		player1->PlayerRender("¦«");
		player2->PlayerRender("¦«");
		shootingGimmick->GimmickRender();
	}
}

void GameManager::Reset()
{
	colorGimmick->Init();
	wordGimmick->Init();
	system("cls");
}

void GameManager::ChangeTurn(Player* p1, Player* p2)
{
	p1->myTurn = !p1->myTurn;
	p2->myTurn = !p2->myTurn;
}



