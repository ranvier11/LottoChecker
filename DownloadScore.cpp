#include "pch.h"
#include "DownloadScore.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
	std::string data((const char*)ptr, (size_t)size * nmemb);
	*((std::stringstream*) stream) << data << std::endl;
	return size * nmemb;
}

DownloadScore::DownloadScore()
{
	curl = curl_easy_init();
}


DownloadScore::~DownloadScore()
{
	curl_easy_cleanup(curl);
}

std::stringstream DownloadScore::download(const std::string& url)\
{
	std::stringstream out;
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
	
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);

	CURLcode res = curl_easy_perform(curl);
	/* Check for errors */
	if (res != CURLE_OK) {
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));
	}
	return out;
}

std::vector<int> DownloadScore::scoreToVector(std::stringstream & score, std::stringstream & date)
{
	int i = 0;
	int temp;
	std::vector<int> scoreVector;
	while (score >> temp) {
		if (i < 3) {
			date << temp;
		}
		else {
			scoreVector.push_back(temp);
		}
		++i;
		//std::cout << temp<<std::endl;
	}
	return scoreVector;
}
