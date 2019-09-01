// checkLotto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Input.h"
#include "DownloadScore.h"
#include "Display.h"


int main()
{
	
	DownloadScore download;
	std::stringstream score = download.download("https://app.lotto.pl/wyniki/?type=dl");
	std::vector<int> scoreVec = download.scoreToVector(score, download.date);
	std::vector<int> userNumbers;
	
	std::string scoreDate = download.date.str();
	Display display;
	display.displayDate(scoreDate);
	display.displayScore(scoreVec);
	Input input;
	userNumbers = input.checkInput();
	//display.displayScore(input.checkInput());
	display.displayChecked(input.checkUserScore(userNumbers, scoreVec));
	
}
