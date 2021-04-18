#include "GameWorld.h"


GameWorld::GameWorld() {
	gridLength = 16;
	initializeGround();
}

void GameWorld::initializeGround() {
	cells.clear();
	cells.reserve(gridLength);
	for (int i = 0; i < 16; i++) {
		if (i == 0) {
			std::vector<GameCell*> row;
			row.reserve(gridLength);
			for (int j = 0; j < gridLength; j++) {
				row.push_back(new GameCell("../Resources/Images/wall_top.png", sf::Vector2f(j * 40, 0), false));
			}
			cells.push_back(row);
		}
		else if (i == 15) {
			std::vector<GameCell*> row;
			row.reserve(gridLength);
			for (int j = 0; j < gridLength; j++) {
				row.push_back(new GameCell("../Resources/Images/wall_bottom.png", sf::Vector2f(j * 40, 600), false));
			}
			cells.push_back(row);
		}
		else {
			std::vector<GameCell*> row;
			row.reserve(gridLength);
			row.push_back(new GameCell("../Resources/Images/wall_left.png", sf::Vector2f(0, i * 40), false));
			for (int j = 1; j < 15; j++) {
				row.push_back(new GameCell("../Resources/Images/ground.png", sf::Vector2f(j * 40, i * 40), true));
			}
			row.push_back(new GameCell("../Resources/Images/wall_right.png", sf::Vector2f(600, i * 40), false));
			cells.push_back(row);
		}
	}	
}

void GameWorld::draw(sf::RenderWindow& window) {
	for (int i = 0; i < gridLength; i++) {
		for (int j = 0; j < gridLength; j++) {
			window.draw(cells[i][j]->sprite);
		}
	}
}