//
//  Bricks.cpp
//  testSFML
//
//  Created by Sarah Bateman on 9/20/23.
//

#include "Bricks.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>


//BRICKS ---------------------------------------------------
//brick constructor with no inputs
gameBrick::gameBrick(){
    length = 100;
    height = 50;
    sf::RectangleShape(sf::Vector2f(length, height));
    sf::Color(140, 90, 77);

}

//brick constructor with x and y positions
sf::RectangleShape gameBrick::createGameBrick(int xPos, int yPos)
{
    //gameBrick RectangleShape;
    sf::RectangleShape brick(sf::Vector2f(100.f, 50.f));
    brick.setFillColor(sf::Color(140, 90, 77));
    brick.setOutlineColor(sf::Color(61, 38, 37));
    brick.setOutlineThickness(5);
    brick.setPosition(xPos, yPos);
    return brick;
}

//function to call that creates the example bricks
std::vector<sf::RectangleShape> exampleLevel (){
    std::vector<sf::RectangleShape> bricksVector;
    gameBrick brick3;
    bricksVector.push_back(brick3.createGameBrick(233, 5));
    gameBrick brick4;
    bricksVector.push_back(brick4.createGameBrick(347, 5));
    gameBrick brick5;
    bricksVector.push_back(brick5.createGameBrick(461, 5));
    return bricksVector;
}


//function to call that creates all the bricks with their pos
std::vector<sf::RectangleShape> levelOneBricks (){
    std::vector<sf::RectangleShape> bricksVector;
    gameBrick brick1;
    bricksVector.push_back(brick1.createGameBrick(5, 5));
    gameBrick brick2;
    bricksVector.push_back(brick2.createGameBrick(119, 5));
    gameBrick brick3;
    bricksVector.push_back(brick3.createGameBrick(233, 5));
    gameBrick brick4;
    bricksVector.push_back(brick4.createGameBrick(347, 5));
    gameBrick brick5;
    bricksVector.push_back(brick5.createGameBrick(461, 5));
    gameBrick brick6;
    bricksVector.push_back(brick6.createGameBrick(575, 5));
    gameBrick brick7;
    bricksVector.push_back(brick7.createGameBrick(689, 5));
    gameBrick brick8;
    bricksVector.push_back(brick8.createGameBrick(5, 140));
    gameBrick brick9;
    bricksVector.push_back(brick9.createGameBrick(119, 140));
    gameBrick brick10;
    bricksVector.push_back(brick10.createGameBrick(233, 140));
    gameBrick brick11;
    bricksVector.push_back(brick11.createGameBrick(347, 140));
    gameBrick brick12;
    bricksVector.push_back(brick12.createGameBrick(461, 140));
    gameBrick brick13;
    bricksVector.push_back(brick13.createGameBrick(575, 140));
    gameBrick brick14;
    bricksVector.push_back(brick14.createGameBrick(689, 140));
    return bricksVector;
}

//function to call that creates all the bricks with their pos
std::vector<sf::RectangleShape> levelTwoBricks (){
    std::vector<sf::RectangleShape> bricksVector;
        gameBrick brick1;
        bricksVector.push_back(brick1.createGameBrick(350, 10));
        gameBrick brick2;
        bricksVector.push_back(brick2.createGameBrick(250, 75));
        gameBrick brick3;
        bricksVector.push_back(brick3.createGameBrick(450, 75));
        gameBrick brick4;
        bricksVector.push_back(brick4.createGameBrick(150, 150));
        gameBrick brick5;
        bricksVector.push_back(brick5.createGameBrick(550, 150));
        gameBrick brick6;
        bricksVector.push_back(brick6.createGameBrick(450, 225));
        gameBrick brick7;
        bricksVector.push_back(brick7.createGameBrick(250, 225));
        gameBrick brick8;
        bricksVector.push_back(brick8.createGameBrick(350, 300));
        return bricksVector;
}

void gameBrick::removeBrick (gameBrick brick){
    
}

float gameBrick::getLength() const {
    return length;
}

float gameBrick::getHeight() const {
    return height;
}

std::vector<sf::RectangleShape> removeItem (std::vector<sf::RectangleShape> vectorOfRecs, int index){
    vectorOfRecs.erase(vectorOfRecs.begin() + index);
    return vectorOfRecs;
}
