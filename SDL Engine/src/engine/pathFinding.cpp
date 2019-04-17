#include "pathFinding.h"

A_Star::A_Star() {

	tileSize = 0;

	totalTilesX = 0;
	totalTilesY = 0;

	endNodeX = 0;
	endNodeY = 0;

	startNodeX = 0;
	startNodeY = 0;

	currentNodeX = 0;
	currentNodeY = 0;

	pathCount = 0;

	pathFound = false;

}

A_Star::~A_Star() { }

void A_Star::initPathfinding(std::vector< std::vector<Node> > &node, Node &start, Node &end, A_Star &astr) {

	// Start/Departure node
	for (unsigned int y = 0; y < node[0].size(); y++) {

		for (unsigned int x = 0; x < node.size(); x++) {

			if (node[x][y].getX() == start.getX() && node[x][y].getY() == start.getY()) {

				astr.setStartNodeX(x);
				astr.setStartNodeY(y);

			}

		}

	}

	// End/Destination node
	for (unsigned int y = 0; y < node[0].size(); y++) {

		for (unsigned int x = 0; x < node.size(); x++) {

			if (node[x][y].getX() == end.getX() && node[x][y].getY() == end.getY()) {

				astr.setEndNodeX(x);
				astr.setEndNodeY(y);

			}

		}

	}

}

template<typename toMove>
bool A_Star::moveOnPath(toMove &character, std::vector< std::vector<Node> > node) {

	bool changeNextNode = true;

	int nodeToMoveX = character.getNode();
	int nodeToMoveY = character.getNode();

	while(pathCount < path.size()) {

		if (path[pathCount] == UP) {

			if (changeNextNode) {
				nodeToMoveY -= 1;
				changeNextNode = false;
			}

			character.moveUp();
			break;

		}
		else if (path[pathCount] == RIGHT) {

			if (changeNextNode) {
				nodeToMoveX += 1;
				changeNextNode = false;
			}

			character.moveRight();
			break;

		}
		else if (path[pathCount] == DOWN) {

			if (changeNextNode) {
				nodeToMoveY += 1;
				changeNextNode = false;
			}

			character.moveDown();
			break;

		}
		else if (path[pathCount] == LEFT) {

			if (changeNextNode) {
				nodeToMoveX -= 1;
				changeNextNode = false;
			}

			character.moveLeft();
			break;

		}

		if (start.getX() == endNodeX && start.getY() == endNodeY) {
			return true;
		}
		else if (character.getX() == node[nodeToMoveX][nodeToMoveY].getX() && character.getY() == node[nodeToMoveX][nodeToMoveY].getY()) {
			pathCount++;
			changeNextNode = true;
		}

	}

	return false;

}

void A_Star::searchPath(std::vector< std::vector<Node> > &node) {

	currentNodeX = startNodeX;
	currentNodeY = startNodeY;

	while (true) { //!pathFound

		getDirection();

		if (!checkDirectionPrioirty(node)) {

			if (!checkDirection(node)) {

				resetSearch(node);

			}

		}

		// !! Try not to move this to the top !! //
		if (currentNodeX == endNodeX && currentNodeY == endNodeY) {
			break;
			//pathFound = true;
		}

	}

}

void A_Star::resetSearch(std::vector< std::vector<Node> > &node) {

	currentNodeX = startNodeX;
	currentNodeY = startNodeY;

	for (unsigned int i = 0; i < path.size(); i++) {

		if (path[i] == UP) {
			currentNodeY--;
		}
		else if (path[i] == RIGHT) {
			currentNodeX++;
		}
		else if (path[i] == DOWN) {
			currentNodeY++;
		}
		else if (path[i] == LEFT) {
			currentNodeX--;
		}

		node[currentNodeX][currentNodeY].setVisited(false);

	}

	node[currentNodeX][currentNodeY].setOpenNode(false);

	if (!path.empty()) {
		path.clear();
	}

	currentNodeX = startNodeX;
	currentNodeY = startNodeY;

}

void A_Star::getDirection() {

	//Release old direction if not empty
	if (!direction.empty()) {
		direction.clear();
	}

	if (currentNodeY > endNodeY) {
		direction.push_back(UP);
	}

	if (currentNodeX < endNodeX) {
		direction.push_back(RIGHT);
	}

	if (currentNodeY < endNodeY) {
		direction.push_back(DOWN);
	}
	if (currentNodeX > endNodeX) {
		direction.push_back(LEFT);
	}

}

