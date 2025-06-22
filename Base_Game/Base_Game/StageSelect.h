#pragma once
#include<iostream>
#include<vector>
#include"Console.h"
#include <algorithm>
#include <random>

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

