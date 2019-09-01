#include "pch.h"
#include "Input.h"
#include <iostream>
#include <sstream>


Input::Input()
{
}


Input::~Input()
{
}

std::string Input::userInput()
{	
	std::string userNumbers;
	std::cout << "Enter Your 6 numbers separated with space: ";
	std::getline(std::cin, userNumbers);
	return userNumbers;
}

std::vector<int> Input::strToVec(std::string &str)
{
	int temp;
	std::stringstream ss(str);
	std::vector<int> scoreVec;
	while ( ss >> temp) {
		scoreVec.push_back(temp);
	}
	return scoreVec;
}

std::vector<int> Input::checkInput()
{	
	bool checked = false;
	std::string userNumbers = Input::userInput();
	std::vector<int> inputVec = Input::strToVec(userNumbers);
	int x = 0;
	while (!checked) {
		for ( auto &el : inputVec) {
			if (el > 0 && el < 50) {
				++x;
			}
		}
		checked = true;
	}
	if (x == 6) {
		return inputVec;
	}
	else {
		std::cout << "Wrong numbers!" << std::endl;
		Input::checkInput();
	}
}

std::vector<int> Input::checkUserScore(std::vector<int> &userNumbers, std::vector<int> &scoreVec)
{
	std::vector<int>checkedScore;
	for (auto &el : userNumbers)
	{
		for (const auto &score : scoreVec) {
			if (el == score) {
				checkedScore.push_back(el);
			}
		}
	}
	return checkedScore;
}
