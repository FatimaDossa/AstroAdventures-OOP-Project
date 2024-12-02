#include <SFML/Graphics.hpp>
#include <algorithm>
#include "spaceship.hpp"

// Constructor for the Spaceship class
Spaceship::Spaceship(const sf::Texture& texture, float x, float y, float speed)
    : speed(speed) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(0.01f, 0.01f);
}

// Method to handle input and move the spaceship
void Spaceship::handleInput(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += speed * deltaTime;
    }

    sprite.move(movement);

    // Keep the spaceship within the window bounds
    sf::Vector2f position = sprite.getPosition();
    position.x = std::max(0.0f, std::min(800.0f - sprite.getGlobalBounds().width, position.x));
    position.y = std::max(0.0f, std::min(600.0f - sprite.getGlobalBounds().height, position.y));
    sprite.setPosition(position);
}

// Method to draw the spaceship
void Spaceship::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Method to get the bounds of the spaceship sprite
sf::FloatRect Spaceship::getBounds() const {
    return sprite.getGlobalBounds();
}
