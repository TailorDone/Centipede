//
//  Mushroom.cpp
//  groupProject
//
//  Created by Tyler Speegle on 9/21/20.
//

#include "Mushroom.hpp"
#include <cmath>

Mushroom::Mushroom(int row, int column) {
    sprite.setSize(rectSize);
    sprite.setPosition(sf::Vector2f(row*50, column*50));
    sprite.setFillColor(sf::Color(100, 250, 50));
}


void drawMushroom(sf::RenderWindow& window, std::vector<std::vector<int>>& mushroomGrid) {
    for (int i = 0; i < mushroomGrid.size(); i++) {
        int xPos = mushroomGrid[i][0];
        int yPos = mushroomGrid[i][1];
        Mushroom mushy(xPos, yPos);
        window.draw(mushy.sprite);
    }
}

void locateMushrooms(std::vector<std::vector<int>>& mushroomGrid) {
    int spawnChance = 5;
    for (int i = 0; i < 25; i++) {
        for (int j = 1; j < 16; j++) {
            int spawnRoll = rand() % 100;
            if (spawnRoll < spawnChance)
                mushroomGrid.push_back({i, j});
        }
    }
}

