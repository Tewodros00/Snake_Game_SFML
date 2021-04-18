#include "GameOver.h"
#include <iostream>
#include <string>

GameOver::GameOver() {
	if (!gameFont.loadFromFile("../Resources/Fonts/pixel_font.ttf")) {
		std::cout << "Error: Unable to open font file" << std::endl;
		return;
	}

	gameOverText.setFont(gameFont);
	highScoreText.setFont(gameFont);
	scoreText.setFont(gameFont);
	playAgainText.setFont(gameFont);

	background = sf::RectangleShape(sf::Vector2f(400, 300));
	background.setOutlineThickness(5);
	background.setFillColor(sf::Color(0, 0, 0, 170));
	background.setOutlineColor(sf::Color(25, 25, 25));
	background.setPosition(sf::Vector2f(120, 170));

	gameOverText.setFillColor(sf::Color::Red);
	playAgainText.setFillColor(sf::Color::Cyan);

	gameOverText.setString(sf::String("GAME OVER"));
	playAgainText.setString(sf::String("Press Enter to try again"));

	gameOverText.setCharacterSize(40);
	highScoreText.setCharacterSize(22);
	scoreText.setCharacterSize(22);
	playAgainText.setCharacterSize(16);

	gameOverText.setOutlineThickness(2);
	highScoreText.setOutlineThickness(1.8f);
	scoreText.setOutlineThickness(1.8f);
	playAgainText.setOutlineThickness(1.5);

	gameOverText.setPosition(sf::Vector2f(140, 200));
	highScoreText.setPosition(sf::Vector2f(160, 300));
	scoreText.setPosition(sf::Vector2f(210, 340));
	playAgainText.setPosition(sf::Vector2f(130, 420));

}

void GameOver::draw(sf::RenderWindow& window, int highScore, int score) {
	highScoreText.setString("High Score : " + std::to_string(highScore));
	scoreText.setString("Score : " + std::to_string(score));
	window.draw(background);
	window.draw(gameOverText);
	window.draw(highScoreText);
	window.draw(scoreText);
	window.draw(playAgainText);
}