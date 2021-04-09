#pragma once

#include "SFML/Graphics.hpp"
#include "GameCell.h"
#include <vector>

class Food {
	public:
		Food();
		void draw(sf::RenderWindow&);
		sf::Vector2f generateFood(std::vector<sf::Vector2f>);
		sf::Vector2f getPosition();
	private:
		GameCell* food;
		sf::Vector2f position;
};