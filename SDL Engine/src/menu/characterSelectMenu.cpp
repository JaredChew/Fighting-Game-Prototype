#include "characterSelectMenu.h"

CharacterSelect::CharacterSelect(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	returnState = NULL;

	buttonSelect = NULL;
	buttonNavigation = CSM_FIGHTER_1;

	characterFrameSpacing = (int) (0.023 * wnd.getWidth());
	characterDisplaySpacing = (int) (0.2 * wnd.getWidth());

	playerSelect = PLAYER_1;

	for (int i = 0; i < MAX_PLAYERS; i++) {

		selectedCharacter[i] = NULL;

	}

	//Background
	background = rseMngr.loadTextureImage("asset/graphic/characterSelectMenu.png");
	SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	//Character display
	characterDisplayPreLoad[0] = rseMngr.loadTextureImage("asset/graphic/fighterDisplay.png");
	characterDisplayPreLoad[1] = rseMngr.loadTextureImage("asset/graphic/fighter1_display.png");
	characterDisplayPreLoad[2] = rseMngr.loadTextureImage("asset/graphic/fighter2_display.png");

	characterDisplayLeft = characterDisplayPreLoad[1];
	SDL_QueryTexture(characterDisplayLeft, NULL, NULL, &characterDisplayLeftRect.w, &characterDisplayLeftRect.h);
	characterDisplayLeftRect.x = (int) (0.1 * wnd.getWidth());
	characterDisplayLeftRect.y = (int) (0.2 * wnd.getHeight());

	characterDisplayRight = characterDisplayPreLoad[0];
	SDL_QueryTexture(characterDisplayRight, NULL, NULL, &characterDisplayRightRect.w, &characterDisplayRightRect.h);
	characterDisplayRightRect.x = (int) (characterDisplayLeftRect.x + characterDisplayLeftRect.w + characterDisplaySpacing);
	characterDisplayRightRect.y = (int) characterDisplayLeftRect.y;

	//Character frame
	for (int i = 2; i < MAX_FIGHTERS; i++) {

		characterFrames[i] = rseMngr.loadTextureImage("asset/graphic/fighterLock.png");
		SDL_QueryTexture(characterFrames[i], NULL, NULL, &characterFramesRect[i].w, &characterFramesRect[i].h);

	}

	characterFrames[0] = rseMngr.loadTextureImage("asset/graphic/fighter1_frame.png");
	SDL_QueryTexture(characterFrames[0], NULL, NULL, &characterFramesRect[0].w, &characterFramesRect[0].h);

	characterFrames[1] = rseMngr.loadTextureImage("asset/graphic/fighter2_frame.png");
	SDL_QueryTexture(characterFrames[1], NULL, NULL, &characterFramesRect[1].w, &characterFramesRect[1].h);

	//Character frame first row
	characterFramesRect[0].x = (int) (0.082 * wnd.getWidth());
	characterFramesRect[0].y = (int) (0.6 * wnd.getHeight());

	characterFramesRect[1].x = (int)(characterFramesRect[0].x + characterFramesRect[0].w + characterFrameSpacing);
	characterFramesRect[1].y = (int)(characterFramesRect[0].y);

	characterFramesRect[2].x = (int)(characterFramesRect[1].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[2].y = (int)(characterFramesRect[1].y);

	characterFramesRect[3].x = (int)(characterFramesRect[2].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[3].y = (int)(characterFramesRect[2].y);

	characterFramesRect[4].x = (int)(characterFramesRect[3].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[4].y = (int)(characterFramesRect[3].y);

	characterFramesRect[5].x = (int)(characterFramesRect[4].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[5].y = (int)(characterFramesRect[4].y);

	characterFramesRect[6].x = (int)(characterFramesRect[5].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[6].y = (int)(characterFramesRect[5].y);

	characterFramesRect[7].x = (int)(characterFramesRect[6].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[7].y = (int)(characterFramesRect[6].y);

	characterFramesRect[8].x = (int)(characterFramesRect[7].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[8].y = (int)(characterFramesRect[7].y);

	characterFramesRect[9].x = (int)(characterFramesRect[8].x + characterFramesRect[1].w + characterFrameSpacing);
	characterFramesRect[9].y = (int)(characterFramesRect[8].y);

	//Character frames second row
	characterFramesRect[10].x = (int)(characterFramesRect[0].x);
	characterFramesRect[10].y = (int)(characterFramesRect[0].y + characterFramesRect[0].h + characterFrameSpacing);

	characterFramesRect[11].x = (int)(characterFramesRect[10].x + characterFramesRect[10].w + characterFrameSpacing);
	characterFramesRect[11].y = (int)(characterFramesRect[10].y);

	characterFramesRect[12].x = (int)(characterFramesRect[11].x + characterFramesRect[11].w + characterFrameSpacing);
	characterFramesRect[12].y = (int)(characterFramesRect[11].y);

	characterFramesRect[13].x = (int)(characterFramesRect[12].x + characterFramesRect[12].w + characterFrameSpacing);
	characterFramesRect[13].y = (int)(characterFramesRect[12].y);

	characterFramesRect[14].x = (int)(characterFramesRect[13].x + characterFramesRect[13].w + characterFrameSpacing);
	characterFramesRect[14].y = (int)(characterFramesRect[13].y);

	characterFramesRect[15].x = (int)(characterFramesRect[14].x + characterFramesRect[14].w + characterFrameSpacing);
	characterFramesRect[15].y = (int)(characterFramesRect[14].y);

	characterFramesRect[16].x = (int)(characterFramesRect[15].x + characterFramesRect[15].w + characterFrameSpacing);
	characterFramesRect[16].y = (int)(characterFramesRect[15].y);

	characterFramesRect[17].x = (int)(characterFramesRect[16].x + characterFramesRect[16].w + characterFrameSpacing);
	characterFramesRect[17].y = (int)(characterFramesRect[16].y);

	characterFramesRect[18].x = (int)(characterFramesRect[17].x + characterFramesRect[17].w + characterFrameSpacing);
	characterFramesRect[18].y = (int)(characterFramesRect[17].y);

	characterFramesRect[19].x = (int)(characterFramesRect[18].x + characterFramesRect[18].w + characterFrameSpacing);
	characterFramesRect[19].y = (int)(characterFramesRect[18].y);

	characterFramesRect[20].x = (int)(characterFramesRect[19].x + characterFramesRect[19].w + characterFrameSpacing);
	characterFramesRect[20].y = (int)(characterFramesRect[19].y);

	//Hover
	characterFrameHover = rseMngr.loadTextureImage("asset/graphic/fighterFrameHover.png");
	SDL_QueryTexture(characterFrameHover, NULL, NULL, &characterFrameHoverRect.w, &characterFrameHoverRect.h);
	characterFrameHoverRect.x = characterFramesRect[0].x;
	characterFrameHoverRect.y = characterFramesRect[0].y;

	//Sounds
	selectSound = rseMngr.loadSound("asset/sound/buttonNavigate.wav");
	navigateSound = rseMngr.loadSound("asset/sound/buttonSelect_test.wav");

}

CharacterSelect::~CharacterSelect() {

	//Background
	SDL_DestroyTexture(background);
	background = nullptr;

	//Character display
	SDL_DestroyTexture(characterDisplayLeft);
	characterDisplayLeft = nullptr;

	SDL_DestroyTexture(characterDisplayRight);
	characterDisplayRight = nullptr;

	for (int i = 0; i < MAX_FIGHTERS + 1; i++) {

		if (characterDisplayPreLoad[i] != NULL) { //Dont know if I can check with nullptr as SDL_Texture* is a C code
			SDL_DestroyTexture(characterDisplayPreLoad[i]);
			characterDisplayPreLoad[i] = nullptr;
		}

	}

	//Character frame
	for (int i = 0; i < MAX_FIGHTERS; i++) {

		SDL_DestroyTexture(characterFrames[i]);
		characterFrames[i] = nullptr;

	}

	//Hover
	SDL_DestroyTexture(characterFrameHover);
	characterFrameHover = nullptr;

	//Sounds
	Mix_FreeChunk(selectSound);
	selectSound = nullptr;

	Mix_FreeChunk(navigateSound);
	navigateSound = nullptr;

}

void CharacterSelect::buttonSelectManager() {

	switch (buttonSelect) {

	case CSM_FIGHTER_1:
		selectedCharacter[playerSelect - 1] = CSM_FIGHTER_1;
		break;

	case CSM_FIGHTER_2:
		selectedCharacter[playerSelect - 1] = CSM_FIGHTER_2;
		break;

	case CSM_FIGHTER_3:
		//Select fighter 3
		break;

	case CSM_FIGHTER_4:
		//Select fighter 4
		break;

	case CSM_FIGHTER_5:
		//Select fighter 5
		break;

	case CSM_FIGHTER_6:
		//Select fighter 6
		break;

	case CSM_FIGHTER_7:
		//Select fighter 7
		break;

	case CSM_FIGHTER_8:
		//Select fighter 8
		break;

	case CSM_FIGHTER_9:
		//Select fighter 9
		break;

	case CSM_FIGHTER_10:
		//Select fighter 10
		break;

	case CSM_FIGHTER_11:
		//Select fighter 11
		break;

	case CSM_FIGHTER_12:
		//Select fighter 12
		break;

	case CSM_FIGHTER_13:
		//Select fighter 13
		break;

	case CSM_FIGHTER_14:
		//Select fighter 14
		break;

	case CSM_FIGHTER_15:
		//Select fighter 15
		break;

	case CSM_FIGHTER_16:
		//Select fighter 16
		break;

	case CSM_FIGHTER_17:
		//Select fighter 17
		break;

	case CSM_FIGHTER_18:
		//Select fighter 18
		break;

	case CSM_FIGHTER_19:
		//Select fighter 19
		break;

	case CSM_FIGHTER_20:
		//Select fighter 20
		break;

	}

	if (playerSelect == PLAYER_1) {
		playerSelect = PLAYER_2;
	}
	else if (playerSelect == PLAYER_2) {
		returnState = TEST_STAGE;
	}

	buttonSelect = NULL;

}

void CharacterSelect::buttonHoverManager() {

	//For locked charcters
	if (selectedCharacter[playerSelect] == NULL && playerSelect == PLAYER_1) {
		characterDisplayLeft = characterDisplayPreLoad[0];
	}
	else if(selectedCharacter[playerSelect] == NULL && playerSelect == PLAYER_1) {
		characterDisplayRight = characterDisplayPreLoad[0];
	}

	//Change hover button to appropriate button
	switch (buttonNavigation) {

	case CSM_FIGHTER_1:

		characterFrameHoverRect.x = characterFramesRect[0].x;
		characterFrameHoverRect.y = characterFramesRect[0].y;
		characterFrameHoverRect.w = characterFramesRect[0].w;
		characterFrameHoverRect.h = characterFramesRect[0].h;

		if (playerSelect == PLAYER_1) {
			characterDisplayLeft = characterDisplayPreLoad[1];
		}
		else if (playerSelect == PLAYER_2) {
			characterDisplayRight = characterDisplayPreLoad[1];
		}

		break;

	case CSM_FIGHTER_2:

		characterFrameHoverRect.x = characterFramesRect[1].x;
		characterFrameHoverRect.y = characterFramesRect[1].y;
		characterFrameHoverRect.w = characterFramesRect[1].w;
		characterFrameHoverRect.h = characterFramesRect[1].h;

		if (playerSelect == PLAYER_1) {
			characterDisplayLeft = characterDisplayPreLoad[2];
		}
		else if (playerSelect == PLAYER_2) {
			characterDisplayRight = characterDisplayPreLoad[2];
		}

		break;

	case CSM_FIGHTER_3:
		characterFrameHoverRect.x = characterFramesRect[2].x;
		characterFrameHoverRect.y = characterFramesRect[2].y;
		characterFrameHoverRect.w = characterFramesRect[2].w;
		characterFrameHoverRect.h = characterFramesRect[2].h;
		break;

	case CSM_FIGHTER_4:
		characterFrameHoverRect.x = characterFramesRect[3].x;
		characterFrameHoverRect.y = characterFramesRect[3].y;
		characterFrameHoverRect.w = characterFramesRect[3].w;
		characterFrameHoverRect.h = characterFramesRect[3].h;
		break;

	case CSM_FIGHTER_5:
		characterFrameHoverRect.x = characterFramesRect[4].x;
		characterFrameHoverRect.y = characterFramesRect[4].y;
		characterFrameHoverRect.w = characterFramesRect[4].w;
		characterFrameHoverRect.h = characterFramesRect[4].h;
		break;

	case CSM_FIGHTER_6:
		characterFrameHoverRect.x = characterFramesRect[5].x;
		characterFrameHoverRect.y = characterFramesRect[5].y;
		characterFrameHoverRect.w = characterFramesRect[5].w;
		characterFrameHoverRect.h = characterFramesRect[5].h;
		break;

	case CSM_FIGHTER_7:
		characterFrameHoverRect.x = characterFramesRect[6].x;
		characterFrameHoverRect.y = characterFramesRect[6].y;
		characterFrameHoverRect.w = characterFramesRect[6].w;
		characterFrameHoverRect.h = characterFramesRect[6].h;
		break;

	case CSM_FIGHTER_8:
		characterFrameHoverRect.x = characterFramesRect[7].x;
		characterFrameHoverRect.y = characterFramesRect[7].y;
		characterFrameHoverRect.w = characterFramesRect[7].w;
		characterFrameHoverRect.h = characterFramesRect[7].h;
		break;

	case CSM_FIGHTER_9:
		characterFrameHoverRect.x = characterFramesRect[8].x;
		characterFrameHoverRect.y = characterFramesRect[8].y;
		characterFrameHoverRect.w = characterFramesRect[8].w;
		characterFrameHoverRect.h = characterFramesRect[8].h;
		break;

	case CSM_FIGHTER_10:
		characterFrameHoverRect.x = characterFramesRect[9].x;
		characterFrameHoverRect.y = characterFramesRect[9].y;
		characterFrameHoverRect.w = characterFramesRect[9].w;
		characterFrameHoverRect.h = characterFramesRect[9].h;
		break;

	case CSM_FIGHTER_11:
		characterFrameHoverRect.x = characterFramesRect[10].x;
		characterFrameHoverRect.y = characterFramesRect[10].y;
		characterFrameHoverRect.w = characterFramesRect[10].w;
		characterFrameHoverRect.h = characterFramesRect[10].h;
		break;

	case CSM_FIGHTER_12:
		characterFrameHoverRect.x = characterFramesRect[11].x;
		characterFrameHoverRect.y = characterFramesRect[11].y;
		characterFrameHoverRect.w = characterFramesRect[11].w;
		characterFrameHoverRect.h = characterFramesRect[11].h;
		break;

	case CSM_FIGHTER_13:
		characterFrameHoverRect.x = characterFramesRect[12].x;
		characterFrameHoverRect.y = characterFramesRect[12].y;
		characterFrameHoverRect.w = characterFramesRect[12].w;
		characterFrameHoverRect.h = characterFramesRect[12].h;
		break;

	case CSM_FIGHTER_14:
		characterFrameHoverRect.x = characterFramesRect[13].x;
		characterFrameHoverRect.y = characterFramesRect[13].y;
		characterFrameHoverRect.w = characterFramesRect[13].w;
		characterFrameHoverRect.h = characterFramesRect[13].h;
		break;

	case CSM_FIGHTER_15:
		characterFrameHoverRect.x = characterFramesRect[14].x;
		characterFrameHoverRect.y = characterFramesRect[14].y;
		characterFrameHoverRect.w = characterFramesRect[14].w;
		characterFrameHoverRect.h = characterFramesRect[14].h;
		break;

	case CSM_FIGHTER_16:
		characterFrameHoverRect.x = characterFramesRect[15].x;
		characterFrameHoverRect.y = characterFramesRect[15].y;
		characterFrameHoverRect.w = characterFramesRect[15].w;
		characterFrameHoverRect.h = characterFramesRect[15].h;
		break;

	case CSM_FIGHTER_17:
		characterFrameHoverRect.x = characterFramesRect[16].x;
		characterFrameHoverRect.y = characterFramesRect[16].y;
		characterFrameHoverRect.w = characterFramesRect[16].w;
		characterFrameHoverRect.h = characterFramesRect[16].h;
		break;

	case CSM_FIGHTER_18:
		characterFrameHoverRect.x = characterFramesRect[17].x;
		characterFrameHoverRect.y = characterFramesRect[17].y;
		characterFrameHoverRect.w = characterFramesRect[17].w;
		characterFrameHoverRect.h = characterFramesRect[17].h;
		break;

	case CSM_FIGHTER_19:
		characterFrameHoverRect.x = characterFramesRect[18].x;
		characterFrameHoverRect.y = characterFramesRect[18].y;
		characterFrameHoverRect.w = characterFramesRect[18].w;
		characterFrameHoverRect.h = characterFramesRect[18].h;
		break;

	case CSM_FIGHTER_20:
		characterFrameHoverRect.x = characterFramesRect[19].x;
		characterFrameHoverRect.y = characterFramesRect[19].y;
		characterFrameHoverRect.w = characterFramesRect[19].w;
		characterFrameHoverRect.h = characterFramesRect[19].h;
		break;

	}

}

void CharacterSelect::buttonControl() {

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
		buttonNavigation -= 10;
	}
	else if (kbd.isPressed(SDL_SCANCODE_S) || kbd.isPressed(SDL_SCANCODE_DOWN)) {
		audio.sound.playSound(navigateSound, 0);
		buttonNavigation += 10;
	}
	else if (kbd.isPressed(SDL_SCANCODE_BACKSPACE) || kbd.isPressed(SDL_SCANCODE_ESCAPE)) {
		audio.sound.playSound(selectSound, 0);
		returnState = MM_MAIN_MENU;
	}

	//Left-right controls
	if (buttonNavigation > CSM_FIGHTER_20) {
		buttonNavigation = CSM_FIGHTER_1;
	}
	else if (buttonNavigation < CSM_FIGHTER_1) {
		buttonNavigation = CSM_FIGHTER_20;
	}

	buttonHoverManager();

}

void CharacterSelect::display() {

	//Background
	SDL_RenderCopy(wnd.renderer, background, NULL, &backgroundRect);

	//Character display
	SDL_RenderCopy(wnd.renderer, characterDisplayLeft, NULL, &characterDisplayLeftRect);
	SDL_RenderCopy(wnd.renderer, characterDisplayRight, NULL, &characterDisplayRightRect);

	//Save slots
	for (int i = 0; i < MAX_FIGHTERS; i++) {

		SDL_RenderCopy(wnd.renderer, characterFrames[i], NULL, &characterFramesRect[i]);

	}

	//Hover
	SDL_RenderCopy(wnd.renderer, characterFrameHover, NULL, &characterFrameHoverRect);
	
}

int CharacterSelect::flow() {

	display();

	buttonControl();

	if (buttonSelect != NULL) {
		buttonSelectManager();
	}

	return returnState;

}