//
//  Mushroom.hpp
//  groupProject
//
//  Created by Tyler Speegle on 9/21/20.
//

#ifndef Mushroom_hpp
#define Mushroom_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Mushroom {
public:
    
private:
    int xPos, yPos;
    int health = 3;
    int red, green, blue;
    
};

void createMushrooms(std::vector<std::vector<int>>& mushroomGrid);

sf::RectangleShape drawMushroom(int xPos, int yPos);


#endif /* Mushroom_hpp */
