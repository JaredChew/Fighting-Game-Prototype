#include <iostream>
#include <SDL.h>

#include "logger.h"
#include "gameWindow.h"
#include "../game.h"
#include "fileChecker.h"

int main(int argc, char* args[]) {

	std::cout << "Initialising logger\n" << std::endl;

	Logger* log = new Logger();

	fileChecker(*log);

	GameWindow* wnd = new GameWindow(*log);
	Game* game = new Game(*wnd, *log);

	std::cout << "\nRunning game loop" << std::endl;

	//Game loop
	while (wnd->getGameLoop()) {

		// ** Direct flow between game and window here ** //

		game->gameFlow();

		wnd->fpsCounter();
		wnd->update();
		wnd->eventHandler();

	}

	delete game;
	game = nullptr;

	delete wnd;
	wnd = nullptr;

	delete log;
	log = nullptr;

	std::cout << "\n\nDone! Press ENTER to exit" << std::endl;
	std::cin.get();

	return 0;

}

/*

					NOTE

	To run the 32bit version of the engine,
	replace the current DLLs with the 32bit
	DLLs from the x86 folder 

*/