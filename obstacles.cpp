#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "obstacles.h"

// Base class for obstacles
Obstacles::Obstacles(const sf::Texture& sharedTexture, float x, float y, float scaleX, float scaleY) {
    sprite.setTexture(sharedTexture);
    sprite.setPosition(x, y);
    sprite.setScale(scaleX, scaleY);
}

void Obstacles::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Obstacles::getBounds() const {
    return sprite.getGlobalBounds();
}

// Asteroid and Debris Obstacles
Asteroid::Asteroid(const sf::Texture& sharedTexture, float x, float y, float speed)
    : Obstacles(sharedTexture, x, y, 0.1f, 0.1f), speed(speed) {}

void Asteroid::update(float deltaTime) {
    sf::Vector2f position = sprite.getPosition();
    position.y += speed * deltaTime;

    if (position.y > 600) {
        position.y = 0;
        position.x = std::rand() % 750 + 25;
    }

    sprite.setPosition(position);
}

SpaceDebris::SpaceDebris(const sf::Texture& sharedTexture, float x, float y, float speed)
    : Obstacles(sharedTexture, x, y, 0.15f, 0.15f), speed(speed) {}

void SpaceDebris::update(float deltaTime) {
    sf::Vector2f position = sprite.getPosition();
    position.x += speed * deltaTime;

    if (position.x > 800) {
        position.x = 0;
    } else if (position.x < 0) {
        position.x = 800;
    }

    sprite.setPosition(position);
}
