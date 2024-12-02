#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>

class Player {
private:
    int health;
    int score;
    bool won;

public:
    Player();

    void collectGem();
    void hitObstacle();
    void winGame();

    int getHealth() const;
    int getScore() const;
    bool isAlive() const;
    bool hasWon() const;

    void displayStats(sf::RenderWindow& window, sf::Font& font);
};

#endif // PLAYER_H
