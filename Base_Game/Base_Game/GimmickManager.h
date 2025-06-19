#pragma once
#include "WordGimmick.h"
#include "ColorGimmick.h"
#include "Enums.h"

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
	WordGimmick* wordGimmick;
	ColorGimmick* colorGimmick;
};

