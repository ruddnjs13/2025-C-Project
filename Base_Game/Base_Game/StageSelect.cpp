#include "StageSelect.h"


StageSelect::StageSelect()
{
	StageSelectInit();
}

void StageSelect::StageSelectInit()
{
	ShuffleStage();
}

void StageSelect::StageSelectScene()
{
	StageSelectRender();
	Sleep(3000);
	SceneManager::GetInstance()->currentScene = Scene::WINCHECK;
}

void StageSelect::ShuffleStage()
{
	std::random_device rd;
	std::mt19937 generator(rd());


	stageArr.clear();
	std::vector<GimmickMode> stages = {GimmickMode::CORLOR,GimmickMode::WORD , GimmickMode::CORLOR };
	std::shuffle(stages.begin(), stages.end(), rd);
	for (int i = 0; i < 3;i++) 
	{
		stageArr.push_back(stages[i]);
	}
}

void StageSelect::StageSelectRender()
{
	string stageName;
	switch (stageArr[stageIdx])
	{
	case GimmickMode::CORLOR:
		stageName = "������߱�";
		Gotoxy(GetConsoleResolution().X /2 , GetConsoleResolution().Y /2);
		GameManager::GetInstance()->mode = GimmickMode::CORLOR;
		break;
	case GimmickMode::WORD:
		stageName = "�ܾ���߱�";
		Gotoxy(GetConsoleResolution().X / 2, GetConsoleResolution().Y / 2);
		GameManager::GetInstance()->mode = GimmickMode::WORD;
		break;

	}
	cout << "�̹� ����������!!! : " <<stageName  << "�Դϴ�." << endl;
	stageIdx++;
	stageIdx = std::clamp(stageIdx, 0, 2);
}

StageSelect::~StageSelect()
{
}
