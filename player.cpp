#include <SFML/Graphics.hpp>
#include <string>
#include "player.hpp"

// Constructor for the Player class
Player::Player() : health(3), score(0), won(false) {}

// Method to collect a gem
void Player::collectGem() {
    score += 1;
    health += 1;
}

// Method to hit an obstacle
void Player::hitObstacle() {
    health -= 1;
}

// Method to declare the player as the winner
void Player::winGame() {
    won = true;
}

// Method to get the player's health
int Player::getHealth() const {
    return health;
}

// Method to get the player's score
int Player::getScore() const {
    return score;
}

// Method to check if the player is alive
bool Player::isAlive() const {
    return health > 0;
}

// Method to check if the player has won
bool Player::hasWon() const {
    return won;
}

// Method to display player stats on the window
void Player::displayStats(sf::RenderWindow& window, sf::Font& font) {
    sf::Text healthText("Health: " + std::to_string(health), font, 20);
    sf::Text scoreText("Score: " + std::to_string(score), font, 20);

    healthText.setPosition(10, 10);
    scoreText.setPosition(10, 40);

    window.draw(healthText);
    window.draw(scoreText);
    
    if (won) {
        sf::Text winText("You Win!", font, 30);
        winText.setPosition(350, 280);
        window.draw(winText);
    }
}
