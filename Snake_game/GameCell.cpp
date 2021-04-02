#include "GameCell.h"

GameCell::GameCell(std::string textureName, sf::Vector2f position, bool isPassable) {
	if (!setSpriteTexture(textureName))
		return;
	pos = position;
	sprite.setPosition(pos);
	sprite.setScale(sf::Vector2f(5, 5));
	this->isPassable = isPassable;
}

bool GameCell::setSpriteTexture(std::string textureName) {
	if (!texture.loadFromFile(textureName)) {
		return false;
	}
	sprite.setTexture(texture);
	return true;
}