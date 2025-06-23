#pragma once
const int WORD_HEIGHT = 6;
const int WORD_WIDTH = 18;

#include "GimmickBase.h"
#include "AsciiAlphabets.h"
#include<vector>
#include <fstream>
#include<io.h>
#include<fcntl.h>

using std::vector;

class WordGimmick : public GimmickBase
{
public:
	char submitArr[5] = { 'A','A','A','A','A' };
	AsciiAlphabets asciiAlphabets;
public : 
	virtual void Init() override;
	virtual void Interact(char btnType) override;
	virtual void GimmickRender() override;
};




