#pragma once

#include<SFML/Graphics.hpp>

class GameCell {
public:
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	bool isPassable;
	GameCell(std::string, sf::Vector2f, bool);
	bool setSpriteTexture(std::string);
};