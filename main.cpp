#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(1080, 1080), "Astro Adventures");

    // Load the main texture (image)
    sf::Texture texture;
    if (!texture.loadFromFile("ASTRO ADVENTURES.png"))
        return -1;

    // Create a sprite for the main image and set the texture
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Load the instructions texture (image)
    sf::Texture instructionsTexture;
    if (!instructionsTexture.loadFromFile("INSTRUCTIONS_BACKBUTTON.png"))  // Ensure you have this file
        return -1;

    // Create a sprite for the instructions image and set the texture
    sf::Sprite instructionsSprite;
    instructionsSprite.setTexture(instructionsTexture);

    // Define the "Exit" button coordinates on the image
    sf::Vector2f exitButtonPos(770, 750);  // Top-left corner of the button
    sf::Vector2f exitButtonSize(300, 115);  // Width and height of the button

    // Define the "Instructions" button coordinates
    sf::Vector2f instructionsButtonPos(40, 760);  // Top-left corner of the button
    sf::Vector2f instructionsButtonSize(300, 115);  // Width and height of the button

    // Define the "Back" button coordinates on the instructions page
    sf::Vector2f backButtonPos(405, 915);  // Top-left corner of the back button
    sf::Vector2f backButtonSize(300, 115);  // Width and height of the back button

    // Variable to track if instructions should be displayed
    bool showInstructions = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check for left mouse click
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // Get mouse position relative to the window
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Check if the mouse click is inside the "Exit" button area
                if (mousePos.x >= exitButtonPos.x && mousePos.x <= exitButtonPos.x + exitButtonSize.x &&
                    mousePos.y >= exitButtonPos.y && mousePos.y <= exitButtonPos.y + exitButtonSize.y)
                {
                    // If clicked inside the button area, close the window
                    window.close();
                }

                // Check if the mouse click is inside the "Instructions" button area
                if (mousePos.x >= instructionsButtonPos.x && mousePos.x <= instructionsButtonPos.x + instructionsButtonSize.x &&
                    mousePos.y >= instructionsButtonPos.y && mousePos.y <= instructionsButtonPos.y + instructionsButtonSize.y)
                {
                    // Show the instructions when the button is clicked
                    showInstructions = true;
                }

                // Check if the mouse click is inside the "Back" button area
                if (showInstructions && 
                    mousePos.x >= backButtonPos.x && mousePos.x <= backButtonPos.x + backButtonSize.x &&
                    mousePos.y >= backButtonPos.y && mousePos.y <= backButtonPos.y + backButtonSize.y)
                {
                    // Go back to the main page when the back button is clicked
                    showInstructions = false;
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the main sprite (image) or instructions based on the state
        if (showInstructions)
        {
            window.draw(instructionsSprite);  // Draw the instructions image
            // Optionally, draw the back button here (if you have a visual representation)
        }
        else
        {
            window.draw(sprite);  // Draw the main image
        }

        // Display everything
        window.display();
    }

    return 0;
}
