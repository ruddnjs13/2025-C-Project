#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Map.h"
#include "Console.h"


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
public:
	POS myPos;

public:
	Target(POS initPos);
	~Target();

	void Render();
	void Clear();
	bool CheckHit(POS hitPos);
};

