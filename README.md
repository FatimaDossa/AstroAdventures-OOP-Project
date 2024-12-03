# AstroAdventures
Astro Adventure is an exciting, space-themed adventure game that immerses players in a quest to discover aliens in outer space. Navigate through the vast cosmos while avoiding meteors, black holes, and other cosmic dangers, all while collecting valuable gems. With vibrant visuals and engaging gameplay, this single-player game offers a fun and challenging experience for players of all ages.

# Objectives
Create a space-themed adventure game with vibrant visuals and intuitive gameplay.
Implement astronaut navigation, obstacle avoidance, and item collection mechanics.
Utilize object-oriented programming principles and SFML for game rendering.

# Features
Two Levels:
Level 1: Asteroid Belt, where players dodge asteroids while collecting gems.
Level 2: Black Hole Zone, where black holes act as traps, ending the game if the player gets too close.
Obstacles: Asteroids in Level 1 and black holes in Level 2.
Items: Collectible gems that contribute to the player's score.
Timer: A 100-second countdown adds urgency to the game.
Game Over: The game ends if the astronaut collides with an obstacle or the timer runs out.

# How to Run the Game
Open the project in Visual Studio Code.

Go to the .vscode folder and update the path of the compiler in c_cpp_properties.json.

In the VSCode terminal, execute the following command to compile and create the executable:

g++ final.cpp -I"C:/mingw64/include" -L"C:/mingw64/lib" -lsfml-graphics -lsfml-window -lsfml-system
After compiling, run the game by executing the following command:
./final.exe
