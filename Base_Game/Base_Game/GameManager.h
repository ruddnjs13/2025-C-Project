#pragma once
#include "Player.h"
#include "Map.h"
#include "WordGimmick.h"
#include <algorithm>
#include <random>
#include "ColorGimmick.h"
#include <vector>
#include "WordList.h"
#include "SceneManager.h"
#include "ShootingGimmick.h"
#include "ExcludeData.h"
using std::vector;
using std::cout;
const int MAX_ANSWER_LENGTH = 5;
const int RESULT_X = GetConsoleResolution().X / 4 -1;
const int RESULT_Y = GetConsoleResolution().Y / 4 +1;

class Player;
class Map;
class ShootingGimmick;
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
	GimmickMode mode;

	vector<char> answer;

	EXCLUDEDATA exData;

	WordList wordList;
	Player* player1;
	Player* player2;
	Map* map1;
	Map* map2;
	Map* map3;

	ShootingGimmick* shootingGimmick;
	WordGimmick* wordGimmick;
	ColorGimmick* colorGimmick;

public:
	
	void ChooseAnswer(vector<char>& answer);
	void CheckAnswer(vector<char> submit);
	void DrawColorBox(int i, COLOR color);
	void Init();
	void PlalyersInit();
	void Update();
	void Render();
	void Reset();
	void ChangeTurn(Player* p1, Player* p2);

};

