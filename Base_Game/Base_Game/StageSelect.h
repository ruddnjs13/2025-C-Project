#pragma once
#include <algorithm>
#include <random>
#include"Console.h"
#include "SceneManager.h"	
#include<vector>
#include<string>
#include <unordered_map>

using std::string;
using std::vector;

class StageSelect
{
public:
	vector<GimmickMode> stageArr;
	std::unordered_map<int, vector<wstring>> StageSelectAsciiMap;
	int stageIdx = 0;

public:
	void StageSelectInit();
	void StageSelectScene();
	void ShuffleStage();
	void StageSelectRender();
	void StageSelectAscii();
	StageSelect();
	~StageSelect();
};


