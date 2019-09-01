#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <curl/easy.h>
class DownloadScore
{
public:
	DownloadScore();
	~DownloadScore();
	std::stringstream date;
	std::stringstream download(const std::string& url);
	std::vector<int> scoreToVector(std::stringstream &score, std::stringstream &date);
private:
	CURL* curl;
};

