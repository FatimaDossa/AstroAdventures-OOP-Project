#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
// #include "obstacles.h" //obstacles header file 
#include "obstacles.cpp"
#include "gem.cpp"
#include "alien.cpp" 
#include "spaceship.cpp"
#include "player.cpp"
#include "level1.cpp"
#include "level2.cpp"


using namespace std;
bool isButtonClicked(const sf::RectangleShape& button, const sf::Vector2i& mousePos) {
    return button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}


   // Main Function
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Astro Adventures");

    // Load textures for the menu and levels
    sf::Texture menuTexture, levelsTexture, instructionsTexture, winTexture, loseTexture;
    if (!menuTexture.loadFromFile("ASTRO ADVENTURES.png") ||
        !levelsTexture.loadFromFile("LEVELS.png") ||
        !instructionsTexture.loadFromFile("INSTRUCTIONS_BACKBUTTON.png") ||
        !winTexture.loadFromFile("WIN_SCREEN.jpg") || // Add your win screen image here
        !loseTexture.loadFromFile("LOSE_SCREEN.jpg")) { // Add your lose screen image here
        std::cerr << "Error loading assets!" << std::endl;
        return -1;
    }

    sf::Sprite menuSprite(menuTexture);
    menuSprite.setScale(800.0f / menuTexture.getSize().x, 600.0f / menuTexture.getSize().y);

    sf::Sprite levelsSprite(levelsTexture);
    levelsSprite.setScale(800.0f / levelsTexture.getSize().x, 600.0f / levelsTexture.getSize().y);

    sf::Sprite instructionsSprite(instructionsTexture);
    instructionsSprite.setScale(800.0f / instructionsTexture.getSize().x, 600.0f / instructionsTexture.getSize().y);

    sf::Sprite winSprite(winTexture);
    winSprite.setScale(800.0f / winTexture.getSize().x, 600.0f / winTexture.getSize().y);

    sf::Sprite loseSprite(loseTexture);
    loseSprite.setScale(800.0f / loseTexture.getSize().x, 600.0f / loseTexture.getSize().y);

    // Load font for text
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Define buttons with original positions and transparent fill
    sf::RectangleShape playButton(sf::Vector2f(222, 64));
    playButton.setPosition(300, 428);
    playButton.setFillColor(sf::Color::Transparent);

    sf::RectangleShape instructionsButton(sf::Vector2f(222, 64));
    instructionsButton.setPosition(30, 422);
    instructionsButton.setFillColor(sf::Color::Transparent);

    sf::RectangleShape exitButton(sf::Vector2f(222, 64));
    exitButton.setPosition(570, 416);
    exitButton.setFillColor(sf::Color::Transparent);

    sf::RectangleShape backButton(sf::Vector2f(222, 64));
    backButton.setPosition(300, 508);
    backButton.setFillColor(sf::Color::Transparent);

    sf::RectangleShape level1Button(sf::Vector2f(200, 50));
    level1Button.setPosition(100, 400);
    level1Button.setFillColor(sf::Color::Transparent);

    sf::RectangleShape level2Button(sf::Vector2f(200, 50));
    level2Button.setPosition(500, 400);
    level2Button.setFillColor(sf::Color::Transparent);

    // Define text for restart on win/lose screens
    sf::Text restartText("Press R to Restart", font, 20);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition(300, 600);

    // Game states
    enum GameState { MainMenu, LevelSelect, PlayingLevel1, PlayingLevel2, WinScreen, LoseScreen, Instructions } gameState = MainMenu;

    // Placeholder for Level1 and Level2 classes
    Level1 level1;
    Level2 level2;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Handle button interactions based on game state
                if (gameState == MainMenu) {
                    if (isButtonClicked(playButton, mousePos)) {
                        gameState = LevelSelect;
                    } else if (isButtonClicked(instructionsButton, mousePos)) {
                        gameState = Instructions;
                    } else if (isButtonClicked(exitButton, mousePos)) {
                        window.close();
                    }
                } else if (gameState == LevelSelect) {
                    if (isButtonClicked(level1Button, mousePos)) {
                        gameState = PlayingLevel1;
                    } else if (isButtonClicked(level2Button, mousePos)) {
                        gameState = PlayingLevel2;
                    } else if (isButtonClicked(backButton, mousePos)) {
                        gameState = MainMenu;
                    }
                } else if (gameState == Instructions && isButtonClicked(backButton, mousePos)) {
                    gameState = MainMenu;
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();

        if (gameState == PlayingLevel1 && !level1.isGameOver()) {
            level1.update(deltaTime);

            if (!level1.getPlayer().isAlive()) {
                gameState = LoseScreen;
            } else if (level1.getPlayer().hasWon()) {
                gameState = WinScreen;
            }
        } else if (gameState == PlayingLevel2 && !level2.isGameOver()) {
            level2.update(deltaTime);

            if (!level2.getPlayer().isAlive()) {
                gameState = LoseScreen;
            } else if (level2.getPlayer().hasWon()) {
                gameState = WinScreen;
            }
        }

        // Render based on state
        window.clear();
        bool lev=false;
        if (gameState == MainMenu) {
            window.draw(menuSprite);
            window.draw(playButton);
            window.draw(instructionsButton);
            window.draw(exitButton);
        } else if (gameState == LevelSelect) {
            window.draw(levelsSprite);
            window.draw(level1Button);
            window.draw(level2Button);
            window.draw(backButton);
        } else if (gameState == Instructions) {
            window.draw(instructionsSprite);
            window.draw(backButton);
        } else if (gameState == PlayingLevel1) {
            lev=true;
            level1.draw(window);
        } else if (gameState == PlayingLevel2) {
            lev=false;
            level2.draw(window);
        } else if (gameState == WinScreen) {
            window.draw(winSprite);
            // sf::Text winText("You Win!", font, 40);
            // winText.setFillColor(sf::Color::White);
            // winText.setPosition(300, 100);
           if (lev==true){
            sf::Text scoreText("Your Score: " + std::to_string(level1.getPlayer().getScore()), font, 30);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setPosition(300, 500);

            // window.draw(winText);
            window.draw(scoreText);}

            else if(lev==false) {
            sf::Text scoreText("Your Score: " + std::to_string(level2.getPlayer().getScore()), font, 30);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setPosition(300, 500);

            // window.draw(winText);
            window.draw(scoreText);}

            
            window.draw(restartText);}

        else if (gameState == LoseScreen) {
            window.draw(loseSprite);
            // sf::Text loseText("Game Over!", font, 40);
            // loseText.setFillColor(sf::Color::Red);
            // loseText.setPosition(300, 200);
           if (lev=true){
            sf::Text scoreText("Your Score: " + std::to_string(level1.getPlayer().getScore()), font, 30);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setPosition(300, 500);

            // window.draw(winText);
            window.draw(scoreText);}

            else if(lev=false) {
            sf::Text scoreText("Your Score: " + std::to_string(level2.getPlayer().getScore()), font, 30);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setPosition(300, 500);

            // window.draw(winText);
            window.draw(scoreText);}

            window.draw(restartText);
        }

        // Restart logic
        if ((gameState == WinScreen || gameState == LoseScreen) && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // level1 = Level1(); // Reset Level 1
            Level1 restartleve();
            level2 = Level2(); // Reset Level 2
            gameState = MainMenu;
        }

        window.display();
    }

    return 0;
}
































