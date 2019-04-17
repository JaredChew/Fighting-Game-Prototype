#include "testFighter1.h"

TestFighter1::TestFighter1(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	health = 100;
	damage = 5;

	moveSpeed = 30;
	jumpSpeed = 30;
	landSpeed = 50;

	floor = NULL;

	bufferTime = kbd.getPressDelay() + 1;

	idleBufferCounter = 0;
	jumpBufferCounter = 0;
	crouchBufferCounter = 0;

	jumpPosition = false;
	crouchPosition = false;

	//Flip
	facingPosition = NULL;
	imageFlip = SDL_FLIP_NONE;

	//Stand
	stand = rseMngr.loadTextureImage("asset/graphic/fighter1_stand.png");
	SDL_QueryTexture(stand, NULL, NULL, &standRect.w, &standRect.h);

	punchLight = rseMngr.loadTextureImage("asset/graphic/fighter1_punch_light.png");
	SDL_QueryTexture(punchLight, NULL, NULL, &punchLightRect.w, &punchLightRect.h);

	punchMedium = rseMngr.loadTextureImage("asset/graphic/fighter1_punch_medium.png");
	SDL_QueryTexture(punchMedium, NULL, NULL, &punchMediumRect.w, &punchMediumRect.h);

	punchHeavy = rseMngr.loadTextureImage("asset/graphic/fighter1_punch_heavy.png");
	SDL_QueryTexture(punchHeavy, NULL, NULL, &punchHeavyRect.w, &punchHeavyRect.h);

	kickLight = rseMngr.loadTextureImage("asset/graphic/fighter1_kick_light.png");
	SDL_QueryTexture(kickLight, NULL, NULL, &kickLightRect.w, &kickLightRect.h);

	kickMedium = rseMngr.loadTextureImage("asset/graphic/fighter1_kick_medium.png");
	SDL_QueryTexture(kickMedium, NULL, NULL, &kickMediumRect.w, &kickMediumRect.h);

	kickHeavy = rseMngr.loadTextureImage("asset/graphic/fighter1_kick_heavy.png");
	SDL_QueryTexture(kickHeavy, NULL, NULL, &kickHeavyRect.w, &kickHeavyRect.h);

	//Crouch
	crouch = rseMngr.loadTextureImage("asset/graphic/fighter1_crouch.png");
	SDL_QueryTexture(crouch, NULL, NULL, &crouchRect.w, &crouchRect.h);

	crouchPunchLight = rseMngr.loadTextureImage("asset/graphic/fighter1_crouchPunch_light.png");
	SDL_QueryTexture(crouchPunchLight, NULL, NULL, &crouchPunchLightRect.w, &crouchPunchLightRect.h);

	crouchPunchMedium = rseMngr.loadTextureImage("asset/graphic/fighter1_crouchPunch_medium.png");
	SDL_QueryTexture(crouchPunchMedium, NULL, NULL, &crouchPunchMediumRect.w, &crouchPunchMediumRect.h);

	crouchPunchHeavy = rseMngr.loadTextureImage("asset/graphic/fighter1_crouchPunch_heavy.png");
	SDL_QueryTexture(crouchPunchHeavy, NULL, NULL, &crouchPunchHeavyRect.w, &crouchPunchHeavyRect.h);

	crouchKickLight = rseMngr.loadTextureImage("asset/graphic/fighter1_crouchKick_light.png");
	SDL_QueryTexture(crouchKickLight, NULL, NULL, &crouchKickLightRect.w, &crouchKickLightRect.h);

	crouchKickMedium = rseMngr.loadTextureImage("asset/graphic/fighter1_crouchKick_medium.png");
	SDL_QueryTexture(crouchKickMedium, NULL, NULL, &crouchKickMediumRect.w, &crouchKickMediumRect.h);

	crouchKickHeavy = rseMngr.loadTextureImage("asset/graphic/fighter1_crouchKick_heavy.png");
	SDL_QueryTexture(crouchKickHeavy, NULL, NULL, &crouchKickHeavyRect.w, &crouchKickHeavyRect.h);

	//Jump
	jump = rseMngr.loadTextureImage("asset/graphic/fighter1_jump.png");
	SDL_QueryTexture(jump, NULL, NULL, &jumpRect.w, &jumpRect.h);

	jumpPunchLight = rseMngr.loadTextureImage("asset/graphic/fighter1_jumpPunch_light.png");
	SDL_QueryTexture(jumpPunchLight, NULL, NULL, &jumpPunchLightRect.w, &jumpPunchLightRect.h);

	jumpPunchMedium = rseMngr.loadTextureImage("asset/graphic/fighter1_jumpPunch_medium.png");
	SDL_QueryTexture(jumpPunchMedium, NULL, NULL, &jumpPunchMediumRect.w, &jumpPunchMediumRect.h);

	jumpPunchHeavy = rseMngr.loadTextureImage("asset/graphic/fighter1_jumpPunch_heavy.png");
	SDL_QueryTexture(jumpPunchHeavy, NULL, NULL, &jumpPunchHeavyRect.w, &jumpPunchHeavyRect.h);

	jumpKickLight = rseMngr.loadTextureImage("asset/graphic/fighter1_jumpKick_light.png");
	SDL_QueryTexture(jumpKickLight, NULL, NULL, &jumpKickLightRect.w, &jumpKickLightRect.h);

	jumpKickMedium = rseMngr.loadTextureImage("asset/graphic/fighter1_jumpKick_medium.png");
	SDL_QueryTexture(jumpKickMedium, NULL, NULL, &jumpKickMediumRect.w, &jumpKickMediumRect.h);

	jumpKickHeavy = rseMngr.loadTextureImage("asset/graphic/fighter1_jumpKick_heavy.png");
	SDL_QueryTexture(jumpKickHeavy, NULL, NULL, &jumpKickHeavyRect.w, &jumpKickHeavyRect.h);

	//Movement
	moveBack = rseMngr.loadTextureImage("asset/graphic/fighter1_moveBack.png");
	SDL_QueryTexture(moveBack, NULL, NULL, &moveBackRect.w, &moveBackRect.h);

	moveFront = rseMngr.loadTextureImage("asset/graphic/fighter1_moveFront.png");
	SDL_QueryTexture(moveFront, NULL, NULL, &moveFrontRect.w, &moveFrontRect.h);

	//Block
	block = rseMngr.loadTextureImage("asset/graphic/fighter1_block.png");
	SDL_QueryTexture(block, NULL, NULL, &blockRect.w, &blockRect.h);

	//Fighter
	fighter = stand;
	SDL_QueryTexture(stand, NULL, NULL, &fighterRect.w, &fighterRect.h);
	fighterRect.x = (int)(0.2 * wnd.getWidth());
	//fighterRect.w = standRect.w;
	//fighterRect.h = standRect.h;

}

