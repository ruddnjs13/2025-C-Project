#include "ShootingGimmick.h"

void ShootingGimmick::Init()
{
	startTime = time(nullptr);
	beforeTime = time(nullptr);
	p1_point = 0;
	p2_point = 0;
}

void ShootingGimmick::Interact(char btnType)
{

}

void ShootingGimmick::GimmickRender()
{
	for (auto& target : targets)
	{
		target->Render();
	}

	RenderUI();


}
void ShootingGimmick::RenderUI()
{

	Gotoxy(POINT_UI_X[0], POINT_UI_Y);
	cout << "Player1 : " << p1_point;

	Gotoxy(POINT_UI_X[1], POINT_UI_Y);
	cout << "Player2 : " << p2_point;

	Gotoxy(POINT_UI_X[1]+30, POINT_UI_Y);
	cout << "Timer : " << (countdownSeconds-(time(nullptr) - startTime)) << " ";
}
void ShootingGimmick::Update()
{
	int sec = time(nullptr) - beforeTime;
	
	if (sec >= spawnInterval)
	{
		int spawnCnt = 0;
		while (true)
		{
			if (SpawnTarget())
			{
				spawnCnt++;
				beforeTime = time(nullptr);
				if(spawnCnt >= 2)
					break;
			}
		}
	}

	if (time(nullptr) - startTime > countdownSeconds)
	{
		// p1_point와 p2_point를 비교해서 승점 올려주기

		if (p1_point > p2_point) 
		{
			SceneManager::GetInstance()->player1Win++;
			SceneManager::GetInstance()->currentScene = Scene::STAGESLECT;
		}
		else if(p1_point < p2_point)
		{
			SceneManager::GetInstance()->player2Win++;
			SceneManager::GetInstance()->currentScene = Scene::STAGESLECT;
		}
		else
		{
			Init();
			SceneManager::GetInstance()->currentScene = Scene::WINCHECK;
		}
	}

	for (int i = 0; i < targets.size(); i++)
	{
		if (targets[i]->lifeTime >= 2)
		{
			Target* temp = targets[i];
			targets.erase(targets.begin() + i);
			temp->ClearSpawnMap(spawnMap);

			delete temp;
		}
	}

	for (auto target : targets)
	{
		target->Update();
	}
}
void ShootingGimmick::CheckHitTargets(int playerIdx, POS hitPos)
{
	for (int i = 0; i < targets.size(); i++)
	{
		if (targets[i]->CheckHit(hitPos))
		{
			Target* temp = targets[i];
			temp->ClearSpawnMap(spawnMap);
			if (playerIdx == 0)
			{
				p1_point++;
			}
			else
			{
				p2_point++;
			}

			targets.erase(targets.begin() + i);
			delete temp;
		}
	}
}

bool ShootingGimmick::SpawnTarget()
{
	int dx[] = { -2,-1,0,1,2 };
	int dy[] = { 2,1,0,-1,-2 };

	std::mt19937 rng(std::random_device{}());

	std::uniform_int_distribution<int> rangeX(4, MAP_WIDTH-5);
	int x = rangeX(rng);

	std::uniform_int_distribution<int> rangeY(4, MAP_HEIGHT - 4);
	int y = rangeY(rng);

	POS spawnPos = { x,y };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (spawnMap[spawnPos.x + dx[i]][spawnPos.y + dy[j]] >= 1)
				return false;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			spawnMap[spawnPos.x+ dx[i]][spawnPos.y + dy[j]] = 1;
		}
	}

	targets.push_back(new Target({ spawnPos }));
	return true;
}
