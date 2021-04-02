#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include "GameCell.h"
#include <vector>

class GameWorld
{
private:
	sf::Vector2i foodPosition;
	void initializeGround();
	
public:
	std::vector<std::vector<GameCell*>> cells;
	int gridLength;
	GameWorld();
	void draw(sf::RenderWindow&);
};

#endif // !GAMEWORLD_H

