#include "testStage.h"

//template <typename P1_fighter, typename P2_fighter>
TestStage::TestStage(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	timerCountdown = 100;
	timerCounter = 0;

	returnState = NULL;
	nextState = NULL;

	floor = (int) (0.93* wnd.getHeight());

	player1 = new TestFighter1(wnd, rseMngr, kbd, mse, audio);
	player1->fighterInit(floor, FACE_RIGHT);

	fightOverMenu = new FightOverMenu(wnd, rseMngr, kbd, mse, audio);

	//Background
	background = rseMngr.loadTextureImage("asset/graphic/testStage.png");
	SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	//Player 1 health bar
	healthBarLeft = rseMngr.loadTextureImage("asset/graphic/healthBar.png");
	SDL_QueryTexture(healthBarLeft, NULL, NULL, &healthBarLeftRect.w, &healthBarLeftRect.h);
	healthBarLeftRect.x = (int) (0.05 * wnd.getWidth());
	healthBarLeftRect.y = (int) (0.05 * wnd.getHeight());
	healthBarLeftRect.w = (int) (0.35 * (float) wnd.getWidth());
	healthBarLeftRect.h = (int) (0.05 * wnd.getHeight());

	//Countdown timer
	timer = new Font(wnd);
	timer->setFont(rseMngr.loadFont("asset/font/Consolas.ttf", 100));
	timerRect.x = (int)(healthBarLeftRect.x + healthBarLeftRect.w + (0.07 * wnd.getWidth()));
	timerRect.y = healthBarLeftRect.y;
	timerRect.w = 50;
	timerRect.h = (int) (healthBarLeftRect.h * 1.5);

	//Player 1 health bar
	healthBarRight = rseMngr.loadTextureImage("asset/graphic/healthBar.png");
	SDL_QueryTexture(healthBarRight, NULL, NULL, &healthBarRightRect.w, &healthBarRightRect.h);
	healthBarRightRect.y = healthBarLeftRect.y;
	healthBarRightRect.x = (int)(timerRect.x + timerRect.w + (0.075 * wnd.getWidth()));
	healthBarRightRect.w = (int)(0.35 * (float)wnd.getWidth());
	healthBarRightRect.h = healthBarLeftRect.h;

	//bgm = rseMngr.loadMusic("");
	menuSound = rseMngr.loadSound("asset/sound/homeMenuEnter.wav");

	//audio.music.playMusic(bgm, 0);

}

//template <typename P1_fighter, typename P2_fighter>
TestStage::~TestStage() {

	delete timer;
	timer = nullptr;

	SDL_DestroyTexture(background);
	background  = nullptr;

	SDL_DestroyTexture(healthBarLeft);
	healthBarLeft  = nullptr;

	SDL_DestroyTexture(healthBarRight);
	healthBarRight  = nullptr;

	//Mix_FreeMusic(bgm);
	//bgm = nullptr;

	Mix_FreeChunk(menuSound);
	menuSound = nullptr;

	std::cout << "\nTest stage destroyed" << std::endl;

}


//template <typename P1_fighter, typename P2_fighter>
void TestStage::reset() {

	timerCountdown = 100;
	timerCounter = 0;

	player1->reset();
	//player2->reset();

	healthBarRightRect.w = (int)(0.35 * (float)wnd.getWidth());
	healthBarLeftRect.w = (int)(0.35 * (float)wnd.getWidth());

	//audio.music.playMusic(bgm, 0);

}

//template <typename P1_fighter, typename P2_fighter>
void TestStage::clampInWindow() {

	//

}

void TestStage:: buttonControls() {

	if (kbd.isPressed(SDL_SCANCODE_ESCAPE)) {
		audio.sound.playSound(menuSound, 0);
		nextState = IGM_IN_GAME_MENU;
	}

}

//template <typename P1_fighter, typename P2_fighter>
void TestStage::countdownTimerDisplay() {

	timerText << timerCountdown;

	timer->displayFont(timerText.str(), timerRect.x, timerRect.y, timerRect.w, timerRect.h, 0, 0, 0);

	timerText.str("");
	timerText.clear();

}

//template <typename P1_fighter, typename P2_fighter>
void TestStage::display() {

	SDL_RenderCopy(wnd.renderer, background, NULL, &backgroundRect);

	player1->display();
	//player2->display();

	SDL_RenderCopy(wnd.renderer, healthBarLeft, NULL, &healthBarLeftRect);
	SDL_RenderCopy(wnd.renderer, healthBarRight, NULL, &healthBarRightRect);

	countdownTimerDisplay();

}

void TestStage::update() {

	if (timerCountdown != 0) {

		buttonControls();
		player1->update();
		//player2->update();
		clampInWindow();

		if (timerCounter == wnd.getMaxFPS()) {
			timerCountdown--;
			timerCounter = 0;
		}
		else {
			timerCounter++;
		}

	}
	else {

		returnState = fightOverMenu->flow();

		switch (returnState) {

		case FOM_REMATCH:
			reset();
			returnState = NULL;
			break;

		case FOM_CHANGE_CHARACTER:
			returnState = CSM_CHARACTER_SELECT_MENU;
			break;

		case FOM_MAIN_MENU:
			returnState = MM_MAIN_MENU;
			break;

		}

	}

}

void TestStage::stateManager() {

	switch (nextState) {

	case IGM_IN_GAME_MENU:
		inGameMenu = new InGameMenu(wnd, rseMngr, kbd, mse, audio);
		currentState = IGM_IN_GAME_MENU;
		break;

	case IGM_RESUME_GAME:
		delete inGameMenu;
		inGameMenu = nullptr;
		currentState = NULL;
		break;

	case IGM_MAIN_MENU:
		delete inGameMenu;
		inGameMenu = nullptr;
		returnState = MM_MAIN_MENU;
		break;

	case QUIT_GAME:
		delete inGameMenu;
		inGameMenu = nullptr;
		returnState = QUIT_GAME;
		break;

	}

}

//template <typename P1_fighter, typename P2_fighter>
int TestStage::flow() {

	display();

	switch (currentState) {

	case IGM_IN_GAME_MENU:
		nextState = inGameMenu->flow();
		break;

	default:
		update();

	}

	if (nextState != NULL) {
		stateManager();
	}

	return returnState;

}