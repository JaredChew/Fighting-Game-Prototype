#include "game.h"

Game::Game(GameWindow& wnd, Logger& log) : wnd(wnd), log(log) {

	// ** Initialise everything here ** //

	generalCounter = 0;
	currentState = NULL;
	nextState = NULL;
	returnedState = HM_SPLASHSCREEN;

	std::cout << "\nInitialising Game object" << std::endl;

	//Initialise essential obbjects
	kbd = new Keyboard();
	std::cout << "Keyboard initialised" << std::endl;

	mse = new Mouse();
	std::cout << "Mouse initialised" << std::endl;

	rseMngr = new ResourcesManager(wnd);
	std::cout << "ResourcesManager initialised" << std::endl;

	audio = new Audio(wnd);
	std::cout << "Audio initialised" << std::endl;

	physics = new Physics();
	std::cout << "Physics initialised" << std::endl;

	font = new Font(wnd);
	font->setFont(rseMngr->loadFont("asset/font/Consolas.ttf", 100));
	
	splashScreen = nullptr;

	splashScreenDuration = 120;

	homeScreen = nullptr;

}

Game::~Game() { 

	// ** Destroy all objects' data ** //

	std::cout << "\nDestroying game objects" << std::endl;

	std::cout << "\nDeleting ResourcesManager object" << std::endl;
	delete rseMngr;
	rseMngr = nullptr;

	std::cout << "Deleting Physics object" << std::endl;
	delete physics;
	physics = nullptr;

	std::cout << "Deleting Audio object" << std::endl;
	delete audio;
	audio = nullptr;

	std::cout << "Deleting FPS counter Font object" << std::endl;
	delete font;
	font = nullptr;

	//Splashscreen
	if (splashScreen != nullptr) {
		SDL_DestroyTexture(splashScreen);
		splashScreen = nullptr;
	}

	//Home screen
	if (homeScreen != nullptr) {
		SDL_DestroyTexture(homeScreen);
		homeScreen = nullptr;

		Mix_FreeMusic(bgm);
		bgm = nullptr;

		Mix_FreeChunk(enterSound);
		enterSound = nullptr;
	}

	std::cout << "\nGame object cleaned" << std::endl;

}

void Game::displayFPScounter() {

	// ** Displays average fps ** //

	if (wnd.getDisplayFPS()) {
		
		//Display in-game top left

		fpsText << "FPS: " << wnd.getAverageFPS();

		font->displayFont(fpsText.str(), 10, 10, 50, 15, 0, 0, 0);

		fpsText.str("");
		fpsText.clear();

	}

}

int Game::displaySplashScreen() {

	SDL_RenderCopy(wnd.renderer, splashScreen, NULL, &splashScreenRect);

	generalCounter++;

	if (kbd->isPressed(SDL_SCANCODE_RETURN) || generalCounter == splashScreenDuration) {
		generalCounter = 0;
		return HM_HOME_SCREEN;
	}

	return NULL;

}

int Game::displayHomeScreen() {

	if (generalCounter == 0) {

		audio->music.playMusic(bgm, -1);
		generalCounter++;

	}

	SDL_RenderCopy(wnd.renderer, homeScreen, NULL, &homeScreenRect);

	if (kbd->isPressed(SDL_SCANCODE_RETURN)) {

		audio->sound.playSound(enterSound, 0);
		generalCounter = 0;

		return MM_MAIN_MENU;

	}

	return NULL;

}

void Game::objectDestroyer() {

	switch (currentState) {

		case HM_SPLASHSCREEN:

			SDL_DestroyTexture(splashScreen);
			splashScreen = nullptr;

			break;

		case HM_HOME_SCREEN:

			SDL_DestroyTexture(homeScreen);
			homeScreen = nullptr;

			Mix_FreeMusic(bgm);
			bgm = nullptr;

			Mix_FreeChunk(enterSound);
			enterSound = nullptr;

			break;

		case MM_MAIN_MENU:

			delete mainMenu;
			mainMenu = nullptr;

			break;

		case CSM_CHARACTER_SELECT_MENU: //MM_NEW_GAME

			delete charSlct;
			charSlct = nullptr;

			break;

		case TEST_STAGE:

			delete testStage;
			testStage = nullptr;

			break;

	}

}

void Game::objectInitialiser() {

	switch (nextState) {

		case HM_SPLASHSCREEN:

			splashScreen = rseMngr->loadTextureImage("asset/graphic/splashScreen.png");
			SDL_QueryTexture(splashScreen, NULL, NULL, &splashScreenRect.w, &splashScreenRect.h);
			splashScreenRect.x = 0;
			splashScreenRect.y = 0;

			break;

		case HM_HOME_SCREEN:

			homeScreen = rseMngr->loadTextureImage("asset/graphic/homeScreen.png");
			SDL_QueryTexture(homeScreen, NULL, NULL, &homeScreenRect.w, &homeScreenRect.h);
			splashScreenRect.x = 0;
			splashScreenRect.y = 0;

			bgm = rseMngr->loadMusic("asset/music/menuTest.wav"); //menuTest.wav
			enterSound = rseMngr->loadSound("asset/sound/homeMenuEnter.wav");

			break;

		case MM_MAIN_MENU:

			mainMenu = new MainMenu(wnd, *rseMngr, *kbd, *mse, *audio);

			break;

		case CSM_CHARACTER_SELECT_MENU: //MM_NEW_GAME

			charSlct = new CharacterSelect(wnd, *rseMngr, *kbd, *mse, *audio);

			break;

		case TEST_STAGE:

			testStage = new TestStage(wnd, *rseMngr, *kbd, *mse, *audio);

			break;

		case QUIT_GAME:

			wnd.setGameLoop(false);

			break;

	}

	objectDestroyer();

	currentState = nextState;
	nextState = NULL;

}

void Game::currentStateManager() {

	switch (currentState) {

		case HM_SPLASHSCREEN:
			returnedState = displaySplashScreen();
			break;

		case HM_HOME_SCREEN:
			returnedState = displayHomeScreen();
			break;

		case MM_MAIN_MENU:
			returnedState = mainMenu->flow();
			break;

		case MM_CONTINUE_GAME:
			//Continues last save file
			break;

		case CSM_CHARACTER_SELECT_MENU: //MM_NEW_GAME
			returnedState = charSlct->flow();
			break;

		case TEST_STAGE:
			returnedState = testStage->flow();
			break;

	}

}

void Game::gameFlow() {

	// ** Insert game's functions code here ** //

	currentStateManager();

	if (returnedState != NULL) {

		nextState = returnedState;
		returnedState = NULL;

		objectInitialiser();

	}

	kbd->update();

	displayFPScounter();
	
}