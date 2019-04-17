#pragma once

#include <iostream>
#include <sstream>
#include <SDL.h>

#include "logger.h"

#define WINDOW_TITLE "Honey Badger Engine"
#define FPS_NUM_SAMPLES 10

class GameWindow {

	private:
		Logger& log;

	private:

		bool gameloop;

		// Frame limiter

		Uint32 frameStart;

		int maxFPS;
		int frameDelay;
		int frameTicks;

		bool limitFrame;

		//FPS counter

		bool showFPS;

		float frameTimes[FPS_NUM_SAMPLES];

		float avgFPS;
		float countedFrames;
		float currentTicks;
		float prevTicks;
		float frameTimeAverage;

		int currentFrame;

		//Window and screen

		int width;
		int height;

		std::ostringstream dynamicWindowTitle;
		//char dynamicWindowTitle[80]; //C-Style

		SDL_WindowFlags windowSetting;
		SDL_RendererFlags renderSetting;

		SDL_Event event;

	public:
		SDL_Window* window;
		SDL_Surface* backbuffer;
		SDL_Renderer* renderer;

	private:
		int init();

	public:
		GameWindow(Logger& log);
		~GameWindow();

		void eventHandler();
		void update();
		void fpsCounter();
		void fpsLimiter();
		void forceQuit();

		void setMaxFPS(int maxFPS);
		int getMaxFPS();

		bool getIsFrameLimited();

		void setGameLoop(bool gameloop);
		bool getGameLoop();

		void setResolution(int width, int height);

		void setWidth(int width);
		int getWidth();

		void setHeight(int height);
		int getHeight();

		void setFullScreen(bool fullscreen);
		bool getFullScreen();

		void setRenderType(int renderType);
		int getRenderType();

		void setDisplayFPS(bool showFPS);
		bool getDisplayFPS();

		int getAverageFPS();

};
