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

class CentipedeSegment{
public:
    CentipedeSegment();
    CentipedeSegment(int i);
    sf::CircleShape segment;
    void moveRight(sf::Time dt);
    void moveLeft(sf::Time dt);
    void moveDown();
    bool movingRight;
    //sf::CircleShape head;
private:
};

class Centipede {
public:
    std::vector<CentipedeSegment> centipede;
    Centipede();
    Centipede(int length);
    void move(sf::Time dt);
    void drawCentipede(sf::RenderWindow& window);
    CentipedeSegment operator[](int index) const;
    CentipedeSegment& operator[](int index);
private:
    int bodyLength = 10;
};



#endif /* Centipede_hpp */
