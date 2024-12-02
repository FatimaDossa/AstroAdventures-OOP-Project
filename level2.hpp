#ifndef LEVEL2_H
#define LEVEL2_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Spaceship.hpp" // Include your Spaceship header
#include "Alien.hpp"     // Include your Alien header
#include "Gem.h"       // Include your Gem header
#include "obstacles.h"  // Include your Asteroid header
#include "player.hpp"    // Include your Player header

class Level2 {
private:
    sf::Sprite background;
    sf::Texture backgroundTexture, gemTexture, spaceshipTexture, alienTexture, asteroidTexture, debrisTexture;
    std::vector<Gem> gems;
    std::vector<Asteroid> asteroids;
    std::vector<SpaceDebris> debris;
    Spaceship* spaceship;
    Alien* alien;
    Player player;
    sf::Font font;

    bool asteroidCollisionProcessed = false;
    bool debrisCollisionProcessed = false;

public:
    Level2();
    ~Level2();

    Player& getPlayer();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isGameOver();
};

#endif // LEVEL2_H