bool A_Star::checkBoundaries(std::vector< std::vector<Node> > node, int currentNodeX, int currentNodeY) {

	if (currentNodeX < 0 || currentNodeX >= totalTilesX) {
		return false;
	}

	if (currentNodeY < 0 || currentNodeY >= totalTilesY) {
		return false;
	}

	if (!node[currentNodeX][currentNodeY].getOpenNode()) {
		return false;
	}

	if (node[currentNodeX][currentNodeY].getVisited()) {
		return false;
	}

	return true;

}

bool A_Star::checkDirectionPrioirty(std::vector< std::vector<Node> > &node) {

	for (unsigned int i = 0; i < direction.size(); i++) {

		if ((direction[i] == UP) && checkBoundaries(node, currentNodeX, currentNodeY - 1)) {
			node[currentNodeX][currentNodeY].setVisited(true);
			currentNodeY -= 1;
			path.push_back(UP);
			return true;
		}
		else if ((direction[i] == RIGHT) && checkBoundaries(node, currentNodeX + 1, currentNodeY)) {
			node[currentNodeX][currentNodeY].setVisited(true);
			currentNodeX += 1;
			path.push_back(RIGHT);
			return true;
		}
		else if ((direction[i] == DOWN) && checkBoundaries(node, currentNodeX, currentNodeY + 1)) {
			node[currentNodeX][currentNodeY].setVisited(true);
			currentNodeY += 1;
			path.push_back(DOWN);
			return true;
		}
		else if ((direction[i] == LEFT) && checkBoundaries(node, currentNodeX - 1, currentNodeY)) {
			node[currentNodeX][currentNodeY].setVisited(true);
			currentNodeX -= 1;
			path.push_back(LEFT);
			return true;
		}

	}

	return false;

}

bool A_Star::checkDirection(std::vector< std::vector<Node> > &node) {

	if (checkBoundaries(node, currentNodeX, currentNodeY - 1)) {
		node[currentNodeX][currentNodeY].setVisited(true);
		currentNodeY -= 1;
		path.push_back(UP);
		return true;
	}
	else if (checkBoundaries(node, currentNodeX + 1, currentNodeY)) {
		node[currentNodeX][currentNodeY].setVisited(true);
		currentNodeX += 1;
		path.push_back(RIGHT);
		return true;
	}
	else if (checkBoundaries(node, currentNodeX, currentNodeY + 1)) {
		node[currentNodeX][currentNodeY].setVisited(true);
		currentNodeY += 1;
		path.push_back(DOWN);
		return true;
	}
	else if (checkBoundaries(node, currentNodeX - 1, currentNodeY)) {
		node[currentNodeX][currentNodeY].setVisited(true);
		currentNodeX -= 1;
		path.push_back(LEFT);
		return true;
	}

	return false;

}

void A_Star::setTileSize(int tileSize) {
	this->tileSize = tileSize;
}

void A_Star::setNumOfTilesX(int totalTilesX) {
	this->totalTilesX = totalTilesX;
}

void A_Star::setNumOfTilesY(int totalTilesY) {
	this->totalTilesY = totalTilesY;
}

void A_Star::setNumOfTiles(int totalTilesX, int totalTilesY) {
	this->totalTilesX = totalTilesX;
	this->totalTilesY = totalTilesY;
}

void A_Star::setStartNodeX(int startNodeX) {
	this->startNodeX = startNodeX;
}

void A_Star::setStartNodeY(int startNodeY) {
	this->startNodeY = startNodeY;
}

void A_Star::setStartNodes(int startNodeX, int startNodeY) {
	this->startNodeX = startNodeX;
	this->startNodeY = startNodeY;
}

void A_Star::setEndNodeX(int endNodeX) {
	this->endNodeX = endNodeX;
}

void A_Star::setEndNodeY(int endNodeY) {
	this->endNodeY = endNodeY;
}

void A_Star::setEndNodes(int endNodeX, int endNodeY) {
	this->endNodeX = endNodeX;
	this->endNodeY = endNodeY;
}