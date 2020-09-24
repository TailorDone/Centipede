//
//  PewPew.hpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#ifndef PewPew_hpp
#define PewPew_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

struct PewPew {
    PewPew(float startPosition);
    sf::CircleShape bullet;
    void removePewPews(std::vector<PewPew>& firedShots, int& bulletCount);
    void drawBullet(sf::RenderWindow& window);
    void move(sf::Time dt);
};

#endif /* PewPew_hpp */
