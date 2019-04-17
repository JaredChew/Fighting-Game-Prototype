#include "gameWindow.h"

GameWindow::GameWindow(Logger& log) : log(log) {

	// ** Initialise variables and objects here ** //

	gameloop = true;

	//Frame limiter
	
	frameStart = 0;

	maxFPS = 60;
	frameDelay = 1000 / maxFPS;
	frameTicks = 0;

	limitFrame = true;

	//FPS Counter
	showFPS = true;

	avgFPS = 0.0f;
	countedFrames = 0.0f;
	currentTicks = 0.0f;
	prevTicks = 0.0f;
	frameTimeAverage = 0.0f;

	currentFrame = 0;

	//Window and screen

	width = 1280;
	height = 720;

	windowSetting = SDL_WINDOW_SHOWN;
	renderSetting = SDL_RENDERER_ACCELERATED;

	if (init() == -1) {
		gameloop = false;
	}

}

GameWindow::~GameWindow() {

	// ** Destroy window object here ** //

	std::cout << "\nDestroying SDL renderer" << std::endl;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	std::cout << "Destroying SDL surface" << std::endl;
	SDL_FreeSurface(backbuffer);
	backbuffer = nullptr;

	std::cout << "Destroying SDL window" << std::endl;
	SDL_DestroyWindow(window);
	window = nullptr;

	std::cout << "Quitting SDL libraries" << std::endl;
	SDL_Quit();

}

int GameWindow::init() {

	// ** Initialise window here ** //

	std::cout << "\nInitialising SDL..." << std::endl;
	log.writeLog("Initialising SDL");

	//Initialise SDL drivers
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Quit();
		std::cerr << "Failed to intialise SDL drivers" << std::endl;
		log.errorLog("Failed to intialise SDL drivers");
		return -1;
	}

	std::cout << "SDL drivers initialised" << std::endl;
	log.writeLog("SDL drivers initialised");

	//Create main window
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowSetting);

	if (window == nullptr) {
		SDL_Quit();
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		log.errorLog("Failed to intialise SDL window");
		return -1;
	}

	SDL_SetWindowResizable(window, SDL_TRUE);

	//Apply window into backbuffer/surface
	backbuffer = SDL_GetWindowSurface(window);
	std::cout << "SDL window initialised" << std::endl;
	log.writeLog("SDL window initialised");

	//Initialise renderer
	renderer = SDL_CreateRenderer(window, -1, renderSetting);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	if (renderer == nullptr) {
		SDL_Quit();
		std::cerr << "Failed to intialise SDL renderer" << std::endl;
		log.errorLog("Failed to intialise SDL renderer");
		return -1;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	std::cout << "SDL renderer initialised" << std::endl;
	log.writeLog("SDL renderer initialised");

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	return 0;

}

void GameWindow::eventHandler() {

	// ** Set window event listener here ** //

	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT) { //Listen to 'X' button of window being clicked
			std::cout << "\nPlayer exited game" << std::endl;
			log.writeLog("Player exited game");
			gameloop = false;
		}

	}

}

void GameWindow::fpsCounter() {

	// ** Calculate average FPS ** //

	countedFrames = 0;
	frameTimeAverage = 0;

	currentFrame++;

	currentTicks = (float) SDL_GetTicks();

	frameTimes[currentFrame % FPS_NUM_SAMPLES] = (float) currentTicks - prevTicks;

	prevTicks = currentTicks;

	if (currentFrame < FPS_NUM_SAMPLES) { countedFrames = (float) currentFrame; }
	else { countedFrames = FPS_NUM_SAMPLES; }

	for (int i = 0; i < countedFrames; i++) {

		frameTimeAverage += frameTimes[i];

	}

	frameTimeAverage /= countedFrames;

	if (frameTimeAverage > 0) { avgFPS = 1000.0f / frameTimeAverage; }
	else { avgFPS = 60.0f; }

	//sprintf_s(dynamicWindowTitle, "Honey Badger Engine | FPS: %d", (int) avgFPS); //C-Style

	dynamicWindowTitle << WINDOW_TITLE << " | FPS: " << (int)avgFPS;

	SDL_SetWindowTitle(window, dynamicWindowTitle.str().c_str());

	dynamicWindowTitle.str("");
	dynamicWindowTitle.clear();

}

