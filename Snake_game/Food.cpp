#include "Food.h"
#include <random>
#include <algorithm>
#include <ctime>

Food::Food() {
	std::vector<sf::Vector2f> positions;
	positions.reserve(3);
	positions.emplace_back(7 * 40, 7 * 40);
	positions.emplace_back(6 * 40, 7 * 40);
	positions.emplace_back(5 * 40, 7 * 40);
	position = generateFood(positions);
}

void Food::draw(sf::RenderWindow& window) {
	window.draw(food->sprite);
}

sf::Vector2f Food::generateFood(std::vector<sf::Vector2f> positions) {
	srand(static_cast<unsigned int>(time(0)));
	delete food;
	std::vector<sf::Vector2f>::iterator iter = positions.begin();
	while (iter != positions.end()) {
		position = sf::Vector2f(((rand() % 14) + 1) * 40, ((rand() % 14) + 1) * 40);
		iter = std::find(positions.begin(), positions.end(), position);
	} 
	food = new GameCell("images/food.png", position, true);
	return position;
}

sf::Vector2f Food::getPosition() {
	return position;
}