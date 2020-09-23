//
//  MushroomGrid.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/22/20.
//

#include "MushroomGrid.hpp"

MushroomGrid::MushroomGrid() {
    spawnMushrooms();
}

void MushroomGrid::spawnMushrooms() {
    for (int i = 0; i < 25; i++) {
        for (int j = 1; j < 16; j++) {
            int spawnRoll = rand() % 100;
            if (spawnRoll < spawnChance){
                if (!adjacentMushroom(i, j)){
                    Mushroom mushy(i, j);
                    mushroomGrid.push_back(Mushroom {mushy});
                    size++;
                }
            }
        }
    }
}

void MushroomGrid::drawMushrooms(sf::RenderWindow& window) {
    for (Mushroom mushy : mushroomGrid)
        window.draw(mushy.sprite);
}

int MushroomGrid::getSize(){
    return size;
}

Mushroom MushroomGrid::operator[](int index) const{
    return mushroomGrid[index];
}

Mushroom& MushroomGrid::operator[](int index){
    return mushroomGrid[index];
}

bool MushroomGrid::adjacentMushroom(int column, int row){
    for (Mushroom placedMushy : mushroomGrid){
        int placedCol = placedMushy.getColumn();
        int placedRow = placedMushy.getRow();
        if (placedCol == column - 1 && (placedRow == row - 1 || placedRow == row + 1)){
            return true;
        }
    }
    return false;
}
