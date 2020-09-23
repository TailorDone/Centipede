#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Mushroom.hpp"
#include "MushroomGrid.hpp"
#include "Player.hpp"
#include "PewPew.hpp"
#include "Centipede.hpp"
#include "Collision.hpp"

int main()
{
    srand (time(NULL));
    sf::Clock clock;
    // create the window
    sf::RenderWindow window(sf::VideoMode(1250, 1000), "Centipede");
    window.setFramerateLimit(60);

    
    MushroomGrid mushroomGrid;
    Centipede centipede;
    Player playerOne;
    std::vector<PewPew> firedShot;
    int bulletCount = 0;
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        if (centipede.centipede.size() == 0) {
            window.close() ;
            //winScreen == true;
            //return 0;
        }
            
            
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
                    float startPosition = playerOne.getCenter();
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
            if (playerOne.sprite.getPosition().x > 0) {
                playerOne.moveLeft(dt);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // move right...
            if (playerOne.sprite.getPosition().x < 1190) {
                playerOne.moveRight(dt);
            }
        }
        
        playerOne.drawPlayer(window);
        
        centipede.move(dt, mushroomGrid);
        centipede.drawCentipede(window);

        

        for (int i = 0; i < firedShot.size(); i++){
            firedShot[i].move(dt);
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
            Collision centipedeShot;
            if (centipedeShot.BulletCollisionTest(centipede[0].segment, firedShot[i].bullet)){
                firedShot.erase(firedShot.begin() + i);
                bulletCount--;
                centipede.centipede.pop_back();
            }
        }
                    
        // end the current frame
        window.display();

    }
    

    return 0;
}
