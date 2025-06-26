#include "ShootingGimmick.h"

void ShootingGimmick::Init()
{
	beforeTime = time(nullptr);
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


}
void ShootingGimmick::RenderUI()
{
	Gotoxy(POINT_UI_X[0], POINT_UI_Y);


	Gotoxy(POINT_UI_X[1], POINT_UI_Y);
}
void ShootingGimmick::Update()
{
	int sec = time(nullptr) - beforeTime;
	
	if (sec >= spawnInterval)
	{
		int maxTries = 30;
		while (maxTries--)
		{
			if (SpawnTarget())
			{
				beforeTime = time(nullptr);
				break;
			}
		}
		if (maxTries <= 0)
			beforeTime = time(nullptr);
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
			if (playerIdx == 0)
			{
				p1_point++;
			}
			else
			{
				p2_point++;
			}

			Target* temp = targets[i];
			targets.erase(targets.begin() + i);
			temp->ClearSpawnMap(spawnMap);
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
