#include "ShootingGimmick.h"

void ShootingGimmick::Init()
{
}

void ShootingGimmick::Interact(char btnType)
{

}

void ShootingGimmick::GimmickRender()
{
	for (auto target : targets)
	{
		target.Render();
	}
}
void ShootingGimmick::Update()
{
	auto startTime = std::chrono::system_clock::now();
	int Sec = 0;

	if (Sec <= countdownSeconds)
	{
		auto endTime = std::chrono::system_clock::now();
		auto sec = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
		if (sec.count() > Sec)
		{
			Sec++;
			while (true)
			{
				if (SpawnTarget())
					break;
			}
		}
	}
}
void ShootingGimmick::CheckHitTargets(POS hitPos)
{
	for (auto iter = targets.begin(); iter != targets.end(); ++iter)
	{
		if (iter->CheckHit(hitPos))
		{
			// 점수 올리기
			targets.erase(iter); 
			return;
		}
	}
}

bool ShootingGimmick::SpawnTarget()
{
	int dx[] = { -1,0,1 };
	int dy[] = { 1,0,-1 };

	std::mt19937 rng(std::random_device{}());

	std::uniform_int_distribution<int> rangeX(4, MAP_WIDTH-5);
	int x = rangeX(rng);

	std::uniform_int_distribution<int> rangeY(4, MAP_HEIGHT - 4);
	int y = rangeY(rng);

	POS spawnPos = { x,y };

	if (x > MAP_WIDTH - 4 || x < 4 || y > MAP_HEIGHT - 4 || y < 4)
		return false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (spawnMap[dx[i]][dy[j]] >= 0)
				return false;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (spawnMap[dx[i]][dy[j]] >= 0)
				spawnMap[dx[i]][dy[j]] = 1;
		}
	}

	targets.push_back(Target(spawnPos));
	return true;
}
