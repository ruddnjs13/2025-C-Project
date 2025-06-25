#pragma once
#include <algorithm>
#include <random>
#include"Console.h"
#include "SceneManager.h"	
#include<vector>

using std::vector;

class StageSelect
{
public:
	vector<GimmickMode> stageArr;
	int stageIdx = 0;

public:
	void StageSelectInit();
	void StageSelectScene();
	void ShuffleStage();
	void StageSelectRender();
	StageSelect();
	~StageSelect();
};