TestFighter1::~TestFighter1() {

	//Stance
	SDL_DestroyTexture(stand);
	stand = nullptr;

	SDL_DestroyTexture(punchLight);
	punchLight = nullptr;

	SDL_DestroyTexture(kickLight);
	kickLight = nullptr;

	SDL_DestroyTexture(crouch);
	crouch = nullptr;

	SDL_DestroyTexture(jump);
	jump = nullptr;

	SDL_DestroyTexture(moveFront);
	moveFront = nullptr;

	SDL_DestroyTexture(moveBack);
	moveBack = nullptr;

	SDL_DestroyTexture(block);
	block = nullptr;

	//Fighter
	SDL_DestroyTexture(fighter);
	fighter = nullptr;

}

void TestFighter1::reset() {

	health = 100;

	fighterRect.x = (int)(0.2 * wnd.getWidth());

	imageFlip = SDL_FLIP_NONE;

	jumpPosition = false;
	crouchPosition = false;

}

void TestFighter1::movementManager(int movementPosition) {
	
	switch (movementPosition) {

	case MOVE_UP:
		fighterRect.y -= jumpSpeed;
		break;

	case MOVE_RIGHT:
		fighterRect.x += moveSpeed;
		break;

	case MOVE_DOWN:
		fighterRect.y = floor - fighterRect.h;
		break;

	case MOVE_LEFT:
		fighterRect.x -= moveSpeed;
		break;

	}

	if (idleBufferCounter == 0) {
		idleBufferCounter++;
	}
	else if (idleBufferCounter >= bufferTime) {
		idleBufferCounter = 1;
	}

}

