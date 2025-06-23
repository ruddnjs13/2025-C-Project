#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <string>


class AsciiAlphabets
{
public:
	std::map<char, std::vector<std::wstring>> asciiMap;
	AsciiAlphabets();
};

