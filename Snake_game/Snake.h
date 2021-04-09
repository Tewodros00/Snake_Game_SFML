#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

enum class Direction { UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4 };

class SnakeCell
{
public:
	SnakeCell(std::string, sf::Vector2f, bool, Direction);
	~SnakeCell();
	Direction direction;
	GameCell* snakeSprite;
};

class Snake
{
public:
	Snake();
	unsigned int length;
	Direction head_direction;
	std::vector<Direction> directions;
	std::vector<sf::Vector2f> positions;
	std::vector<SnakeCell*> body;
	
	void buildBody();
	void move();
	void grow();
	void changeDirection(Direction);
	void draw(sf::RenderWindow&);
};