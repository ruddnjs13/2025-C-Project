#pragma once
#include <algorithm>
#include <random>
#include"Console.h"
#include<vector>

using std::vector;

class StageSelect
{
public:
	vector<int> stageArr;
	int stageIdx = 0;

public:
	void StageSelectInit();
	void ShuffleStage();
	void StageSelectRender();
};

