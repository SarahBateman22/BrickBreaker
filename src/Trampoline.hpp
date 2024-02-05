//
//  Trampoline.hpp
//  testSFML
//
//  Created by Sarah Bateman on 9/20/23.
//

#ifndef Trampoline_hpp
#define Trampoline_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

#endif /* Trampoline_hpp */


class Trampoline
{
private:
    sf::RectangleShape shape_;
    sf::Vector2f position_;
    float Tspeed_= 666.0f;
    
    bool TMovingLeft_ = false;
    bool TMovingRight_ = false;
    
public:
    Trampoline(float startX, float startY);
    
    sf::RectangleShape getshape();
    sf::FloatRect getBounds();
    sf::Vector2f getPosition();
    
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void setPosition(float setX, float setY);
    void move(float x, float y);
    void update(sf::Time dt);
    void Draw(sf::RenderWindow& window);
};
