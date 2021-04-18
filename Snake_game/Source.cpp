#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameCell.h"
#include "GameWorld.h"
#include "Snake.h"
#include "Food.h"
#include "GameOver.h"
#include <iostream>

void loadSound(std::string, sf::SoundBuffer&, sf::Sound&);

int main()
{
    int windowHeight = 640;
    int windowWidth = 640;

    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Snake Game");


    sf::SoundBuffer eatingSoundBuffer;
    sf::Sound eating_sound;
    loadSound("../Resources/Audios/eating.wav", eatingSoundBuffer, eating_sound);
    sf::SoundBuffer dyingSoundBuffer;
    sf::Sound dying_sound;
    loadSound("../Resources/Audios/dying.wav", dyingSoundBuffer, dying_sound);

    GameWorld gameWorld = GameWorld();
    Snake snake = Snake();
    Food food = Food();
    GameOver gameOver = GameOver();


    sf::Vector2f food_position = food.getPosition();
    bool isGameOver = false;
    bool foodEaten = false;
    int highScore = 0;
    int score = 0;
    int gameSpeed = 150;

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
             
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                snake.changeDirection( Direction::UP );
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                snake.changeDirection( Direction::DOWN );
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                snake.changeDirection( Direction::LEFT );
            }   
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                snake.changeDirection( Direction::RIGHT );
            }
                
            if (isGameOver and sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                snake = Snake();
                food_position = food.generateFood(snake.positions);
                gameSpeed = 150;
                score = 0;
                isGameOver = false;
            }
        }

        if (isGameOver)
            continue;

        if (foodEaten) {
            snake.grow();
            food_position = food.generateFood(snake.positions);
            foodEaten = false;
        }
        else {
            snake.move();
        }
        

        int x = static_cast<int>(snake.positions[0].x / 40);
        int y = static_cast<int>(snake.positions[0].y / 40);

        if (!gameWorld.cells[x][y]->isPassable or 
            std::find(snake.positions.begin() + 1, snake.positions.end(), snake.positions[0]) != snake.positions.end()) 
        {
            dying_sound.play();
            isGameOver = true;
            if (score > highScore)
                highScore = score;
        }

        if (snake.positions[0] == food_position) {
            eating_sound.play();
            score += 10;
            foodEaten = true;
        }
            
        
        if (score >= 300)
            gameSpeed = 35;
        else if (score >= 250)
            gameSpeed = 50;
        else if (score >= 150)
            gameSpeed = 75;
        else if (score >= 100)
            gameSpeed = 100;
        else if (score >= 50)
            gameSpeed = 150;
        

        sf::sleep(sf::milliseconds(gameSpeed));

        window.clear();

        gameWorld.draw(window);
        
        snake.draw(window);

        if (!foodEaten) {
            food.draw(window);
        }

        if (isGameOver) {
            gameOver.draw(window, highScore, score);
        }

        window.display();
    }

    return 0;
}



void loadSound(std::string fileName, sf::SoundBuffer& soundBuffer, sf::Sound& sound) {
    if (!soundBuffer.loadFromFile(fileName))
        std::cerr << "Couldn't find the file: " << fileName << std::endl; 
    sound.setBuffer(soundBuffer);
}