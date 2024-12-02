// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>
// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>

// class Gem {
// private:
//     sf::Sprite sprite;

// public:
//     Gem(const sf::Texture& sharedTexture, float x, float y) {
//         sprite.setTexture(sharedTexture);
//         sprite.setPosition(x, y);
//         sprite.setScale(0.015f, 0.015f);
//     }

//     static vector<Gem> createGems(const sf::Texture& texture, int count, float spacing, vector<sf::Vector2f>& usedPositions) {
//         vector<Gem> gems;
//         for (int i = 0; i < count; ++i) {
//             float randomX, randomY;
//             bool validPosition = false;

//             while (!validPosition) {
//                 randomX = std::rand() % 750 + 25;
//                 randomY = std::rand() % 550 + 25;
//                 validPosition = isPositionValid(randomX, randomY, usedPositions, spacing);
//             }

//             gems.emplace_back(texture, randomX, randomY);
//             usedPositions.push_back({randomX, randomY});
//         }
//         return gems;
//     }

//     void draw(sf::RenderWindow& window) {
//         window.draw(sprite);
//     }

//     sf::FloatRect getBounds() const {
//         return sprite.getGlobalBounds();
//     }

//     static bool isPositionValid(float x, float y, const vector<sf::Vector2f>& usedPositions, float spacing) {
//         for (const auto& pos : usedPositions) {
//             float distance = sqrt(pow(x - pos.x, 2) + pow(y - pos.y, 2));
//             if (distance < spacing) return false;
//         }
//         return true;
//     }
// };

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "gem.h"

// Constructor for Gem class
Gem::Gem(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(0.015f, 0.015f);
}

// Method to draw the gem
void Gem::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Method to get the bounds of the gem
sf::FloatRect Gem::getBounds() const {
    return sprite.getGlobalBounds();
}

// Static method to create multiple gems
std::vector<Gem> Gem::createGems(const sf::Texture& texture, int count, float spacing, std::vector<sf::Vector2f>& usedPositions) {
    std::vector<Gem> gems;
    for (int i = 0; i < count; ++i) {
        float randomX, randomY;
        bool validPosition = false;

        while (!validPosition) {
            randomX = std::rand() % 750 + 25;
            randomY = std::rand() % 550 + 25;
            validPosition = isPositionValid(randomX, randomY, usedPositions, spacing);
        }

        gems.emplace_back(texture, randomX, randomY);
        usedPositions.push_back({randomX, randomY});
    }
    return gems;
}

// Static method to check if the position is valid
bool Gem::isPositionValid(float x, float y, const std::vector<sf::Vector2f>& usedPositions, float spacing) {
    for (const auto& pos : usedPositions) {
        float distance = std::sqrt(std::pow(x - pos.x, 2) + std::pow(y - pos.y, 2));
        if (distance < spacing) return false;
    }
    return true;
}
