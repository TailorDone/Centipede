#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Mushroom.hpp"
#include "MushroomGrid.hpp"
#include "Player.hpp"
#include "PewPew.hpp"

int main()
{
    srand (time(NULL));
    sf::Clock clock;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1250, 1000), "Centipede");
    
    MushroomGrid mushroomGrid;
    Player playerOne;
    std::vector<PewPew> firedShot;
    
    bool bulletFired = false;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        mushroomGrid.drawMushrooms(window);
        
        //Player playerOne;
        //Handles Movement of Player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // move left...
            if (playerOne.getXPosition() > 0) {
                playerOne.setXPos(-0.4);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // move right...
            if (playerOne.getXPosition() < 1190) {
                playerOne.setXPos(0.4);
            }
        }
        
        playerOne.drawPlayer(window);
        
        //Shoot Pew Pew
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            bulletFired = true;
            PewPew newBullet;
            newBullet.startXPosition = playerOne.getXPosition()+25;
            firedShot.push_back(newBullet);
        }
        
                  
//
//            int xPosition = playerOne.getXPosition() + 25;
//            for(int i = 880; i > 0; i-=20){
//                PewPew newBullet;
//                newBullet.startXPosition = xPosition;
//                newBullet.startYPosition = i;
//                firedShot.push_back(newBullet);
//            }
            for (PewPew& bullet : firedShot){
                bullet.move();
                bullet.drawBullet(window);
            }
    
            //PewPew newBullet;
            //newBullet.startXPosition = playerOne.getXPosition() + 25;
            //newBullet.drawBullet(window);
        
        //sprite.setPointCount();
     
        
        

        // end the current frame
        window.display();

    }

    return 0;
}
