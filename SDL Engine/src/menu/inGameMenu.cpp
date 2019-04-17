#include "inGameMenu.h"

InGameMenu::InGameMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	buttonNavigation = IGM_RESUME_GAME;
	currentState = NULL;
	returnState = NULL;
	nextState = NULL;

	buttonSpacing = (int)(0.008 * wnd.getWidth());
	
	//Background
	background = rseMngr.loadTextureImage("asset/graphic/inGameMenu.png");
	SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	//Buttons
	resumeButton = rseMngr.loadTextureImage("asset/graphic/resumeButton.png");
	SDL_QueryTexture(resumeButton, NULL, NULL, &resumeButtonRect.w, &resumeButtonRect.h);
	resumeButtonRect.x = (int)(0.05 * wnd.getWidth());
	resumeButtonRect.y = (int)(0.07 * wnd.getHeight());

	saveButton = rseMngr.loadTextureImage("asset/graphic/saveGameButton.png");
	SDL_QueryTexture(saveButton, NULL, NULL, &saveButtonButton.w, &saveButtonButton.h);
	saveButtonButton.x = (int)(resumeButtonRect.x);
	saveButtonButton.y = (int)(resumeButtonRect.y + resumeButtonRect.h + buttonSpacing);

	loadButton = rseMngr.loadTextureImage("asset/graphic/loadGameButton2.png");
	SDL_QueryTexture(loadButton, NULL, NULL, &loadButtonRect.w, &loadButtonRect.h);
	loadButtonRect.x = (int)(resumeButtonRect.x);
	loadButtonRect.y = (int)(saveButtonButton.y + saveButtonButton.h + buttonSpacing);

	settingsButton = rseMngr.loadTextureImage("asset/graphic/settingsMenuButton2.png");
	SDL_QueryTexture(settingsButton, NULL, NULL, &settingsButtonRect.w, &settingsButtonRect.h);
	settingsButtonRect.x = (int)(resumeButtonRect.x);
	settingsButtonRect.y = (int)(loadButtonRect.y + loadButtonRect.h + buttonSpacing);

	mainMenuButton = rseMngr.loadTextureImage("asset/graphic/mainMenuButton.png");
	SDL_QueryTexture(mainMenuButton, NULL, NULL, &mainMenuButtonRect.w, &mainMenuButtonRect.h);
	mainMenuButtonRect.x = (int)(resumeButtonRect.x);
	mainMenuButtonRect.y = (int)(settingsButtonRect.y + settingsButtonRect.h + buttonSpacing);

	quitButton = rseMngr.loadTextureImage("asset/graphic/quitGameButton2.png");
	SDL_QueryTexture(quitButton, NULL, NULL, &quitButtonRect.w, &quitButtonRect.h);
	quitButtonRect.x = (int)(resumeButtonRect.x);
	quitButtonRect.y = (int)(mainMenuButtonRect.y + mainMenuButtonRect.h + buttonSpacing);

	//Hover
	buttonHover = rseMngr.loadTextureImage("asset/graphic/hoverButton.png");
	SDL_QueryTexture(resumeButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
	buttonHoverRect.x = (int) resumeButtonRect.x;
	buttonHoverRect.y = (int) resumeButtonRect.y;

	//Sound
	selectSound = rseMngr.loadSound("asset/sound/buttonNavigate.wav");
	navigateSound = rseMngr.loadSound("asset/sound/buttonSelect_test.wav");

}

InGameMenu::~InGameMenu() {

	//Background
	SDL_DestroyTexture(background);
	background = nullptr;

	//Buttons
	SDL_DestroyTexture(resumeButton);
	resumeButton = nullptr;

	SDL_DestroyTexture(saveButton);
	saveButton = nullptr;

	SDL_DestroyTexture(loadButton);
	loadButton = nullptr;

	SDL_DestroyTexture(settingsButton);
	settingsButton = nullptr;

	SDL_DestroyTexture(mainMenuButton);
	mainMenuButton = nullptr;

	SDL_DestroyTexture(quitButton);
	quitButton = nullptr;

	//Hover
	SDL_DestroyTexture(buttonHover);
	buttonHover = nullptr;

	//Sound
	Mix_FreeChunk(selectSound);
	selectSound = nullptr;

	Mix_FreeChunk(navigateSound);
	navigateSound = nullptr;

	std::cout << "\nIn game menu destroyed" << std::endl;

}

