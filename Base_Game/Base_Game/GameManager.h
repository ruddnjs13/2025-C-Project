#pragma once
#include "Player.h"
#include "Map.h"
#include "WordGimmick.h"
#include <algorithm>
#include <random>
#include "ColorGimmick.h"
#include <vector>
#include "WordList.h"
using std::vector;
using std::cout;
const int MAX_ANSWER_LENGTH = 5;
const int RESULT_X = GetConsoleResolution().X / 2;
const int RESULT_Y = GetConsoleResolution().Y / 2;

class Player;
class Map;
class GameManager
{
private:
	static GameManager* Instance;
	GameManager();
	~GameManager();

public:
	static GameManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new GameManager;
		}
		return Instance;
	}
public:
	GimmickMode mode = GimmickMode::CORLOR;

	vector<char> answer;
	WordList wordList;
	Player* player1;
	Player* player2;
	Map* map1;
	Map* map2;
	Map* map3;

	WordGimmick* wordGimmick;
	ColorGimmick* colorGimmick;

public:
	
	void ChooseAnswer(vector<char>& answer);
	void CheckAnswer(vector<char> submit);
	void Init();
	void Update();
	void Render();
	void Reset();
	void ChangeTurn(Player* p1, Player* p2);
};

