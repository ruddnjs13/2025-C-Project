#pragma once
#include "Console.h"
#include "TypeDefines.h"
#include <vector>
#include <string>
#include "Map.h"
#include <cmath>

class Target
{
public:
	std::vector<std::wstring> target
		= {
			 L"  ¡á¡á¡á  "
			,L"¡á¡à¡à¡à¡á"
			,L"¡á¡à¡á¡à¡á"
			,L"¡á¡à¡à¡à¡á"
			,L"  ¡á¡á¡á  "
	};

	int dx[5] = { -2,-1,0,1,2 };
	int dy[5] = { 2,1,0,-1,-2 };
public:
	POS myPos;

	int spawnTime;
	int lifeTime = 0;

public:
	Target() = default;
	Target(POS initPos);
	~Target();

	Target(const Target&) = default;
	Target(Target&&) = default;
	Target& operator=(const Target&) = default;
	Target& operator=(Target&&) = default;

	void Update();
	void Render();
	void Clear();
	void ClearSpawnMap(char spawnMap[MAP_HEIGHT][MAP_WIDTH]);
	bool CheckHit(POS hitPos);
};