void TestFighter1::fightMovesJump() {

	if (jumpPosition && kbd.isPressed(KEYBOARD_A)) { //Light punch

		fighter = jumpPunchLight;
		SDL_QueryTexture(jumpPunchLight, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = jumpPunchLightRect.w;
		//fighterRect.h = jumpPunchLightRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (jumpPosition && kbd.isPressed(KEYBOARD_S)) { //Medium punch

		fighter = jumpPunchMedium;
		SDL_QueryTexture(jumpPunchMedium, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = jumpPunchMediumRect.w;
		//fighterRect.h = jumpPunchMediumRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (jumpPosition && kbd.isPressed(KEYBOARD_D)) { //Heavy punch

		fighter = jumpPunchHeavy;
		SDL_QueryTexture(jumpPunchHeavy, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = jumpPunchHeavyRect.w;
		//fighterRect.h = jumpPunchHeavyRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (jumpPosition && kbd.isPressed(KEYBOARD_Z)) { //Light kick

		fighter = jumpKickLight;
		SDL_QueryTexture(jumpKickLight, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = jumpKickLightRect.w;
		//fighterRect.h = jumpKickLightRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (jumpPosition && kbd.isPressed(KEYBOARD_X)) { //Medium kick

		fighter = jumpKickMedium;
		SDL_QueryTexture(jumpKickMedium, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = jumpKickMediumRect.w;
		//fighterRect.h = jumpKickMediumRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (jumpPosition && kbd.isPressed(KEYBOARD_C)) { //Heavy kick

		fighter = jumpKickHeavy;
		SDL_QueryTexture(jumpKickHeavy, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = jumpKickHeavyRect.w;
		//fighterRect.h = jumpKickHeavyRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}

}

void TestFighter1::fightMovesStand() {

	if (kbd.isPressed(KEYBOARD_A)) { //Light punch

		fighter = punchLight;
		SDL_QueryTexture(punchLight, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = punchLightRect.w;
		//fighterRect.h = punchLightRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (kbd.isPressed(KEYBOARD_S)) { //Medium punch

		fighter = punchMedium;
		SDL_QueryTexture(punchMedium, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = punchMediumRect.w;
		//fighterRect.h = punchMediumRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (kbd.isPressed(KEYBOARD_D)) { //Heavy punch

		fighter = punchHeavy;
		SDL_QueryTexture(punchHeavy, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = punchHeavyRect.w;
		//fighterRect.h = punchHeavyRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (kbd.isPressed(KEYBOARD_Z)) { //Light kick

		fighter = kickLight;
		SDL_QueryTexture(kickLight, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = kickLightRect.w;
		//fighterRect.h = kickLightRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (kbd.isPressed(KEYBOARD_X)) { //Medium kick

		fighter = kickMedium;
		SDL_QueryTexture(kickMedium, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = kickMediumRect.w;
		//fighterRect.h = kickMediumRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (kbd.isPressed(KEYBOARD_C)) { //Heavy kick

		fighter = kickHeavy;
		SDL_QueryTexture(kickHeavy, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = kickHeavyRect.w;
		//fighterRect.h = kickHeavyRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}

}

void TestFighter1::fightMovesCrouch() {

	if (crouchPosition && kbd.isPressed(KEYBOARD_A)) { //Light punch

		fighter = crouchPunchLight;
		SDL_QueryTexture(crouchPunchLight, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = crouchPunchLightRect.w;
		//fighterRect.h = crouchPunchLightRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (crouchPosition && kbd.isPressed(KEYBOARD_S)) { //Medium punch

		fighter = punchMedium;
		SDL_QueryTexture(punchMedium, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = crouchPunchMediumRect.w;
		//fighterRect.h = crouchPunchMediumRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (crouchPosition && kbd.isPressed(KEYBOARD_D)) { //Heavy punch

		fighter = crouchPunchHeavy;
		SDL_QueryTexture(crouchPunchHeavy, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = crouchPunchHeavyRect.w;
		//fighterRect.h = crouchPunchHeavyRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (crouchPosition && kbd.isPressed(KEYBOARD_Z)) { //Light kick

		fighter = crouchKickLight;
		SDL_QueryTexture(crouchKickLight, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = crouchKickLightRect.w;
		//fighterRect.h = crouchKickLightRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (crouchPosition && kbd.isPressed(KEYBOARD_X)) { //Medium kick

		fighter = crouchKickMedium;
		SDL_QueryTexture(crouchKickMedium, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = crouchKickMediumRect.w;
		//fighterRect.h = crouchKickMediumRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}
	else if (crouchPosition && kbd.isPressed(KEYBOARD_C)) { //Heavy kick

		fighter = crouchKickHeavy;
		SDL_QueryTexture(crouchKickHeavy, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = crouchKickHeavyRect.w;
		//fighterRect.h = crouchKickHeavyRect.h;

		if (idleBufferCounter == 0) {
			idleBufferCounter++;
		}
		else if (idleBufferCounter >= bufferTime) {
			idleBufferCounter = 1;
		}

	}

}

void TestFighter1::buttonControls() {

	fightMovesJump();
	fightMovesStand();
	fightMovesCrouch();

	//Movement verticle
	if (kbd.isPressed(KEYBOARD_UP)) { //Jump

		fighter = jump;
		SDL_QueryTexture(jump, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = jumpRect.w;
		//fighterRect.h = jumpRect.h;

		if (jumpBufferCounter == 0) {
			jumpBufferCounter++;
			jumpPosition = true;
		}

		movementManager(MOVE_UP);

	}
	else if (kbd.isPressed(KEYBOARD_DOWN)) { //Courch

		fighter = crouch;
		SDL_QueryTexture(crouch, NULL, NULL, &fighterRect.w, &fighterRect.h);
		//fighterRect.w = crouchRect.w;
		//fighterRect.h = crouchRect.h;

		if (crouchBufferCounter == 0) {
			crouchBufferCounter++;
		}

		crouchPosition = true;

		movementManager(MOVE_DOWN);

	}
	
	//Movement horizontal
	if (facingPosition == FACE_RIGHT) {

		if (crouchPosition && kbd.isPressed(KEYBOARD_LEFT)) { //Block
			fighter = block;
			SDL_QueryTexture(block, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = blockRect.w;
			//fighterRect.h = blockRect.h;
		}
		else if (kbd.isPressed(KEYBOARD_LEFT)) { //Move back

			fighter = moveFront;
			SDL_QueryTexture(moveFront, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = moveFrontRect.w;
			//fighterRect.h = moveFrontRect.h;

			movementManager(MOVE_LEFT);

		}
		else if (kbd.isPressed(KEYBOARD_RIGHT)) { //Move front
			fighter = moveBack;
			SDL_QueryTexture(moveBack, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = moveBackRect.w;
			//fighterRect.h = moveBackRect.h;

			movementManager(MOVE_RIGHT);

		}

	}
	else if (facingPosition == FACE_LEFT) {

		if (crouchPosition && kbd.isPressed(KEYBOARD_RIGHT)) { //Block
			fighter = block;
			SDL_QueryTexture(block, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = blockRect.w;
			//fighterRect.h = blockRect.h;
		}
		else if (kbd.isPressed(KEYBOARD_RIGHT)) { //Move front
			fighter = moveFront;
			SDL_QueryTexture(moveFront, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = moveFrontRect.w;
			//fighterRect.h = moveFrontRect.h;

			movementManager(MOVE_LEFT);

		}
		else if (kbd.isPressed(KEYBOARD_LEFT)) { //Move back
			fighter = moveBack;
			SDL_QueryTexture(moveBack, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = moveBackRect.w;
			//fighterRect.h = moveBackRect.h;

			movementManager(MOVE_RIGHT);

		}

	}

	//Block
	if (facingPosition == FACE_RIGHT) {

		if (crouchPosition && kbd.isPressed(KEYBOARD_LEFT)) {
			fighter = block;
			SDL_QueryTexture(block, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = blockRect.w;
			//fighterRect.h = blockRect.h;
			std::cout << "here" << std::endl;
		}

	}
	else if (facingPosition == FACE_LEFT) {

		if (crouchPosition && kbd.isPressed(KEYBOARD_RIGHT)) {
			fighter = block;
			SDL_QueryTexture(block, NULL, NULL, &fighterRect.w, &fighterRect.h);
			//fighterRect.w = blockRect.w;
			//fighterRect.h = blockRect.h;
		}

	}

}

void TestFighter1::stanceManager() {

	//Land jump
	if (jumpBufferCounter >= bufferTime) {

		fighterRect.y += jumpSpeed;

		if (fighterRect.y >= (floor - fighterRect.h)) {
			jumpBufferCounter = 0;
			jumpPosition = false;
		}

	}
	else if (jumpBufferCounter != 0) {

		jumpBufferCounter++;

	}

	//Couch
	if (crouchBufferCounter >= bufferTime) {
		crouchBufferCounter = 0;
		crouchPosition = false;
	}
	else if (crouchBufferCounter != 0) {
		crouchBufferCounter++;
	}

	//Sitch to idle animation
	if (idleBufferCounter >= bufferTime && fighter != stand) {

		fighter = stand;

		SDL_QueryTexture(stand, NULL, NULL, &fighterRect.w, &fighterRect.h);
		fighterRect.y = floor - fighterRect.h;

	}
	else if (idleBufferCounter != 0) {
		idleBufferCounter++;
	}

	//Stay on floor
	if ((fighterRect.y + fighterRect.h) >= floor) {
		fighterRect.y = floor - fighterRect.h;
	}

}

void TestFighter1::update() {

	buttonControls();

	stanceManager();

	std::cout << crouchPosition << std::endl;

}

void TestFighter1::display() {

	SDL_RenderCopyEx(wnd.renderer, fighter, NULL, &fighterRect, 0.0, NULL, imageFlip);

}

void TestFighter1::fighterInit(int floor, int facingPosition) {

	this->floor = floor;

	fighterRect.y = floor - fighterRect.h;

	if (facingPosition == FACE_RIGHT) {
		this->facingPosition = FACE_RIGHT;
		imageFlip = SDL_FLIP_NONE;
	}
	else if (facingPosition == FACE_LEFT) {
		this->facingPosition = FACE_LEFT;
		imageFlip = SDL_FLIP_HORIZONTAL;
	}

}

void TestFighter1::setHealth(int health) {
	this->health = health;
}

int TestFighter1::getHealth() {
	return health;
}

void TestFighter1::setFacingPosition(int facingPosition) {
	this->facingPosition = facingPosition;
}

int TestFighter1::getFacingPosition() {
	return facingPosition;
}