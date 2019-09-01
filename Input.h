#pragma once
#include <vector>
#include <iostream>
#include <string>
class Input
{
public:
	Input();
	~Input();
	std::string userInput();
	std::vector<int> strToVec(std::string &str);
	std::vector<int> checkInput();
	std::vector<int> checkUserScore(std::vector<int> &userNumbers, std::vector<int> &scoreVec);
};