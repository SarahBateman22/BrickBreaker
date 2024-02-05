//
//  Test.hpp
//  testSFML
//
//  Created by 陳肜樺 on 9/21/23.
//

#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Ball.hpp"
#include "Game.hpp"
#include "Bricks.hpp"
#include "Trampoline.hpp"


template<typename T>
void test(const T& expected, const T& actual, const std::string& testName);
void testCreateGameBrick();
void testBall();
void testBricks();
void runAllTests();
void testTrampoline();



#endif /* Test_hpp */
