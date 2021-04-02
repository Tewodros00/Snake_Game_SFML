#include "Food.h"
#include <random>
#include <ctime>

Food::Food() {
	srand(static_cast<unsigned int>(time(0)));
	std::vector<sf::Vector2f> positions;
	positions.push_back(sf::Vector2f(7 * 40, 7 * 40));
	positions.push_back(sf::Vector2f(6 * 40, 7 * 40));
	positions.push_back(sf::Vector2f(5 * 40, 7 * 40));
	position = generateFood(positions);
}

void Food::draw(sf::RenderWindow& window) {
	window.draw(food->sprite);
}

sf::Vector2f Food::generateFood(std::vector<sf::Vector2f> positions) {
	srand(static_cast<unsigned int>(time(0)));
	delete food;
	position = sf::Vector2f(((rand() % 14) + 1) * 40, ((rand() % 14) + 1) * 40);
	for (unsigned int i = 0; i < positions.size(); i++) {
		if (position == positions[i]) {
			position = sf::Vector2f(((rand() % 14) + 1) * 40, ((rand() % 14) + 1) * 40);
			i = 0;
		}
	}
	food = new GameCell("images/food.png", position, true);
	return position;
}

sf::Vector2f Food::getPosition() {
	return position;
}