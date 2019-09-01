#include "pch.h"
#include "Display.h"


Display::Display()
{
}


Display::~Display()
{
}

void Display::displayScore(std::vector<int> &scoreVec)
{	
	std::sort(scoreVec.begin(), scoreVec.end());
	for (auto &el : scoreVec) {
		std::cout << el << std::endl;
	}
}

void Display::displayDate(const std::string &date)
{
	std::cout << "Last draw was: " << date << std::endl;
}

void Display::displayChecked(const std::vector<int> &checkedScore)
{
	std::cout << "You have " << checkedScore.size() << " hits." << std::endl;
	//std::sort(checkedScore.begin(), checkedScore.end());
	if (checkedScore.size() > 0) {
		for (auto &el : checkedScore) {
			std::cout << el << " ";
		}
	}
}
