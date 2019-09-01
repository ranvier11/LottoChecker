#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class Display
{
public:
	Display();
	~Display();

	void displayScore(std::vector<int> &scoreVec);
	void displayDate(const std::string &date);
	void displayChecked(const std::vector<int> &checkedScore);
};

