#pragma once
const int WORD_HEIGHT = 8;
const int WORD_WIDTH = 24;

#include <map>
#include "GimmickBase.h"
#include<io.h>
#include<fcntl.h>
#include<vector>
#include <fstream>

using std::map;
using std::vector;

class WordGimmick : public GimmickBase
{
public:
	char word[5] = { 'A','B','C','X','Q' };
	map<char, vector<string>> asciiMap;
public : 
	virtual void Init() override;
	virtual void Interact(char btnType) override;
	virtual void GimmickRender() override;
};

