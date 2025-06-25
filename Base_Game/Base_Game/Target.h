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
			 L"  ����  "
			,L"������"
			,L"������"
			,L"������"
			,L"  ����  "
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

