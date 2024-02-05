//
//  Test.cpp
//  testSFML
//
//  Created by 陳肜樺 on 9/21/23.
//

#include "Test.hpp"

template<typename T>
void test(const T& expected, const T& actual, const std::string& testName) {
    if (expected == actual) {
        std::cout << testName << " PASSED!" << std::endl;
    } else {
        std::cout << testName << " FAILED!!T_T" << std::endl;
    }
}

// Ball class Test
void testBall() {
    
    Ball ball(300, 400);

    // Test getPosition() function
    sf::FloatRect position = ball.getPosition();
    test(300.0f, position.left, "Ball getPosition() - Left");
    test(400.0f, position.top, "Ball getPosition() - Top");
    

    // Test BounceOffWalls() function
    ball.BounceOffWalls();
    test(-1.0f, ball.getXVelocity(), "Ball BounceOffWalls() - XVelocity");

    // Test missBottom() function
    ball.missBottom();
    position = ball.getPosition();
    test(300.0f, position.left, "Ball missBottom() - Left");
    test(400.0f, position.top, "Ball missBottom() - Top");
    
    
}

// Trampoline class Test
void testTrampoline() {
    Trampoline trampoline(350, 570);

    // Test getPosition() function
    sf::Vector2f trampolinePosition = trampoline.getPosition();
    test(350.0f, trampolinePosition.x, "Trampoline getPosition() - X");
    test(570.0f, trampolinePosition.y, "Trampoline getPosition() - Y");

    // Test moveLeft() function
    trampoline.moveLeft();
    trampolinePosition = trampoline.getPosition();
    test(340.0f, trampolinePosition.x, "Trampoline moveLeft()");

    // Test moveRight() function
    trampoline.moveRight();
    trampolinePosition = trampoline.getPosition();
    test(350.0f, trampolinePosition.x, "Trampoline moveRight()");

    // Test stopLeft() function
    trampoline.stopLeft();
    trampoline.moveLeft();
    trampolinePosition = trampoline.getPosition();
    test(340.0f, trampolinePosition.x, "Trampoline stopLeft()");

    // Test stopRight() function
    trampoline.stopRight();
    trampoline.moveRight();
    trampolinePosition = trampoline.getPosition();
    test(350.0f, trampolinePosition.x, "Trampoline stopRight()");
}



// Bricks class Test
void testBricks() {
    gameBrick brick;

    // Test getLength() function
    test(100.0f, brick.getLength(), "Bricks getLength()");

    // Test getHeight() function
    test(50.0f, brick.getHeight(), "Bricks getHeight()");

    // Test createGameBrick() function
    sf::RectangleShape expected(sf::Vector2f(100, 50));
    expected.setFillColor(sf::Color(140, 90, 77));
    expected.setOutlineColor(sf::Color(61, 38, 37));
    expected.setOutlineThickness(5);
    expected.setPosition(5, 5);

    sf::RectangleShape actual = brick.createGameBrick(5, 5);

    test(expected.getSize(), actual.getSize(), "Bricks createGameBrick() - size");
    test(expected.getFillColor(), actual.getFillColor(), "Bricks createGameBrick() - fill color");
    test(expected.getOutlineColor(), actual.getOutlineColor(), "Bricks createGameBrick() - outline color");
    test(expected.getOutlineThickness(), actual.getOutlineThickness(), "Bricks createGameBrick() - outline thickness");
    test(expected.getPosition(), actual.getPosition(), "Bricks createGameBrick() - position");
}

void testCreateGameBrick() {
  // Expected output
  sf::RectangleShape expected(sf::Vector2f(100, 50));
  expected.setFillColor(sf::Color(140, 90, 77));
  expected.setOutlineColor(sf::Color(61, 38, 37));
  expected.setOutlineThickness(5);
  expected.setPosition(5, 5);

  // Actual output
  sf::RectangleShape actual = gameBrick().createGameBrick(5, 5);

  // Whether the expected output is equal to actual output
  test(expected.getSize(), actual.getSize(), "Test case 1: createGameBrick() - size");
  test(expected.getFillColor(), actual.getFillColor(), "Test case 1: createGameBrick() - fill color");
  test(expected.getOutlineColor(), actual.getOutlineColor(), "Test case 1: createGameBrick() - outline color");
  test(expected.getOutlineThickness(), actual.getOutlineThickness(), "Test case 1: createGameBrick() - outline thickness");
  test(expected.getPosition(), actual.getPosition(), "Test case 1: createGameBrick() - position");
}





void runAllTests() {
    testCreateGameBrick();
    testBall();
    testBricks();
    testTrampoline();
}

