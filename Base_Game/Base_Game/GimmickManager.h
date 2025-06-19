#pragma once
#include "WordGimmick.h"
#include "ColorGimmick.h"
#include "Enums.h"
#include "vector"
using std::vector;

class GimmickManager
{
private:
	GimmickManager();
	static GimmickManager* Instance;

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

	WordGimmick* wordGimmick;
	ColorGimmick* colorGimmick;

public:
	
	virtual bool CheckAnswer(vector<char> answer);

};

