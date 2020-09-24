//
//  Centipede.hpp
//  groupProject
//
//  Created by Tyler Speegle and Taylor Dunn on 9/22/20.
//

#ifndef Centipede_hpp
#define Centipede_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Mushroom.hpp"
#include "MushroomGrid.hpp"

class CentipedeSegment{
public:
    CentipedeSegment();
    CentipedeSegment(int i);
    sf::CircleShape segment;
    bool MushroomCollision(Mushroom& mushy);
    void moveRight();
    void moveLeft();
    void moveDown();
    bool movingRight;
private:
};

class Centipede {
public:
    Centipede();
    Centipede(int bodyLength);
    
    //Rule of 3 declaration
    Centipede(const Centipede& rhs);
    Centipede& operator=(const Centipede& rhs);
    //~Centipede();
    
    int bodyLength = 5;
    std::vector<CentipedeSegment> centipede;
    
    void move(MushroomGrid& mushroomGrid);
    void drawCentipede(sf::RenderWindow& window);
    void setBodyLength(int i);
    int getBodyLength();
    CentipedeSegment operator[](int index) const;
    CentipedeSegment& operator[](int index);
private:

};



#endif /* Centipede_hpp */
