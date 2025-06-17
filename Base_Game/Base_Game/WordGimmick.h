#pragma once

#include <map>
#include "GimmickBase.h"
using std::map;

class WordGimmick : GimmickBase
{
public : 
	map<char, char[15][15]> showTexts;
	virtual void Interact(char btnType) override;
	virtual void GimmickRender() override;
};

