#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Mushroom.hpp"
#include "MushroomGrid.hpp"
#include "Player.hpp"
#include "PewPew.hpp"
#include "Collision.hpp"

int main()
{
    srand (time(NULL));
    sf::Clock clock;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1250, 1000), "Centipede");
    
    
    MushroomGrid mushroomGrid;
    Player playerOne;
    std::vector<PewPew> firedShot;
    int bulletCount = 0;
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            window.setKeyRepeatEnabled(false);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && bulletCount < 11) {
                    float startPosition = playerOne.getXPosition()+25;
                    PewPew newBullet(startPosition);
                    firedShot.push_back(newBullet);
                    bulletCount++;
                }
            }
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
        
        

        for (int i = 0; i < firedShot.size(); i++){
            firedShot[i].move();
            firedShot[i].removePewPews(firedShot, bulletCount);
            firedShot[i].drawBullet(window);
            for (int j = 0; j < mushroomGrid.getSize(); j++){
                if (mushroomGrid[j].bulletCollision(firedShot[i])){
                    firedShot.erase(firedShot.begin() + i);
                    bulletCount--;
                    mushroomGrid[j].mushroomHit();
                    if (mushroomGrid[j].getHealth() == 0) {
                        mushroomGrid[j].sprite.setPosition(sf::Vector2f(-1 * 50, -1 * 50));
                    }
                }
            }
        }
                    
        // end the current frame
        window.display();

    }

    return 0;
}
