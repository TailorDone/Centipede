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
    Mushroom(int row, int column);
    sf::RectangleShape sprite;
    
private:
    sf::Vector2f rectSize = {50, 50};
    int xPos, yPos;
    int health = 3;
    int red, green, blue;
    
};

void locateMushrooms(std::vector<std::vector<int>>& mushroomGrid);

void drawMushroom(sf::RenderWindow& window, std::vector<std::vector<int>>& mushroomGrid);


#endif /* Mushroom_hpp */
