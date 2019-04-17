#include "mainMenu.h"

MainMenu::MainMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	buttonSpacing = (int)(0.008 * wnd.getWidth());

	navigation = MM_MAIN_MENU;
	currentState = NULL;
	nextState = NULL;
	returnState = NULL;

	buttonNavigation = MM_NEW_GAME;

	//Background image
	background = rseMngr.loadTextureImage("asset/graphic/mainMenu.png");
	SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	//Quit game button
	quitGameButton = rseMngr.loadTextureImage("asset/graphic/quitGameButton.png");

	SDL_QueryTexture(quitGameButton, NULL, NULL, &quitGameButtonRect.w, &quitGameButtonRect.h);
	quitGameButtonRect.x = (int) (0.05 * wnd.getWidth());
	quitGameButtonRect.y = (int) (0.87 * wnd.getHeight());

	//Settings menu button
	settingsMenuButton = rseMngr.loadTextureImage("asset/graphic/settingsMenuButton.png");

	SDL_QueryTexture(settingsMenuButton, NULL, NULL, &settingsMenuButtonRect.w, &settingsMenuButtonRect.h);
	settingsMenuButtonRect.x = (int) (0.05 * wnd.getWidth());
	settingsMenuButtonRect.y = (int) (quitGameButtonRect.y - quitGameButtonRect.h - buttonSpacing);

	//Load game button
	loadGameButton = rseMngr.loadTextureImage("asset/graphic/loadGameButton.png");

	SDL_QueryTexture(loadGameButton, NULL, NULL, &loadGameButtonRect.w, &loadGameButtonRect.h);
	loadGameButtonRect.x = (int) (0.05 * wnd.getWidth());
	loadGameButtonRect.y = (int) (settingsMenuButtonRect.y - settingsMenuButtonRect.h - buttonSpacing);

	//New game button
	newGameButton = rseMngr.loadTextureImage("asset/graphic/newGameButton.png");

	SDL_QueryTexture(newGameButton, NULL, NULL, &newGameButtonRect.w, &newGameButtonRect.h);
	newGameButtonRect.x = (int) (0.05 * wnd.getWidth());
	newGameButtonRect.y = (int) (loadGameButtonRect.y - loadGameButtonRect.h - buttonSpacing);

	//Continue game button
	continueGameButton = rseMngr.loadTextureImage("asset/graphic/continueButton.png");

	SDL_QueryTexture(continueGameButton, NULL, NULL, &continueGameButtonRect.w, &continueGameButtonRect.h);
	continueGameButtonRect.x = (int) (0.05 * wnd.getWidth());
	continueGameButtonRect.y = (int) (newGameButtonRect.y - newGameButtonRect.h - buttonSpacing);

	//Button hover
	buttonHover = rseMngr.loadTextureImage("asset/graphic/hoverButton.png");

	SDL_QueryTexture(buttonHover, NULL, NULL, &hoverRect.w, &hoverRect.h);
	hoverRect.x = newGameButtonRect.x;
	hoverRect.y = newGameButtonRect.y;

	//Sounds
	selectSound = rseMngr.loadSound("asset/sound/buttonNavigate.wav");
	navigateSound = rseMngr.loadSound("asset/sound/buttonSelect_test.wav");

}

MainMenu::~MainMenu() {

	//Objects
	settingsMenu = nullptr;
	loadMenu = nullptr;

	//Background image
	SDL_DestroyTexture(continueGameButton);
	continueGameButton = nullptr;

	//Button images
	SDL_DestroyTexture(newGameButton);
	newGameButton = nullptr;

	SDL_DestroyTexture(loadGameButton);
	loadGameButton = nullptr;

	SDL_DestroyTexture(settingsMenuButton);
	settingsMenuButton = nullptr;

	SDL_DestroyTexture(quitGameButton);
	quitGameButton = nullptr;

	SDL_DestroyTexture(buttonHover);
	buttonHover = nullptr;

	//Sound
	Mix_FreeChunk(selectSound);
	selectSound = nullptr;

	Mix_FreeChunk(navigateSound);
	navigateSound = nullptr;

}

void MainMenu::initialiser() {

	switch (nextState) {

		case MM_CONTINUE_GAME:
			//returnState = MM_CONTINUE_GAME;
			break;

		case MM_NEW_GAME:
			returnState = CSM_CHARACTER_SELECT_MENU;
			break;

		case MM_LOAD_MENU:
			loadMenu = new LoadMenu(wnd, rseMngr, kbd, mse, audio);
			break;

		case MM_SETTINGS_MENU:
			settingsMenu = new SettingsMenu(wnd, rseMngr, kbd, mse, audio);
			break;

	}

	navigation = nextState;
	nextState = NULL;

}

