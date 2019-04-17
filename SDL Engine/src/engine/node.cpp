#include "node.h"

Node::Node() {

	x = 0;
	y = 0;

	openNode = true;
	visited = false;
	passable = true;

}

Node::~Node() { }

void Node::setNodePositions(int x, int y) {
	this->x = x;
	this->y = y;
}

void Node::setX(int x) {
	this->x = x;
}

void Node::setY(int y) {
	this->y = y;
}

int Node::getX() {
	return x;
}

int Node::getY() {
	return y;
}

void Node::setOpenNode(bool openNode) {
	this->openNode = openNode;
}

void Node::setVisited(bool visited) {
	this->visited = visited;
}

void Node::setPassable(bool passable) {
	this->passable = passable;
}

bool Node::getOpenNode() {
	return openNode;
}

bool Node::getVisited() {
	return visited;
}

bool Node::getPassable() {
	return passable;
}
