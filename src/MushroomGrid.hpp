//
//  MushroomGrid.hpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/22/20.
//

#ifndef MushroomGrid_hpp
#define MushroomGrid_hpp

#include <SFML/Graphics.hpp>
#include "Mushroom.hpp"

class MushroomGrid {
public:
    MushroomGrid();
    std::vector<Mushroom> mushroomGrid;
    void spawnMushrooms();
    //void respawn();
    void drawMushrooms(sf::RenderWindow& window);
    int getSize();
    Mushroom operator[](int index) const;
    Mushroom& operator[](int index);
    bool adjacentMushroom(int column, int row);
private:
    int spawnChance = 10;
    int size = 0;
};


#endif /* MushroomGrid_hpp */
