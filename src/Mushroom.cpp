//
//  Mushroom.cpp
//  groupProject
//
//  Created by Tyler Speegle on 9/21/20.
//

#include "Mushroom.hpp"
#include <cmath>


sf::RectangleShape drawMushroom(int xPos, int yPos) {
    sf::RectangleShape block(sf::Vector2f(50, 50));
    block.setPosition(sf::Vector2f(xPos*50, yPos*50));
    block.setFillColor(sf::Color(100, 250, 50));
    return block;
}


void createMushrooms(std::vector<std::vector<int>>& mushroomGrid) {
    int spawnChance = 5;
    for (int i = 0; i < 25; i++) {
        for (int j = 1; j < 16; j++) {
            int spawnRoll = rand() % 100;
            if (spawnRoll < spawnChance)
                mushroomGrid.push_back({i, j});
        }
    }
}

