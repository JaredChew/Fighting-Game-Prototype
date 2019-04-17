#pragma once

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"
#include "../engine/font.h"
#include "../engine/sprite.h"

#include "../stateTransition.h"

#define FACE_RIGHT 1
#define FACE_LEFT 2

#define MOVE_UP 1
#define MOVE_RIGHT 2
#define MOVE_DOWN 3
#define MOVE_LEFT 4

class TestFighter1{

private:
	GameWindow& wnd;
	ResourcesManager& rseMngr;
	Keyboard& kbd;
	Mouse& mse;
	Audio& audio;

private:
	int health;
	int damage;

	int moveSpeed;
	int jumpSpeed;
	int landSpeed;
	
	int floor;
	int facingPosition;

	int bufferTime;

	int idleBufferCounter;
	int jumpBufferCounter;
	int crouchBufferCounter;

	bool jumpPosition;
	bool crouchPosition;

	//Fighter display
	SDL_Texture* fighter;
	SDL_Rect fighterRect;

	SDL_RendererFlip imageFlip;

	//Stand
	SDL_Texture* stand;
	SDL_Rect standRect;

	SDL_Texture* punchLight;
	SDL_Rect punchLightRect;

	SDL_Texture* punchMedium;
	SDL_Rect punchMediumRect;

	SDL_Texture* punchHeavy;
	SDL_Rect punchHeavyRect;

	SDL_Texture* kickLight;
	SDL_Rect kickLightRect;

	SDL_Texture* kickMedium;
	SDL_Rect kickMediumRect;

	SDL_Texture* kickHeavy;
	SDL_Rect kickHeavyRect;

	//Crouch
	SDL_Texture* crouch;
	SDL_Rect crouchRect;

	SDL_Texture* crouchPunchLight;
	SDL_Rect crouchPunchLightRect;

	SDL_Texture* crouchPunchMedium;
	SDL_Rect crouchPunchMediumRect;

	SDL_Texture* crouchPunchHeavy;
	SDL_Rect crouchPunchHeavyRect;

	SDL_Texture* crouchKickLight;
	SDL_Rect crouchKickLightRect;

	SDL_Texture* crouchKickMedium;
	SDL_Rect crouchKickMediumRect;

	SDL_Texture* crouchKickHeavy;
	SDL_Rect crouchKickHeavyRect;

	//Jump
	SDL_Texture* jump;
	SDL_Rect jumpRect;

	SDL_Texture* jumpPunchLight;
	SDL_Rect jumpPunchLightRect;

	SDL_Texture* jumpPunchMedium;
	SDL_Rect jumpPunchMediumRect;

	SDL_Texture* jumpPunchHeavy;
	SDL_Rect jumpPunchHeavyRect;

	SDL_Texture* jumpKickLight;
	SDL_Rect jumpKickLightRect;

	SDL_Texture* jumpKickMedium;
	SDL_Rect jumpKickMediumRect;

	SDL_Texture* jumpKickHeavy;
	SDL_Rect jumpKickHeavyRect;

	//Movements
	SDL_Texture* moveBack;
	SDL_Rect moveBackRect;

	SDL_Texture* moveFront;
	SDL_Rect moveFrontRect;

	//Block
	SDL_Texture* block;
	SDL_Rect blockRect;

private:
	void movementManager(int movementPosition);
	void buttonControls();

public:
	TestFighter1(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~TestFighter1();

	void fightMovesJump();
	void fightMovesStand();
	void fightMovesCrouch();

	void stanceManager();
	void update();
	void display();

	void reset();
	void fighterInit(int floor, int facingPosition);

	void setHealth(int health);
	int getHealth();

	void setFacingPosition(int facingPosition);
	int getFacingPosition();

};