void InGameMenu::initialiser() {

	switch (nextState) {

	case IGM_SAVE_MENU:
		returnState = CSM_CHARACTER_SELECT_MENU;
		break;

	case IGM_LOAD_MENU:
		loadMenu = new LoadMenu(wnd, rseMngr, kbd, mse, audio);
		break;

	case IGM_SETTINGS_MENU:
		settingsMenu = new SettingsMenu(wnd, rseMngr, kbd, mse, audio);
		break;

	}

	navigation = nextState;
	nextState = NULL;

}

void InGameMenu::destroyer() {

	switch (currentState) {

	case IGM_SAVE_MENU:
		//delete saveMenu;
		//saveMenu = nullptr;

	case IGM_LOAD_MENU:
		delete loadMenu;
		loadMenu = nullptr;
		break;

	case IGM_SETTINGS_MENU:
		delete settingsMenu;
		settingsMenu = nullptr;
		break;

	}

	navigation = currentState;
	currentState = NULL;

}

void InGameMenu::buttonHoverManager() {

	//Change hover button to appropriate button
	switch (buttonNavigation) {

	case IGM_RESUME_GAME:
		SDL_QueryTexture(resumeButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resumeButtonRect.x;
		buttonHoverRect.y = resumeButtonRect.y;
		//buttonHoverRect.w = resumeButtonRect.w;
		//buttonHoverRect.h = resumeButtonRect.h;
		break;

	case IGM_SAVE_MENU:
		SDL_QueryTexture(saveButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = saveButtonButton.x;
		buttonHoverRect.y = saveButtonButton.y;
		//buttonHoverRect.w = saveButtonButton.w;
		//buttonHoverRect.h = saveButtonButton.h;
		break;

	case IGM_LOAD_MENU:
		SDL_QueryTexture(loadButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = loadButtonRect.x;
		buttonHoverRect.y = loadButtonRect.y;
		//buttonHoverRect.w = loadButtonRect.w;
		//buttonHoverRect.h = loadButtonRect.h;
		break;

	case IGM_SETTINGS_MENU:
		SDL_QueryTexture(settingsButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = settingsButtonRect.x;
		buttonHoverRect.y = settingsButtonRect.y;
		//buttonHoverRect.w = settingsButtonRect.w;
		//buttonHoverRect.h = settingsButtonRect.h;
		break;

	case IGM_MAIN_MENU:
		SDL_QueryTexture(mainMenuButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = mainMenuButtonRect.x;
		buttonHoverRect.y = mainMenuButtonRect.y;
		//buttonHoverRect.w = mainMenuButtonRect.w;
		//buttonHoverRect.h = mainMenuButtonRect.h;
		break;

	case IGM_QUIT_GAME:
		SDL_QueryTexture(quitButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = quitButtonRect.x;
		buttonHoverRect.y = quitButtonRect.y;
		//buttonHoverRect.w = quitButtonRect.w;
		//buttonHoverRect.h = quitButtonRect.h;
		break;

	}

}

void InGameMenu::buttonControls() {

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
		returnState = IGM_RESUME_GAME;
	}

	//Control button navigation within number of buttons
	if (buttonNavigation < IGM_RESUME_GAME) {
		buttonNavigation = IGM_QUIT_GAME;
	}
	else if (buttonNavigation > IGM_QUIT_GAME) {
		buttonNavigation = IGM_RESUME_GAME;
	}

	buttonHoverManager();

}

void InGameMenu::display() {

	//Background
	SDL_RenderCopy(wnd.renderer, background, NULL, &backgroundRect);

	//Buttons
	SDL_RenderCopy(wnd.renderer, buttonHover, NULL, &buttonHoverRect);

	SDL_RenderCopy(wnd.renderer, resumeButton, NULL, &resumeButtonRect);
	SDL_RenderCopy(wnd.renderer, saveButton, NULL, &saveButtonButton);
	SDL_RenderCopy(wnd.renderer, loadButton, NULL, &loadButtonRect);
	SDL_RenderCopy(wnd.renderer, settingsButton, NULL, &settingsButtonRect);
	SDL_RenderCopy(wnd.renderer, mainMenuButton, NULL, &mainMenuButtonRect);
	SDL_RenderCopy(wnd.renderer, quitButton, NULL, &quitButtonRect);

	buttonControls();

}

int InGameMenu::flow() {

	switch (navigation) {

	case IGM_RESUME_GAME:
		returnState = IGM_RESUME_GAME;
		break;

	case IGM_SAVE_MENU:
		//currentState = saveMenu->flow();
		break;

	case IGM_LOAD_MENU:
		currentState = loadMenu->flow();
		break;

	case IGM_SETTINGS_MENU:
		currentState = settingsMenu->flow();
		break;

	case IGM_MAIN_MENU:
		returnState = IGM_MAIN_MENU;
		break;

	case IGM_QUIT_GAME:
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