void MainMenu::destroyer() {

	switch (currentState) {

		case MM_LOAD_MENU:
			delete loadMenu;
			loadMenu = nullptr;
			break;

		case MM_SETTINGS_MENU:
			delete settingsMenu;
			settingsMenu = nullptr;
			break;

	}

	navigation = currentState;
	currentState = NULL;

}

void MainMenu::buttonSelectManager() {

	//Change hover button to appropriate button
	switch (buttonNavigation) {

	case MM_CONTINUE_GAME:
		SDL_QueryTexture(continueGameButton, NULL, NULL, &hoverRect.w, &hoverRect.h);
		hoverRect.x = continueGameButtonRect.x;
		hoverRect.y = continueGameButtonRect.y;
		//hoverRect.w = continueGameButtonRect.w;
		//hoverRect.h = continueGameButtonRect.h;
		break;

	case MM_NEW_GAME:
		SDL_QueryTexture(newGameButton, NULL, NULL, &hoverRect.w, &hoverRect.h);
		hoverRect.x = newGameButtonRect.x;
		hoverRect.y = newGameButtonRect.y;
		//hoverRect.w = newGameButtonRect.w;
		//hoverRect.h = newGameButtonRect.h;
		break;

	case MM_LOAD_MENU:
		SDL_QueryTexture(loadGameButton, NULL, NULL, &hoverRect.w, &hoverRect.h);
		hoverRect.x = loadGameButtonRect.x;
		hoverRect.y = loadGameButtonRect.y;
		//hoverRect.w = loadGameButtonRect.w;
		//hoverRect.h = loadGameButtonRect.h;
		break;

	case MM_SETTINGS_MENU:
		SDL_QueryTexture(settingsMenuButton, NULL, NULL, &hoverRect.w, &hoverRect.h);
		hoverRect.x = settingsMenuButtonRect.x;
		hoverRect.y = settingsMenuButtonRect.y;
		//hoverRect.w = settingsMenuButtonRect.w;
		//hoverRect.h = settingsMenuButtonRect.h;
		break;

	case MM_QUIT_GAME:
		SDL_QueryTexture(quitGameButton, NULL, NULL, &hoverRect.w, &hoverRect.h);
		hoverRect.x = quitGameButtonRect.x;
		hoverRect.y = quitGameButtonRect.y;
		//hoverRect.w = quitGameButtonRect.w;
		//hoverRect.h = quitGameButtonRect.h;
		break;

	}

}

void MainMenu::buttonControl() {

	if (kbd.isPressed(SDL_SCANCODE_RETURN)) {
		audio.sound.playSound(selectSound, 0);
		nextState = buttonNavigation;
		initialiser();
	}
	else if (kbd.isPressed(SDL_SCANCODE_W) || kbd.isPressed(SDL_SCANCODE_UP)) {
		audio.sound.playSound(navigateSound, 0);
		buttonNavigation--;
	}
	else if (kbd.isPressed(SDL_SCANCODE_S) || kbd.isPressed(SDL_SCANCODE_DOWN)) {
		audio.sound.playSound(navigateSound, 0);
		buttonNavigation++;
	}
	else if (kbd.isPressed(SDL_SCANCODE_BACKSPACE) || kbd.isPressed(SDL_SCANCODE_ESCAPE)) {
		audio.sound.playSound(selectSound, 0);
		returnState = HM_HOME_SCREEN;
	}

	//Control button navigation within number of buttons
	if (buttonNavigation < MM_CONTINUE_GAME) {
		buttonNavigation = MM_QUIT_GAME;
	}
	else if (buttonNavigation > MM_QUIT_GAME) {
		buttonNavigation = MM_CONTINUE_GAME;
	}

	buttonSelectManager();

}

void MainMenu::display() {

	//Background
	SDL_RenderCopy(wnd.renderer, background, NULL, &backgroundRect);

	//Buttons
	SDL_RenderCopy(wnd.renderer, buttonHover, NULL, &hoverRect);

	SDL_RenderCopy(wnd.renderer, continueGameButton, NULL, &continueGameButtonRect);
	SDL_RenderCopy(wnd.renderer, newGameButton, NULL, &newGameButtonRect);
	SDL_RenderCopy(wnd.renderer, loadGameButton, NULL, &loadGameButtonRect);
	SDL_RenderCopy(wnd.renderer, settingsMenuButton, NULL, &settingsMenuButtonRect);
	SDL_RenderCopy(wnd.renderer, quitGameButton, NULL, &quitGameButtonRect);

	buttonControl();

}

int MainMenu::flow() {

	switch (navigation) {

	case MM_LOAD_MENU:
		currentState = loadMenu->flow();
		break;

	case MM_SETTINGS_MENU:
		currentState = settingsMenu->flow();
		break;

	case MM_QUIT_GAME:
		returnState = QUIT_GAME;
		break;

	default:
		display();

	}

	if (currentState != NULL) {
		destroyer();
	}

	return returnState;

}