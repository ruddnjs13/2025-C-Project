#include "StageSelect.h"


void StageSelect::StageSelectInit()
{
	ShuffleStage();
}

void StageSelect::ShuffleStage()
{
	std::random_device rd;
	std::mt19937 generator(rd());


	stageArr.clear();
	std::vector<int> stages = { 1, 2, 3};
	std::shuffle(stages.begin(), stages.end(), rd);
	for (int i = 0; i < 3;i++) 
	{
		stageArr.push_back(stages[i]);
	}
}

void StageSelect::StageSelectRender()
{
	Gotoxy(GetConsoleResolution().X / 2, GetConsoleResolution().Y / 2);
	cout << "이번 스테이지는!!! : " << stageArr[stageIdx] << "입니다." << endl;
	stageIdx++;
	stageIdx = std::clamp(stageIdx, 0, 2);
}
