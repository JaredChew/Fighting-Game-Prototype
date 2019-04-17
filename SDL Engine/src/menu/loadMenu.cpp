#include "loadMenu.h"

LoadMenu::LoadMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	buttonSelect = NULL;
	returnState = NULL;

	buttonNavigation = LSM_SAVE_SLOT_1;
	buttonSection = SAVE_SLOTS;
	oldButtonSection = buttonSection;

	buttonSpacing = (int)(0.008 * wnd.getWidth());//25;
	
	//Background
	background = rseMngr.loadTextureImage("asset/graphic/loadMenu.png");
	SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
	backgroundRect.x = 0;
	backgroundRect.y = 0;
	backgroundRect.w = (int) (((float) wnd.getWidth() / (float) backgroundRect.w) * backgroundRect.w);
	backgroundRect.h = (int) (((float)wnd.getHeight() / (float) backgroundRect.h) * backgroundRect.h);

	//Save slot
	for (int i = 0; i < MAX_SAVE_SLOTS; i++) {

		saveSlot[i] = rseMngr.loadTextureImage("asset/graphic/saveSlot.png");
		SDL_QueryTexture(saveSlot[i], NULL, NULL, &saveSlotRect[i].w, &saveSlotRect[i].h);
		saveSlotRect[i].w = (int)(((float)wnd.getWidth() / (float)saveSlotRect[i].w) * saveSlotRect[i].w);
		saveSlotRect[i].h = (int)(((float)wnd.getHeight() / (float)saveSlotRect[i].h) * saveSlotRect[i].h);

	}

	std::cout << saveSlotRect[0].w << std::endl;

	//Save slot first row
	saveSlotRect[0].x = (int) (0.027 * wnd.getWidth());
	saveSlotRect[0].y = (int) (0.04 * wnd.getHeight());

	saveSlotRect[1].x = (int) (saveSlotRect[0].x + saveSlotRect[0].w + buttonSpacing);
	saveSlotRect[1].y = (int) (saveSlotRect[0].y);

	saveSlotRect[2].x = (int) (saveSlotRect[1].x + saveSlotRect[1].w + buttonSpacing);
	saveSlotRect[2].y = (int) (saveSlotRect[1].y);

	saveSlotRect[3].x = (int) (saveSlotRect[2].x + saveSlotRect[2].w + buttonSpacing);
	saveSlotRect[3].y = (int) (saveSlotRect[2].y);

	//Save slot second row
	saveSlotRect[4].x = (int) (saveSlotRect[0].x);
	saveSlotRect[4].y = (int) (saveSlotRect[0].y + saveSlotRect[0].h + buttonSpacing);

	saveSlotRect[5].x = (int) (saveSlotRect[4].x + saveSlotRect[4].w + buttonSpacing);
	saveSlotRect[5].y = (int) (saveSlotRect[4].y);

	saveSlotRect[6].x = (int) (saveSlotRect[5].x + saveSlotRect[5].w + buttonSpacing);
	saveSlotRect[6].y = (int) (saveSlotRect[5].y);

	saveSlotRect[7].x = (int) (saveSlotRect[6].x + saveSlotRect[6].w + buttonSpacing);
	saveSlotRect[7].y = (int) (saveSlotRect[6].y);

	//Buttons
	prevPageButton = rseMngr.loadTextureImage("asset/graphic/prevPageButton.png");
	SDL_QueryTexture(prevPageButton, NULL, NULL, &prevPageButtonRect.w, &prevPageButtonRect.h);
	prevPageButtonRect.x = (int)(0.29 * wnd.getWidth());
	prevPageButtonRect.y = (int)(0.73 * wnd.getHeight());
	prevPageButtonRect.w = (int)(((float)wnd.getWidth() / (float)prevPageButtonRect.w) * prevPageButtonRect.w);
	prevPageButtonRect.h = (int)(((float)wnd.getHeight() / (float)prevPageButtonRect.h) * prevPageButtonRect.h);

	returnButton = rseMngr.loadTextureImage("asset/graphic/returnButton.png");
	SDL_QueryTexture(returnButton, NULL, NULL, &returnButtonRect.w, &returnButtonRect.h);
	returnButtonRect.x = (int)(prevPageButtonRect.x + prevPageButtonRect.w + buttonSpacing);
	returnButtonRect.y = (int)prevPageButtonRect.y;
	returnButtonRect.w = (int)(((float)wnd.getWidth() / (float)returnButtonRect.w) * returnButtonRect.w);
	returnButtonRect.h = (int)(((float)wnd.getHeight() / (float)returnButtonRect.h) * returnButtonRect.h);

	nextPageButton = rseMngr.loadTextureImage("asset/graphic/nextPageButton.png");
	SDL_QueryTexture(nextPageButton, NULL, NULL, &nextPageButtonRect.w, &nextPageButtonRect.h);
	nextPageButtonRect.x = (int)(returnButtonRect.x + returnButtonRect.w + buttonSpacing);
	nextPageButtonRect.y = (int)returnButtonRect.y;
	nextPageButtonRect.w = (int)(((float)wnd.getWidth() / (float)nextPageButtonRect.w) * nextPageButtonRect.w);
	nextPageButtonRect.h = (int)(((float)wnd.getHeight() / (float)nextPageButtonRect.h) * nextPageButtonRect.h);

	//Hover
	buttonHover = rseMngr.loadTextureImage("asset/graphic/hoverButton.png");
	SDL_QueryTexture(buttonHover, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
	buttonHoverRect.x = NULL;
	buttonHoverRect.y = NULL;
	buttonHoverRect.w = (int)(((float)wnd.getWidth() / (float)buttonHoverRect.w) * buttonHoverRect.w);
	buttonHoverRect.h = (int)(((float)wnd.getHeight() / (float)buttonHoverRect.h) * buttonHoverRect.h);

	saveSlotHover = rseMngr.loadTextureImage("asset/graphic/saveSlotHover.png");
	SDL_QueryTexture(saveSlotHover, NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
	saveSlotHoverRect.x = saveSlotRect[0].x;
	saveSlotHoverRect.y = saveSlotRect[0].y;
	saveSlotHoverRect.w = (int)(((float)wnd.getWidth() / (float)saveSlotHoverRect.w) * saveSlotHoverRect.w);
	saveSlotHoverRect.h = (int)(((float)wnd.getHeight() / (float)saveSlotHoverRect.h) * saveSlotHoverRect.h);

	//Sounds
	selectSound = rseMngr.loadSound("asset/sound/buttonNavigate.wav");
	navigateSound = rseMngr.loadSound("asset/sound/buttonSelect_test.wav");

}

LoadMenu::~LoadMenu() {

	//Background
	SDL_DestroyTexture(background);
	background = nullptr;

	//Buttons
	SDL_DestroyTexture(returnButton);
	returnButton = nullptr;

	SDL_DestroyTexture(prevPageButton);
	prevPageButton = nullptr;

	SDL_DestroyTexture(nextPageButton);
	nextPageButton = nullptr;

	//Save slot
	for (int i = 0; i < MAX_SAVE_SLOTS; i++) {

		SDL_DestroyTexture(saveSlot[i]);
		saveSlot[i] = nullptr;

	}

	//Hover images
	SDL_DestroyTexture(buttonHover);
	buttonHover = nullptr;

	SDL_DestroyTexture(saveSlotHover);
	saveSlotHover = nullptr;

	//Sounds
	Mix_FreeChunk(selectSound);
	selectSound = nullptr;

	Mix_FreeChunk(navigateSound);
	navigateSound = nullptr;

}

void LoadMenu::buttonSectionManager() {

	switch (buttonSection) {

		case SAVE_SLOTS:
			buttonNavigation = LSM_SAVE_SLOT_1;
			break;

		case BUTTONS:
			buttonNavigation = LSM_PREV_PAGE;
			break;

	}

	oldButtonSection = buttonSection;

}

void LoadMenu::buttonNavigationManager() {

	//Control button navigation within number of buttons
	switch (buttonNavigation) {

		case LSM_SAVE_SLOT_1:
		case LSM_SAVE_SLOT_2:
		case LSM_SAVE_SLOT_3:
		case LSM_SAVE_SLOT_4:
		case LSM_SAVE_SLOT_5:
		case LSM_SAVE_SLOT_6:
		case LSM_SAVE_SLOT_7:
		case LSM_SAVE_SLOT_8:
			buttonSection = SAVE_SLOTS;
			break;

		case LSM_NEXT_PAGE:
		case LSM_PREV_PAGE:
		case LSM_RETURN_BUTTON:
			buttonSection = BUTTONS;
			break;

	}

	oldButtonSection = buttonSection;

}

void LoadMenu::buttonSelectManager() {

	switch (buttonSelect) {

	case LSM_SAVE_SLOT_1:
		//Load save 1;
		break;

	case LSM_SAVE_SLOT_2:
		//Load save 2;
		break;

	case LSM_SAVE_SLOT_3:
		//Load save 3;
		break;

	case LSM_SAVE_SLOT_4:
		//Load save 4;
		break;

	case LSM_SAVE_SLOT_5:
		//Load save 5;
		break;

	case LSM_SAVE_SLOT_6:
		//Load save 6;
		break;

	case LSM_SAVE_SLOT_7:
		//Load save 7;
		break;

	case LSM_SAVE_SLOT_8:
		//Load save 8;
		break;

	case LSM_PREV_PAGE:
		//Move to previous 8 save slots;
		break;

	case LSM_RETURN_BUTTON:
		returnState = MM_MAIN_MENU;
		break;

	case LSM_NEXT_PAGE:
		//Move to next 8 save slots
		break;

	}

	buttonSelect = NULL;

}

void LoadMenu::buttonHoverManager() {

	//Button section controller
	if (buttonSection != oldButtonSection) {
		buttonSectionManager();
	}
	else {
		buttonNavigationManager();
	}

	//Change hover button to appropriate button
	switch (buttonNavigation) {

	case LSM_SAVE_SLOT_1:
		SDL_QueryTexture(saveSlot[0], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[0].x;
		saveSlotHoverRect.y = saveSlotRect[0].y;
		//saveSlotHoverRect.w = saveSlotRect[0].w;
		//saveSlotHoverRect.h = saveSlotRect[0].h;
		break;

	case LSM_SAVE_SLOT_2:
		SDL_QueryTexture(saveSlot[1], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[1].x;
		saveSlotHoverRect.y = saveSlotRect[1].y;
		//saveSlotHoverRect.w = saveSlotRect[1].w;
		//saveSlotHoverRect.h = saveSlotRect[1].h;
		break;

	case LSM_SAVE_SLOT_3:
		SDL_QueryTexture(saveSlot[2], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[2].x;
		saveSlotHoverRect.y = saveSlotRect[2].y;
		//saveSlotHoverRect.w = saveSlotRect[2].w;
		//saveSlotHoverRect.h = saveSlotRect[2].h;
		break;

	case LSM_SAVE_SLOT_4:
		SDL_QueryTexture(saveSlot[3], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[3].x;
		saveSlotHoverRect.y = saveSlotRect[3].y;
		//saveSlotHoverRect.w = saveSlotRect[3].w;
		//saveSlotHoverRect.h = saveSlotRect[3].h;
		break;

	case LSM_SAVE_SLOT_5:
		SDL_QueryTexture(saveSlot[4], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[4].x;
		saveSlotHoverRect.y = saveSlotRect[4].y;
		//saveSlotHoverRect.w = saveSlotRect[4].w;
		//saveSlotHoverRect.h = saveSlotRect[4].h;
		break;

	case LSM_SAVE_SLOT_6:
		SDL_QueryTexture(saveSlot[5], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[5].x;
		saveSlotHoverRect.y = saveSlotRect[5].y;
		//saveSlotHoverRect.w = saveSlotRect[5].w;
		//saveSlotHoverRect.h = saveSlotRect[5].h;
		break;

	case LSM_SAVE_SLOT_7:
		SDL_QueryTexture(saveSlot[6], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[6].x;
		saveSlotHoverRect.y = saveSlotRect[6].y;
		//saveSlotHoverRect.w = saveSlotRect[6].w;
		//saveSlotHoverRect.h = saveSlotRect[6].h;
		break;

	case LSM_SAVE_SLOT_8:
		SDL_QueryTexture(saveSlot[7], NULL, NULL, &saveSlotHoverRect.w, &saveSlotHoverRect.h);
		saveSlotHoverRect.x = saveSlotRect[7].x;
		saveSlotHoverRect.y = saveSlotRect[7].y;
		//saveSlotHoverRect.w = saveSlotRect[7].w;
		//saveSlotHoverRect.h = saveSlotRect[7].h;
		break;

	case LSM_PREV_PAGE:
		SDL_QueryTexture(prevPageButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = prevPageButtonRect.x;
		buttonHoverRect.y = prevPageButtonRect.y;
		//buttonHoverRect.w = prevPageButtonRect.w;
		//buttonHoverRect.h = prevPageButtonRect.h;
		break;

	case LSM_NEXT_PAGE:
		SDL_QueryTexture(nextPageButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = nextPageButtonRect.x;
		buttonHoverRect.y = nextPageButtonRect.y;
		//buttonHoverRect.w = nextPageButtonRect.w;
		//buttonHoverRect.h = nextPageButtonRect.h;
		break;

	case LSM_RETURN_BUTTON:
		SDL_QueryTexture(returnButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = returnButtonRect.x;
		buttonHoverRect.y = returnButtonRect.y;
		//buttonHoverRect.w = returnButtonRect.w;
		//buttonHoverRect.h = returnButtonRect.h;
		break;

	}

}

void LoadMenu::buttonControl() {

	if (kbd.isPressed(SDL_SCANCODE_RETURN)) {
		audio.sound.playSound(selectSound, 0);
		buttonSelect = buttonNavigation;
	}
	else if (kbd.isPressed(SDL_SCANCODE_A) || kbd.isPressed(SDL_SCANCODE_LEFT)) {
		audio.sound.playSound(navigateSound, 0);
		buttonNavigation--;
	}
	else if (kbd.isPressed(SDL_SCANCODE_D) || kbd.isPressed(SDL_SCANCODE_RIGHT)) {
		audio.sound.playSound(navigateSound, 0);
		buttonNavigation++;
	}
	else if (kbd.isPressed(SDL_SCANCODE_W) || kbd.isPressed(SDL_SCANCODE_UP)) {
		audio.sound.playSound(navigateSound, 0);
		buttonSection--;
	}
	else if (kbd.isPressed(SDL_SCANCODE_S) || kbd.isPressed(SDL_SCANCODE_DOWN)) {
		audio.sound.playSound(navigateSound, 0);
		buttonSection++;
	}
	else if (kbd.isPressed(SDL_SCANCODE_BACKSPACE) || kbd.isPressed(SDL_SCANCODE_ESCAPE)) {
		audio.sound.playSound(selectSound, 0);
		returnState = MM_MAIN_MENU;
	}

	//Up-down controls
	if (buttonSection < SAVE_SLOTS) {
		buttonSection = BUTTONS;
	}
	else if (buttonSection > BUTTONS) {
		buttonSection = SAVE_SLOTS;
	}

	//Left-right controls
	if (buttonNavigation > LSM_NEXT_PAGE) {
		buttonNavigation = LSM_SAVE_SLOT_1;
	}
	else if (buttonNavigation < LSM_SAVE_SLOT_1) {
		buttonNavigation = LSM_NEXT_PAGE;
	}

	buttonHoverManager();

}

void LoadMenu::display() {

	//Background
	SDL_RenderCopy(wnd.renderer, background, NULL, &backgroundRect);

	//Save slots
	for (int i = 0; i < MAX_SAVE_SLOTS; i++) {

		SDL_RenderCopy(wnd.renderer, saveSlot[i], NULL, &saveSlotRect[i]);

	}

	//Buttons
	SDL_RenderCopy(wnd.renderer, prevPageButton, NULL, &prevPageButtonRect);
	SDL_RenderCopy(wnd.renderer, returnButton, NULL, &returnButtonRect);
	SDL_RenderCopy(wnd.renderer, nextPageButton, NULL, &nextPageButtonRect);

	//Hover
	if (buttonSection == SAVE_SLOTS) {
		SDL_RenderCopy(wnd.renderer, saveSlotHover, NULL, &saveSlotHoverRect);
	}
	else if (buttonSection == BUTTONS) {
		SDL_RenderCopy(wnd.renderer, buttonHover, NULL, &buttonHoverRect);
	}

}

int LoadMenu::flow() {

	display();

	buttonControl();

	if (buttonSelect != NULL) {
		buttonSelectManager();
	}

	return returnState;

}