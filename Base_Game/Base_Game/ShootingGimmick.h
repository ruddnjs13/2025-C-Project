#pragma once
#include "Console.h"
#include "TypeDefines.h"
#include <vector>
#include "GimmickBase.h"
#include "Target.h"

class Target;

const int POINT_UI_X[] = {0, GetConsoleResolution().X/2};
const int POINT_UI_Y = 0;


class ShootingGimmick : public GimmickBase
{
private:
	const int countdownSeconds = 60;
	unsigned int beforeTime;
	unsigned int startTime;
	int spawnInterval = 2;

	int p1_point = 0;
	int p2_point = 0;

public:
	std::vector<Target*> targets;
public:

	char spawnMap[MAP_HEIGHT][MAP_WIDTH] = { 0, };

	void Init() override;

	void Interact(char btnType) override;

	void GimmickRender() override;

	void RenderUI();

	void Update();

	void CheckHitTargets(int playerIdx,POS hitPos);

	bool SpawnTarget();

};

