#pragma once

#include <SFML/Graphics.hpp>

class GameOver
{
public:
	GameOver();
	void draw(sf::RenderWindow&, int, int);
private:
	sf::Font gameFont;

	sf::Text gameOverText;
	sf::Text highScoreText;
	sf::Text scoreText;
	sf::Text playAgainText;

	sf::RectangleShape background;
};