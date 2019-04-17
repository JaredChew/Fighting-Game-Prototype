#include "logger.h"

Logger::Logger() {

	directory = "log_export.txt";

	logFileRead = std::ifstream(directory.c_str());
	logFileWrite = std::ofstream(directory.c_str());

	checkFile();

	std::cout << "Logger ready" << std::endl;

}

Logger::~Logger() {

	logFileWrite.open(directory.c_str(), std::ios::app);

	logFileWrite << "\nPlease make a copy of this file you wish to save this log.";
	logFileWrite << "\nThe next runtime of of the application will re-write the contents of this file." << std::endl;

	logFileWrite.close();

	std::cout << "\nLogger system shut down" << std::endl;
	std::cout << "All logs dumpped at: " << directory.c_str() << std::endl;

}

void Logger::checkFile() {

	if (logFileRead.is_open()) {

		std::remove(directory.c_str());

		logFileWrite.open(directory.c_str(), std::ios::app);
		logFileWrite << "\n" << std::endl;
		logFileWrite.close();

	}

}

std::string Logger::getDateTime() {

	// https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono //

	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

	return ss.str();

}

void Logger::writeLog(char* logMsg) {

	logFileWrite.open(directory.c_str(), std::ios::app);

	logFileWrite << "[MESSAGE] " << getDateTime() << ":	";

	logFileWrite << logMsg << std::endl;

	//std::cout << logMsg << std::endl;

	logFileWrite.close();

}

void Logger::infoLog(char* infoMsg) {

	logFileWrite.open(directory.c_str(), std::ios::app);

	logFileWrite << "[INFO] " << getDateTime() << ":	";

	logFileWrite << infoMsg << std::endl;

	//std::cout << infoMsg << std::endl;

	logFileWrite.close();

}

void Logger::debugLog(char* dbugMsg) {

	logFileWrite.open(directory.c_str(), std::ios::app);

	logFileWrite << "[DEBUG] " << getDateTime() << ":	";

	logFileWrite << dbugMsg << std::endl;

	//std::cout << dbugMsg << std::endl;

	logFileWrite.close();

}

void Logger::warningLog(char* wrngMsg) {

	logFileWrite.open(directory.c_str(), std::ios::app);

	logFileWrite << "[WARNING] " << getDateTime() << ":	";

	logFileWrite << wrngMsg << std::endl;

	//std::cerr << wrngMsg << std::endl;

	logFileWrite.close();

}

void Logger::errorLog(char* errMsg) {

	logFileWrite.open(directory.c_str(), std::ios::app);

	logFileWrite << "[ERROR] " << getDateTime() << ":	";

	logFileWrite << errMsg << std::endl;

	//std::cerr << errMsg << std::endl;

	logFileWrite.close();

}