void GameWindow::fpsLimiter() {

	// ** Limit Frame rate ** //

	frameTicks = SDL_GetTicks() - frameStart;

	if (limitFrame && frameDelay> frameTicks) {
		SDL_Delay(frameDelay - frameTicks);
	}

}

void GameWindow::update() {

	// ** Set window updating here ** //

	//Update the window to display changes (texture)
	SDL_RenderPresent(renderer);

	//Update the window to display changes (surface)
	//SDL_UpdateWindowSurface(window);

	//Apply default background colour
	SDL_FillRect(backbuffer, NULL, 0);

	fpsLimiter();

	SDL_RenderClear(renderer);

	frameStart = SDL_GetTicks();

}

void GameWindow::forceQuit() {

	// ** Use when needed to force quit the program ** //

	std::cerr << "\n\nA critical error has occured, the program will now terminate" << std::endl;
	log.errorLog("A critical error has occured, the program will now terminate");

	std::cout << "Press ENTER to exit" << std::endl;
	std::cin.get();

	SDL_Quit();

	exit(-1);

}

// ** FPS limiter ** //

void GameWindow::setMaxFPS(int maxFPS) {
	
	if (maxFPS != 0) {
		this->maxFPS = maxFPS;
		frameDelay = 1000 / maxFPS;
		limitFrame = true;
	}
	else {
		limitFrame = false;
	}

}

int GameWindow::getMaxFPS() { return maxFPS; }

bool GameWindow::getIsFrameLimited() { return limitFrame; }

// ** Game loop ** //

void GameWindow::setGameLoop(bool gameLoop) { this->gameloop = gameLoop; }

bool GameWindow::getGameLoop() { return gameloop; }

// ** Window dimensions ** //

void GameWindow::setResolution(int width, int height) {

	this->width = width;
	this->height = height;

	SDL_RenderSetLogicalSize(renderer, width, height);

	SDL_SetWindowSize(window, width, height);

}

void GameWindow::setWidth(int width) { this->width = width; }

int GameWindow::getWidth() { return width; }

void GameWindow::setHeight(int height) { this->height = height; }

int GameWindow::getHeight() { return height; }

// ** Screen Settings ** //

void GameWindow::setFullScreen(bool fullscreen) {

	if (fullscreen) {
		windowSetting = SDL_WINDOW_FULLSCREEN;
	}
	else {
		windowSetting = SDL_WINDOW_SHOWN;
	}

	if (SDL_SetWindowFullscreen(window, windowSetting) == -1) {
		SDL_Quit();
		std::cerr << "\nSwitching Window Setting Error: " << SDL_GetError() << std::endl;
		log.errorLog("Failed to switch window from either fullscreen or windowed");
		forceQuit();
	}

}

bool GameWindow::getFullScreen() {

	if (windowSetting == SDL_WINDOW_FULLSCREEN) {
		return true;
	}
	
	return false;

}

// ** Render type ** //

void GameWindow::setRenderType(int renderType) {

	if (renderType == 0) {
		renderSetting = SDL_RENDERER_SOFTWARE;
	}
	else if (renderType == 1) {
		renderSetting = SDL_RENDERER_ACCELERATED;
	}
	else if (renderType == 2) {
		renderSetting = SDL_RENDERER_PRESENTVSYNC;
	}

	std::cout << "\nDestroying old SDL renderer" << std::endl;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	renderer = SDL_CreateRenderer(window, -1, renderSetting);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	if (renderer == nullptr) {
		SDL_Quit();
		std::cerr << "Failed to re-create SDL renderer" << std::endl;
		log.errorLog("Failed to re-create SDL renderer");
		forceQuit();
	}

	std::cout << "New SDL renderer has been created  with switched rendering context" << std::endl;
	log.errorLog("New SDL renderer has been created  with switched rendering context");

}

int GameWindow::getRenderType() {

	if (renderSetting == SDL_RENDERER_SOFTWARE) {
		return 0;
	}
	else if (renderSetting == SDL_RENDERER_ACCELERATED) {
		return 1;
	}
	else if (renderSetting == SDL_RENDERER_PRESENTVSYNC) {
		return 2;
	}

	return -1;

}

// ** In-game FPS counter ** //

void GameWindow::setDisplayFPS(bool showFPS) { this->showFPS = showFPS; }

bool GameWindow::getDisplayFPS() { return showFPS; }

int GameWindow::getAverageFPS() { return (int)avgFPS; }