#pragma once
#include<iostream>
#include <random>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <unordered_map>
#include <vector>
#include"Console.h"

using std::vector;

class MainAnim
{
	std::unordered_map<int,vector<wstring>> BalloonAscii;
	vector<COLOR> colorArr{ COLOR::BLUE,COLOR::GREEN , COLOR::RED,COLOR::MINT,COLOR::YELLOW,COLOR::GRAY };
	void BalloonAsciiInit();
public:
	MainAnim();
	void MainAnimPlay();
	void AnimUpdate();
	void AnimRender();
};

