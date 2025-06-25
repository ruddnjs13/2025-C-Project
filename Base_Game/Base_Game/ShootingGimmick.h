#pragma once
#include <vector>
#include "Map.h";
#include "Player.h";
#include "Target.h";
#include <random>
#include <chrono>

using namespace std::chrono;


class ShootingGimmick : GimmickBase
{
private:
	const int countdownSeconds = 30;
	int remainingTime = countdownSeconds;


private:
	vector<Target> targets;
public:

	char spawnMap[MAP_HEIGHT][MAP_WIDTH] = { 0, };


	void Init() override;

	void Interact(char btnType) override;

	void GimmickRender() override;

	void Update();

	void CheckHitTargets(POS hitPos);

	bool SpawnTarget();

};

