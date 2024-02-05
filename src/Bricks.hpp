//
//  Bricks.hpp
//  testSFML
//
//  Created by Sarah Bateman on 9/20/23.
//

#ifndef Bricks_hpp
#define Bricks_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>





class gameBrick{
private:
    float length;
    float height;
    sf::Color(uint32_t);
    

public:
    int yPosition;
    int xPosition;
    sf::RectangleShape brick;
    
    //to call
    gameBrick();
    sf::RectangleShape createGameBrick(int xPos, int yPos);
    std::vector<sf::RectangleShape> removeItem (std::vector<sf::RectangleShape> vectorOfRecs, int index);

    float getLength() const;
    float getHeight() const;
    void removeBrick (gameBrick brick);
    
};


std::vector<sf::RectangleShape> levelOneBricks ();
std::vector<sf::RectangleShape> levelTwoBricks ();
std::vector<sf::RectangleShape> exampleLevel ();

#endif /* Bricks_hpp */
