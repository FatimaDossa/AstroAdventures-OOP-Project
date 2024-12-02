#ifndef GEM_H
#define GEM_H

#include <SFML/Graphics.hpp>
#include <vector>

class Gem {
public:
    Gem(const sf::Texture& texture, float x, float y);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

    static std::vector<Gem> createGems(const sf::Texture& texture, int count, float spacing, std::vector<sf::Vector2f>& usedPositions);

private:
    sf::Sprite sprite;
    static bool isPositionValid(float x, float y, const std::vector<sf::Vector2f>& usedPositions, float spacing);
};

#endif // GEM_H