#pragma once
#include "WordGimmick.h"
#include "ColorGimmick.h"
#include "Enums.h"
#include "vector"
#include "Console.h"

using std::vector;

const int MAX_ANSWER_LENGTH = 5;
const int RESULT_X = GetConsoleResolution().X / 4 + 5;
const int RESULT_Y = GetConsoleResolution().Y / 2;

class GimmickManager
{
private:
	static GimmickManager* Instance;
	GimmickManager();
	~GimmickManager();

public:
	static GimmickManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new GimmickManager;
		}
		return Instance;
	}
public:
	GimmickMode mode = GimmickMode::CORLOR;

	vector<char> answer;


	WordGimmick* wordGimmick;
	ColorGimmick* colorGimmick;

public:
	
	void ShuffleAnswer(vector<char>& answer);
	void CheckAnswer(vector<char> submit);
	void Init();
	void Render();
	void Reset();
	void RnderResult();


};

