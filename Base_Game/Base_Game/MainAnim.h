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
	vector<COLOR> colorArr{};
	void BalloonAsciiInit();
public:
	MainAnim();
	void SetRandomColor();
	void MainAnimPlay();
	void AnimUpdate();
	void AnimRender();
};

