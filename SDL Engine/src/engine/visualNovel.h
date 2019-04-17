#pragma once

#include <SDL.h>

#include "gameWindow.h"
#include "font.h"

#define NONE 0
#define LEFT 1
#define RIGHT 2

class VisualNovel {

private:
	GameWindow& wnd;

private:
	Font* font;

	char* name;
	char* textToDisplay;

	int namePosition;

	bool displayNameFrame;

	SDL_Texture* dialogueFrame;
	SDL_Rect dialogueRect;

	SDL_Texture* nameFrame;
	SDL_Rect nameRect;

	SDL_Texture* wallFrame;
	SDL_Rect wallRect;

public:
	VisualNovel(GameWindow& wnd);
	~VisualNovel();

	void renderConversation();
	void renderTextWall();

	void setTextConversation(char* name, char* textTiDisplay);
	void setTextWall(char* textToDisplay);

	void setDialogueFrame(SDL_Texture* dialogueFrame);
	void setNameFrame(SDL_Texture* nameFrame);
	void setTextWallFrame(SDL_Texture* wallFrame);

	void setDialogueFrameDimensions(int w, int h);
	void setNameFrameDiamensions(int w, int h);
	void setTextWallFrameDiamensions(int w, int h);

	void setDialogueFramePositions(int x, int y);
	void setNameFrameCustomPosition(int x, int y);
	void setTextWallFrameCustomPosition(int x, int y);

	void setNameFramePosition(bool left, bool right);

	void setDisplayNameFrame(bool nameFrame);
	bool getDisplayNameFrame();

private:
	void updateNameFramePosition();

};

/*

			NOTE

	To be rendered last

*/