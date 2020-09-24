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

struct CentipedeSegment{
    CentipedeSegment(int i);
    sf::CircleShape segment;
    bool movingRight;
    void moveRight();
    void moveLeft();
    void moveDown();
};

class Centipede {
public:
    Centipede();
    //Rule of 3 declaration
    Centipede(const Centipede& rhs);
    Centipede& operator=(const Centipede& rhs);
    CentipedeSegment operator[](int index) const;
    CentipedeSegment& operator[](int index);
    std::vector<CentipedeSegment> centipede;
    //~Centipede(); We know we should have this...
    int getBodyLength();
    void move(MushroomGrid& mushroomGrid);
    void drawCentipede(sf::RenderWindow& window);
    void setBodyLength(int i);
private:
    int bodyLength = 5;
};

#endif /* Centipede_hpp */
