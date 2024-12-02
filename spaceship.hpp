#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>

class Spaceship {
private:
    sf::Sprite sprite;
    float speed;

public:
    Spaceship(const sf::Texture& texture, float x, float y, float speed);

    void handleInput(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
};

#endif // SPACESHIP_H
