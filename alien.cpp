#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "alien.hpp"

// Constructor for the Alien class
Alien::Alien(const sf::Texture& texture)
    : active(false), activeTime(0), spawnCooldown(0) {
    sprite.setTexture(texture);
    sprite.setScale(0.01f, 0.01f);
}

// Update method to manage alien state
void Alien::update(float deltaTime) {
    if (active) {
        activeTime -= deltaTime;
        if (activeTime <= 0) {
            active = false; // Alien vanishes after activeTime
        }
    } else {
        spawnCooldown -= deltaTime;
        if (spawnCooldown <= 0) {
            spawn(); // Alien spawns after spawnCooldown
        }
    }
}

// Method to spawn the alien
void Alien::spawn() {
    float x = std::rand() % 750 + 25;
    float y = std::rand() % 550 + 25;
    sprite.setPosition(x, y);
    active = true;
    activeTime = 5.0f;      // Alien stays active for 5 seconds
    spawnCooldown = 15.0f; // Cooldown before it spawns again
}

// Method to draw the alien
void Alien::draw(sf::RenderWindow& window) {
    if (active) {
        window.draw(sprite);
    }
}

// Method to get the bounds of the alien sprite
sf::FloatRect Alien::getBounds() const {
    return sprite.getGlobalBounds();
}

// Method to check if the alien is active
bool Alien::isActive() const {
    return active;
}
