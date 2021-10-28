#pragma once

#include <string>
#include <time.h>
#include <chrono>
#include <ctime>
#include <iostream>


std::string getCurrentDate() {
	std::string s;
	char timeBuffer[30];
	auto start = std::chrono::system_clock::now();
	auto cDate = std::chrono::system_clock::to_time_t(start);
	ctime_s(timeBuffer, sizeof(timeBuffer), &cDate);

	s = timeBuffer;

	return s;	
}

