#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

class Logger {

private:
	std::string directory;

	std::ifstream logFileRead;
	std::ofstream logFileWrite;

private:
	void checkFile();

	std::string getDateTime();

public:
	Logger();
	~Logger();

	void writeLog(char* logMsg);
	void infoLog(char* infoMsg);
	void debugLog(char* dbugMsg);
	void warningLog(char* wrngMsg);
	void errorLog(char* errMsg);

};