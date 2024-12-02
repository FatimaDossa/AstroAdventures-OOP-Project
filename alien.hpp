#ifndef ALIEN_H
#define ALIEN_H

#include <SFML/Graphics.hpp>

class Alien {
private:
    sf::Sprite sprite;
    bool active;
    float activeTime;
    float spawnCooldown;

public:
    Alien(const sf::Texture& texture);

    void update(float deltaTime);
    void spawn();
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool isActive() const;
};

#endif // ALIEN_H
