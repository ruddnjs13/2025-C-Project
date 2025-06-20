#pragma once

#include "Console.h"


class GimmickBase
{
public:
	int slotIdx = 0;
	int start_x = GetConsoleResolution().X/5*2;
	int start_y = 1;

public :
	virtual void Init() = 0;
	virtual void Interact(char btnType) = 0;
	virtual void GimmickRender() = 0;
	virtual void Submit() = 0;
};

