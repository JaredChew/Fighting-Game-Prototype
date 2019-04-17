#pragma once

#include <SDL.h>
#include <iostream>
#include <string>
#include <sstream>

#include "engine/logger.h"
#include "engine/gameWindow.h"
#include "engine/keyboard.h"
#include "engine/mouse.h"
#include "engine/resourcesManager.h"
#include "engine/font.h"
#include "engine/audio.h"
#include "engine/physics.h"

#include "menu/mainMenu.h"
#include "menu/characterSelectMenu.h"

#include "stages/testStage.h"

#include "stateTransition.h"

#define TOTAL_FILES 1

class Game{

	private:

		Logger& log;
		GameWindow& wnd;
		Keyboard* kbd;
		Mouse* mse;
		ResourcesManager* rseMngr;
		Audio* audio;
		Physics* physics;

	private:

		int generalCounter;

		int currentState;
		int nextState;
		int returnedState;

		//In-game FPS counter

		Font* font;

		float avgFPS;
		int countedFrames;
		std::stringstream fpsText;

		//Splashscreen

		int splashScreenDuration;

		SDL_Texture* splashScreen;
		SDL_Rect splashScreenRect;

		//Home screen

		SDL_Texture* homeScreen;
		SDL_Rect homeScreenRect;

		Mix_Music* bgm;
		Mix_Chunk* enterSound;

		//Objects

		MainMenu* mainMenu;
		CharacterSelect* charSlct;
		TestStage* testStage;

	private:

		void displayFPScounter();

		int displaySplashScreen();
		int displayHomeScreen();

		void objectInitialiser();
		void objectDestroyer();

		void currentStateManager();


	public:

		Game(GameWindow& wnd, Logger& log);
		~Game();

		void gameFlow();

};
