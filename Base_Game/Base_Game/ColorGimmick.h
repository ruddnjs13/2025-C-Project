#pragma once
#include "GimmickBase.h"
#include "Console.h"
#include "Enums.h"

class ColorGimmick : public GimmickBase 
{
public:
	int colorIndex = 0;
	char color[5] = { };
	ColorGimickTile colorGimickTile[5] = {};
public:
	virtual void Interact(char btnType) override;
	virtual void GimmickRender() override;

};