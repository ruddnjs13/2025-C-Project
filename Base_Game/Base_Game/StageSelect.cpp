#include "StageSelect.h"

std::random_device rd;
std::mt19937 generator(rd());

void StageSelect::StageSelectInit()
{
	ShuffleStage();
}

void StageSelect::ShuffleStage()
{
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
	cout << "�̹� ����������!!! : " << stageArr[stageIdx] << "�Դϴ�." << endl;
	stageIdx++;
	stageIdx = std::clamp(stageIdx, 0, 2);
}
