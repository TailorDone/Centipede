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

Mushroom MushroomGrid::operator[](int index) const{
    return mushroomGrid[index];
}

Mushroom& MushroomGrid::operator[](int index){
    return mushroomGrid[index];
}

void MushroomGrid::drawMushrooms(sf::RenderWindow& window) {
    for (Mushroom mushy : mushroomGrid)
        window.draw(mushy.sprite);
}

void MushroomGrid::spawnMushrooms() {
    for (int i = 2; i < 23; i++) {
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

void MushroomGrid::respawn() {
    spawnMushrooms();
}

int MushroomGrid::getSize(){
    return size;
}

bool MushroomGrid::adjacentMushroom(int column, int row){
    for (Mushroom placedMushy : mushroomGrid){
        int placedCol = placedMushy.getColumn();
        int placedRow = placedMushy.getRow();
        if ((placedCol == column - 1 && (placedRow == row - 1 || placedRow == row + 1)) || (placedCol==column && placedRow + 1 == row)){
            return true;
        }
    }
    return false;
}
