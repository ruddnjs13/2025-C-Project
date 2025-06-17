#pragma once
#include "GimmickBase.h"

class ColorGimmick : public GimmickBase 
{
public:
	virtual void Interact(char btnType) override;
	virtual void GimmickRender() override;

};