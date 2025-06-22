const int Color_HEIGHT = 6;
const int Color_WIDTH  = 16;
#pragma once
#include "GimmickBase.h"
#include "Enums.h"

class ColorGimmick : public GimmickBase 
{
public:
	int colorIndex = 0;
	COLOR submitArr[5] = { COLOR::GRAY,COLOR::GRAY ,COLOR::GRAY ,COLOR::GRAY ,COLOR::GRAY };
	char colorGimickTile[5] = {};
public:
	virtual void Init() override;
	virtual void Interact(char btnType) override;
	virtual void GimmickRender() override;
	virtual void Submit() override;
};