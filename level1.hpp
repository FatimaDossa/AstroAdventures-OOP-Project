#ifndef LEVEL1_H
#define LEVEL1_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Spaceship.hpp" // Include your Spaceship header
#include "Alien.hpp"     // Include your Alien header
#include "Gem.h"       // Include your Gem header
#include "obstacles.h"  // Include your Asteroid header
#include "player.hpp"    // Include your Player header

class Level1 {
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
    Level1();
    ~Level1();

    Player& getPlayer();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isGameOver();
};

#endif // LEVEL1_H
