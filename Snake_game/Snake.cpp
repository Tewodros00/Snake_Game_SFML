#include <SFML/Graphics.hpp>
#include "GameCell.h"
#include "Snake.h"

SnakeCell::SnakeCell(std::string textureName, sf::Vector2f position, bool isPassable, Direction direction)
{
	switch (direction)
	{
	case(Direction::UP):
		textureName += "_up.png";
		break;
	case(Direction::DOWN):
		textureName += "_down.png";
		break;
	case(Direction::LEFT):
		textureName += "_left.png";
		break;
	case(Direction::RIGHT):
		textureName += "_right.png";
		break;
	}
	snakeSprite = new GameCell(textureName, position, isPassable);
	this->direction = direction;
}

SnakeCell::~SnakeCell() {
	delete snakeSprite;
}


Snake::Snake()
{
	length = 3;
	head_direction = Direction::RIGHT;
	positions.clear();
	positions.push_back(sf::Vector2f(5 * 40, 7 * 40));
	positions.push_back(sf::Vector2f(4 * 40, 7 * 40));
	positions.push_back(sf::Vector2f(3 * 40, 7 * 40));
	
	directions.clear();
	directions.push_back(Direction::RIGHT);
	directions.push_back(Direction::RIGHT);
	directions.push_back(Direction::RIGHT);
	buildBody();
}

void Snake::buildBody() {
	for (auto cell : body)
		delete cell;
	body.clear();
	
	body.push_back(new SnakeCell("images/snake_head", positions[0], false, directions[0]));
	for (unsigned int i = 1; i < length - 1; i++) {
			
		if (directions[i] == Direction::UP) {
			if (directions[i - 1] == Direction::UP) {
				body.push_back(new SnakeCell("images/snake_back", positions[i], false, directions[i]));
			}
			else if (directions[i - 1] == Direction::LEFT) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::DOWN));
			}
			else if (directions[i - 1] == Direction::RIGHT) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::RIGHT));
			}
		}
		else if (directions[i] == Direction::DOWN) {
			if (directions[i - 1] == Direction::DOWN) {
				body.push_back(new SnakeCell("images/snake_back", positions[i], false, directions[i]));
			}
			else if (directions[i - 1] == Direction::LEFT) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::LEFT));
			}
			else if (directions[i - 1] == Direction::RIGHT) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::UP));
			}
		}
		else if (directions[i] == Direction::LEFT) {
			if (directions[i - 1] == Direction::UP) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::UP));
			}
			else if (directions[i - 1] == Direction::DOWN) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::RIGHT));
			}
			else if (directions[i - 1] == Direction::LEFT) {
				body.push_back(new SnakeCell("images/snake_back", positions[i], false, directions[i]));
			}
		}
		else if (directions[i] == Direction::RIGHT) {
			if (directions[i - 1] == Direction::UP) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::LEFT));
			}
			else if (directions[i - 1] == Direction::DOWN) {
				body.push_back(new SnakeCell("images/snake_turn", positions[i], false, Direction::DOWN));
			}
			else if (directions[i - 1] == Direction::RIGHT) {
				body.push_back(new SnakeCell("images/snake_back", positions[i], false, directions[i]));
			}
		}
	}
	body.push_back(new SnakeCell("images/snake_tail", positions[length - 1], false, directions[length - 2]));
}

void Snake::changeDirection(Direction new_direction) {
	if (head_direction == Direction::UP and new_direction == Direction::DOWN)
		return;
	if (head_direction == Direction::DOWN and new_direction == Direction::UP)
		return;
	if (head_direction == Direction::RIGHT and new_direction == Direction::LEFT)
		return;
	if (head_direction == Direction::LEFT and new_direction == Direction::RIGHT)
		return;
	head_direction = new_direction;
}

void Snake::move() {
	sf::Vector2f new_head_pos;
	switch (head_direction)
	{
	case (Direction::UP):
		new_head_pos = positions[0] + sf::Vector2f(0, -40);
		break;
	case (Direction::DOWN):
		new_head_pos = positions[0] + sf::Vector2f(0, 40);
		break;
	case (Direction::LEFT):
		new_head_pos = positions[0] + sf::Vector2f(-40, 0);
		break;
	case (Direction::RIGHT):
		new_head_pos = positions[0] + sf::Vector2f(40, 0);
		break;
	}
	positions.insert(positions.begin(), new_head_pos);
	positions.pop_back();
	directions.insert(directions.begin(), head_direction);
	directions.pop_back();
	buildBody();
}

void Snake::grow() {
	sf::Vector2f new_head_pos;
	switch (head_direction)
	{
	case (Direction::UP):
		new_head_pos = positions[0] + sf::Vector2f(0, -40);
		break;
	case (Direction::DOWN):
		new_head_pos = positions[0] + sf::Vector2f(0, 40);
		break;
	case (Direction::LEFT):
		new_head_pos = positions[0] + sf::Vector2f(-40, 0);
		break;
	case (Direction::RIGHT):
		new_head_pos = positions[0] + sf::Vector2f(40, 0);
		break;
	}
	positions.insert(positions.begin(), new_head_pos);
	directions.insert(directions.begin(), head_direction);
	length++;
	buildBody();
}


void Snake::draw(sf::RenderWindow& window) {
	for (int i = length - 1; i >= 0; i--) {
		window.draw(body[i]->snakeSprite->sprite);
	}
}