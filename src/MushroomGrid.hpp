//
//  MushroomGrid.hpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/22/20.
//

#ifndef MushroomGrid_hpp
#define MushroomGrid_hpp

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Mushroom.hpp"

class MushroomGrid {
public:
    MushroomGrid();
    std::vector<Mushroom> mushroomGrid;
    Mushroom operator[](int index) const;
    Mushroom& operator[](int index);
    void drawMushrooms(sf::RenderWindow& window);
    void spawnMushrooms();
    void respawn();
    int getSize();
    bool adjacentMushroom(int column, int row);
private:
    int spawnChance = 5;
    int size = 0;
};


#endif /* MushroomGrid_hpp */
