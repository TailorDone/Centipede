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
    void drawMushrooms(sf::RenderWindow& window);
private:
    int spawnChance = 5;
    
};

#endif /* MushroomGrid_hpp */
