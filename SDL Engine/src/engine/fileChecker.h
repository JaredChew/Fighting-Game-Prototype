#pragma once

#include <iostream>
#include <fstream>

#include "logger.h"
#include "../game.h"

/*

						NOTE

	To be used indipendently without creating its object

*/

struct FileList {

	int totalFilesCount = TOTAL_FILES;

	std::string directory;
	std::ifstream file;

	void font();
	void graphic();
	void music();
	void sound();

	void result();

	FileList(Logger& log);

	private:
		Logger& log;

};

/* ###  ###  ###  ###  ###  ### */

FileList::FileList(Logger& log) : log(log) { }

void FileList::result() {

	if (totalFilesCount != TOTAL_FILES) {

		std::cerr << "\nIncomplete files, the program will now terminate" << std::endl;

		std::cout << "Press ENTER to exit" << std::endl;
		std::cin.get();

		exit(-1);

	}

	std::cout << "All files validated" << std::endl;

}

void FileList::font() {

	// ** FONT FILES ** //

	directory = "asset/font/";

	file = std::ifstream((directory + "consolas.ttf").c_str());
	if (!file.is_open()) {
		std::cerr << "Missing file: " << directory + "consolas.ttf" << std::endl;
		totalFilesCount--;
	}

}

void FileList::graphic() {

	// ** GRAPHIC FILES ** //

	directory = "asset/graphic/";

}

void FileList::music() {

	// ** MUSIC FILES ** //

	directory = "asset/music/";

}

void FileList::sound() {

	// ** SOUND FILES ** //

	directory = "asset/sound/";

}

void fileChecker(Logger& log) {

	FileList* fl = new FileList(log);

	fl->font();
	fl->graphic();
	fl->music();
	fl->sound();

	fl->result();

	delete fl;

}