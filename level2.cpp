#include "level2.hpp"

// Constructor for the Level2 class
Level2::Level2() {
    if (!backgroundTexture.loadFromFile("img/blackhole.jpg")) {
        std::cout << "Failed to load background texture!" << std::endl;
    }
    if (!gemTexture.loadFromFile("img/gem.png")) {
        std::cout << "Failed to load gem texture!" << std::endl;
    }
    if (!spaceshipTexture.loadFromFile("img/spaceship.png")) {
        std::cout << "Failed to load spaceship texture!" << std::endl;
    }
    if (!alienTexture.loadFromFile("img/alien2.png")) {
        std::cout << "Failed to load alien texture!" << std::endl;
    }
    if (!asteroidTexture.loadFromFile("img/asteroid.png")) {
        std::cout << "Failed to load asteroid texture!" << std::endl;
    }
    if (!debrisTexture.loadFromFile("img/debris.png")) {
        std::cout << "Failed to load debris texture!" << std::endl;
    }

    background.setTexture(backgroundTexture);
    background.setScale(800.0f / backgroundTexture.getSize().x, 600.0f / backgroundTexture.getSize().y);

    spaceship = new Spaceship(spaceshipTexture, 400.0f, 300.0f, 200.0f);
    alien = new Alien(alienTexture);

    std::vector<sf::Vector2f> usedPositions = {{400.0f, 300.0f}};
    gems = Gem::createGems(gemTexture, 10, 100.0f, usedPositions);

    for (int i = 0; i < 5; ++i) {
        float x = std::rand() % 750 + 25;
        float y = std::rand() % 550 + 25;
        asteroids.emplace_back(asteroidTexture, x, y, 80.0f);
    }

    for (int i = 0; i < 4; ++i) {
        float x = std::rand() % 750 + 25;
        float y = std::rand() % 550 + 25;
        debris.emplace_back(debrisTexture, x, y, 40.0f);
    }

    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }
}

// Destructor for the Level2 class
Level2::~Level2() {
    delete spaceship;
    delete alien;
}

// Method to get the player reference
Player& Level2::getPlayer() {
    return player;
}

// Method to update the level
void Level2::update(float deltaTime) {
    spaceship->handleInput(deltaTime);
    alien->update(deltaTime);

    // Asteroid and debris collision logic
    bool currentAsteroidCollision = false;
    bool currentDebrisCollision = false;

    for (auto& asteroid : asteroids) {
        asteroid.update(deltaTime);
        if (spaceship->getBounds().intersects(asteroid.getBounds())) {
            currentAsteroidCollision = true;
            if (!asteroidCollisionProcessed) {
                player.hitObstacle();
                asteroidCollisionProcessed = true;
            }
        }
    }

    for (auto& d : debris) {
        d.update(deltaTime);
        if (spaceship->getBounds().intersects(d.getBounds())) {
            currentDebrisCollision = true;
            if (!debrisCollisionProcessed) {
                player.hitObstacle();
                debrisCollisionProcessed = true;
            }
        }
    }

    if (!currentAsteroidCollision) asteroidCollisionProcessed = false;
    if (!currentDebrisCollision) debrisCollisionProcessed = false;

    // Alien collection logic
    if (alien->isActive() && spaceship->getBounds().intersects(alien->getBounds())) {
        player.winGame();
    }

    // Collect gems
    for (auto it = gems.begin(); it != gems.end();) {
        if (spaceship->getBounds().intersects(it->getBounds())) {
            player.collectGem();
            it = gems.erase(it);
        } else {
            ++it;
        }
    }
}

// Method to draw the level
void Level2::draw(sf::RenderWindow& window) {
    window.draw(background);
    for (auto& gem : gems) gem.draw(window);
    for (auto& asteroid : asteroids) asteroid.draw(window);
    for (auto& debris : debris) debris.draw(window);
    alien->draw(window);
    spaceship->draw(window);
    player.displayStats(window, font);
}
bool Level2:: isGameOver() {
        return !player.isAlive() || player.hasWon();
    }