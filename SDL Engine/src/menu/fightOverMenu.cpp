#include "fightOverMenu.h"

FightOverMenu::FightOverMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	buttonNavigation = FOM_REMATCH;
	nextState = NULL;

	buttonSpacing = (int)(0.008 * wnd.getWidth());

	//Background
	background = rseMngr.loadTextureImage("asset/graphic/fightOverMenu.png");
	SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	//Buttons
	rematchButton = rseMngr.loadTextureImage("asset/graphic/rematchButton.png");
	SDL_QueryTexture(rematchButton, NULL, NULL, &rematchButtonRect.w, &rematchButtonRect.h);
	rematchButtonRect.x = (int)(0.43 * wnd.getWidth());
	rematchButtonRect.y = (int)(0.6 * wnd.getHeight());

	changeCharacterButton = rseMngr.loadTextureImage("asset/graphic/changeCharacterButton.png");
	SDL_QueryTexture(changeCharacterButton, NULL, NULL, &changeCharacterButtonRect.w, &changeCharacterButtonRect.h);
	changeCharacterButtonRect.x = (int)(0.375 * wnd.getWidth());
	changeCharacterButtonRect.y = rematchButtonRect.y + rematchButtonRect.h + buttonSpacing;

	mainMenuButton = rseMngr.loadTextureImage("asset/graphic/mainMenuButton2.png");
	SDL_QueryTexture(mainMenuButton, NULL, NULL, &mainMenuButtonRect.w, &mainMenuButtonRect.h);
	mainMenuButtonRect.x = (int)(0.42 * wnd.getWidth());
	mainMenuButtonRect.y = changeCharacterButtonRect.y + changeCharacterButtonRect.h + buttonSpacing;

	//Hover
	buttonHover = rseMngr.loadTextureImage("asset/graphic/hoverButton.png");
	SDL_QueryTexture(buttonHover, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
	buttonHoverRect.x = rematchButtonRect.x;
	buttonHoverRect.y = rematchButtonRect.y;

	//Sound
	selectSound = rseMngr.loadSound("asset/sound/buttonNavigate.wav");
	navigateSound = rseMngr.loadSound("asset/sound/buttonSelect_test.wav");

}

FightOverMenu::~FightOverMenu() {

	//Background
	SDL_DestroyTexture(background);
	background = nullptr;

	//Buttons
	SDL_DestroyTexture(rematchButton);
	rematchButton = nullptr;

	SDL_DestroyTexture(changeCharacterButton);
	changeCharacterButton = nullptr;

	SDL_DestroyTexture(mainMenuButton);
	mainMenuButton = nullptr;

	//Hover
	SDL_DestroyTexture(buttonHover);
	buttonHover = nullptr;

	//Sounds
	Mix_FreeChunk(selectSound);
	selectSound = nullptr;

	Mix_FreeChunk(navigateSound);
	navigateSound = nullptr;

}

void FightOverMenu::buttonSelectManager() {

	switch (nextState) {

	case FOM_REMATCH:
		returnState = FOM_REMATCH;
		break;

	case FOM_CHANGE_CHARACTER:
		returnState = FOM_CHANGE_CHARACTER;
		break;

	case FOM_MAIN_MENU:
		returnState = FOM_MAIN_MENU;
		break;

	}

}

void FightOverMenu::buttonHoverManager() {

	//Change hover button to appropriate button
	switch (buttonNavigation) {

	case FOM_REMATCH:
		SDL_QueryTexture(rematchButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = rematchButtonRect.x;
		buttonHoverRect.y = rematchButtonRect.y;
		//buttonHoverRect.w = rematchButtonRect.w;
		//buttonHoverRect.h = rematchButtonRect.h;
		break;

	case FOM_CHANGE_CHARACTER:
		SDL_QueryTexture(changeCharacterButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = changeCharacterButtonRect.x;
		buttonHoverRect.y = changeCharacterButtonRect.y;
		//buttonHoverRect.w = changeCharacterButtonRect.w;
		//buttonHoverRect.h = changeCharacterButtonRect.h;
		break;

	case FOM_MAIN_MENU:
		SDL_QueryTexture(mainMenuButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = mainMenuButtonRect.x;
		buttonHoverRect.y = mainMenuButtonRect.y;
		//buttonHoverRect.w = mainMenuButtonRect.w;
		//buttonHoverRect.h = mainMenuButtonRect.h;
		break;

	}

}

void FightOverMenu::buttonControls() {

	if (kbd.isPressed(SDL_SCANCODE_RETURN)) {
		audio.sound.playSound(selectSound, 0);
		nextState = buttonNavigation;
	}
	else if (kbd.isPressed(SDL_SCANCODE_W) || kbd.isPressed(SDL_SCANCODE_UP)) {
		buttonNavigation--;
	}
	else if (kbd.isPressed(SDL_SCANCODE_S) || kbd.isPressed(SDL_SCANCODE_DOWN)) {
		buttonNavigation++;
	}

	//Control button navigation within number of buttons
	if (buttonNavigation < FOM_REMATCH) {
		buttonNavigation = FOM_MAIN_MENU;
	}
	else if (buttonNavigation > FOM_MAIN_MENU) {
		buttonNavigation = FOM_REMATCH;
	}

	buttonHoverManager();

}

void FightOverMenu::display() {

	//Background
	SDL_RenderCopy(wnd.renderer, background, NULL, &backgroundRect);

	//Buttons
	SDL_RenderCopy(wnd.renderer, buttonHover, NULL, &buttonHoverRect);

	SDL_RenderCopy(wnd.renderer, rematchButton, NULL, &rematchButtonRect);
	SDL_RenderCopy(wnd.renderer, changeCharacterButton, NULL, &changeCharacterButtonRect);
	SDL_RenderCopy(wnd.renderer, mainMenuButton, NULL, &mainMenuButtonRect);

	buttonControls();

}

int FightOverMenu::flow() {

	display();

	if (nextState != NULL) {
		buttonSelectManager();
	}

	return returnState;

}