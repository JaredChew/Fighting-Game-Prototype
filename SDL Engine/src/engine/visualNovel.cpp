#include "visualNovel.h"

VisualNovel::VisualNovel(GameWindow& wnd) : wnd(wnd) {

	font = new Font(wnd);

	name = nullptr;
	textToDisplay = nullptr;

	namePosition = 0;

	displayNameFrame = true;

	dialogueFrame = nullptr;
	nameFrame = nullptr;
	wallFrame = nullptr;

}

VisualNovel::~VisualNovel() { }

void VisualNovel::renderConversation() {

	SDL_RenderCopy(wnd.renderer, dialogueFrame, NULL, &dialogueRect);

	if (displayNameFrame) {
		SDL_RenderCopy(wnd.renderer, nameFrame, NULL, &nameRect);
		//text name
	}

	//text conversation

}

void VisualNovel::renderTextWall() {

	SDL_RenderCopy(wnd.renderer, wallFrame, NULL, &wallRect);

	//wall of text

}

void VisualNovel::setTextConversation(char* name, char* textToDisplay) {

	this->name = name;
	this->textToDisplay = textToDisplay;

}

void VisualNovel::setTextWall(char* textToDisplay) {

	this->textToDisplay;

}

void VisualNovel::setDialogueFrame(SDL_Texture* dialogueFrame) {

	this->dialogueFrame = dialogueFrame;

	SDL_QueryTexture(dialogueFrame, NULL, NULL, &dialogueRect.w, &dialogueRect.h);

	dialogueRect.x = (int) 0;
	dialogueRect.y = (int) wnd.getHeight() -dialogueRect.h;

}

void VisualNovel::setNameFrame(SDL_Texture* nameFrame) {

	this->nameFrame = nameFrame;

	SDL_QueryTexture(nameFrame, NULL, NULL, &nameRect.w, &nameRect.h);

	nameRect.x = (int) 0.05 * wnd.getWidth();
	nameRect.y = (int) dialogueRect.h - (nameRect.h / 2);

}

void VisualNovel::setTextWallFrame(SDL_Texture* wallFrame) {

	this->wallFrame = wallFrame;

	SDL_QueryTexture(wallFrame, NULL, NULL, &wallRect.w, &wallRect.h);

	nameRect.x = (int) 0.05 * wnd.getWidth();
	nameRect.y = (int) 0.05 * wnd.getHeight();

}

void VisualNovel::setDialogueFrameDimensions(int w, int h) {

	dialogueRect.w = w;
	dialogueRect.h = h;

}

void VisualNovel::setNameFrameDiamensions(int w, int h) {

	nameRect.w = w;
	nameRect.h = h;

}

void VisualNovel::setTextWallFrameDiamensions(int w, int h) {

	wallRect.w = w;
	wallRect.h = h;

}

void VisualNovel::setDialogueFramePositions(int x, int y) {

	dialogueRect.x = x;
	dialogueRect.y = y;

}

void VisualNovel::setNameFrameCustomPosition(int x, int y) {

	nameRect.x = x;
	nameRect.y = y;

}

void VisualNovel::setTextWallFrameCustomPosition(int x, int y) {

	wallRect.x = x;
	wallRect.y = y;

}

void VisualNovel::setNameFramePosition(bool left, bool right) {

	//Default is left

	if (left) { namePosition = LEFT; }
	else if (right) { namePosition = RIGHT; }
	else { namePosition = NONE; }

	updateNameFramePosition();

}

void VisualNovel::updateNameFramePosition() {

	if (namePosition == LEFT) {
		nameRect.x = (int) 0.05 * wnd.getWidth();
		nameRect.y = (int)dialogueRect.h - (nameRect.h / 2);
	}
	else if (namePosition == RIGHT) {
		nameRect.x = (int) 0.05 * wnd.getWidth();
		nameRect.y = (int)dialogueRect.h - (nameRect.h / 2);
	}
	else {
		displayNameFrame = false;
	}

}

void VisualNovel::setDisplayNameFrame(bool isplayNameFrame) {
	this->displayNameFrame = displayNameFrame;
}

bool VisualNovel::getDisplayNameFrame() {
	return displayNameFrame;
}