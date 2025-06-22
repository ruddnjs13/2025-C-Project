#include "GimmickManager.h"

GimmickManager* GimmickManager::Instance = nullptr;



GimmickManager::GimmickManager()
	: wordGimmick(nullptr)
	, colorGimmick(nullptr)
{
	wordGimmick = new WordGimmick;
	colorGimmick = new ColorGimmick;
}

GimmickManager::~GimmickManager()
{
}

void GimmickManager::ShuffleAnswer(vector<char>& answer)
{
	if (mode == GimmickMode::CORLOR)
	{
		vector<int> arr = {2,3,4,5,6,7,8};
		std::random_device rd;
		std::mt19937 generator(rd());
		std::shuffle(arr.begin(), arr.end(),rd);

	    answer.clear();
		for (int i = 0; i < 5; i++)
		{
			answer.push_back(arr[i]);
		}
	}
	else
	{
	}
}

void GimmickManager::CheckAnswer(vector<char> submit)
{
	bool isSelect = true;

	if (mode == GimmickMode::CORLOR)
	{
		for (int i = 0; i < MAX_ANSWER_LENGTH; ++i)
		{
			if (answer[i] != submit[i])
			{
				for (int j = 0; j < Color_HEIGHT; ++j)
				{
					SetColor(COLOR::RED, COLOR::BLACK);
					Gotoxy(RESULT_X + (Color_WIDTH * i), RESULT_Y + j);
					cout << "¡á¡á¡á¡á¡á¡á" << "\n";

				}
				SetColor(COLOR::WHITE, COLOR::BLACK);
				isSelect = false;
			}
			else
			{
				for (int j = 0; j < Color_HEIGHT; ++j)
				{
					SetColor(COLOR::GREEN, COLOR::BLACK);
					Gotoxy(RESULT_X + (Color_WIDTH * i), RESULT_Y + j);
					cout << "¡á¡á¡á¡á¡á¡á" << "\n";

				}
				SetColor(COLOR::WHITE, COLOR::BLACK);
			}
		}
	}
	else if (mode == GimmickMode::WORD)
	{
	}

	if (isSelect)
	{
		// ¸ÂÀ½
	}
	else
	{
		Sleep(2000);
		Reset();

	}
}

void GimmickManager::Init()
{
	colorGimmick->Init();
	wordGimmick->Init();

	ShuffleAnswer(answer);
}

void GimmickManager::Render()
{
	if (mode == GimmickMode::CORLOR)
	{
		colorGimmick->GimmickRender();
	}
	else
	{
		wordGimmick->GimmickRender();
	}
}

void GimmickManager::Reset()
{
	colorGimmick->Init();
	system("cls");
}

void GimmickManager::RnderResult()
{

}
