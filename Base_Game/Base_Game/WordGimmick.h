#pragma once

#include <map>
#include "GimmickBase.h"
using std::map;

class WordGimmick : GimmickBase
{
public:
	char word[5] = { 'A','A','A','A','A' };
	map<char, char[15][15]> showTexts;
public : 
	virtual void Interact(char btnType) override;
	virtual void GimmickRender() override;
};

