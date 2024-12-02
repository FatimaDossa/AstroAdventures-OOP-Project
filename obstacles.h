

#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <SFML/Graphics.hpp>
#include <vector>

class Obstacles {
public:
    Obstacles(const sf::Texture& sharedTexture, float x, float y, float scaleX = 1.0f, float scaleY = 1.0f);

    virtual void update(float deltaTime) = 0;
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

protected:
    sf::Sprite sprite;
};

class Asteroid : public Obstacles {
public:
    Asteroid(const sf::Texture& sharedTexture, float x, float y, float speed);

    void update(float deltaTime) override;

private:
    float speed; // Private attribute for Asteroid
};

class SpaceDebris : public Obstacles {
public:
    SpaceDebris(const sf::Texture& sharedTexture, float x, float y, float speed);

    void update(float deltaTime) override;

private:
    float speed; // Private attribute for SpaceDebris
};

#endif // OBSTACLES_H