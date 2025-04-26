#include "Ball.h"
#include <iostream>

using namespace sf;

Ball::Ball(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(sf::Vector2f(10, 10)); // Set size using sf::Vector2f
    m_Shape.setPosition(m_Position);

    std::cout << "Ball created at: (" << m_Position.x << ", " << m_Position.y << ")" << std::endl;
}

FloatRect Ball::getPosition()
{
    return m_Shape.getGlobalBounds();
}

RectangleShape Ball::getShape() // Updated return type to RectangleShape
{
    return m_Shape;
}

float Ball::getXVelocity()
{
    return m_DirectionX;
}

void Ball::reboundSides()
{
    m_DirectionX = -m_DirectionX;
    m_Speed *= 1.05f; // Optional: slight speed increase on side hit

    std::cout << "Ball hit side wall. New X direction: " << m_DirectionX << std::endl;
}

void Ball::reboundBatOrTop()
{
    m_DirectionY = -m_DirectionY;
    m_Speed *= 1.1f; // Speed up on bat/top hit

    std::cout << "Ball hit bat or top. New Y direction: " << m_DirectionY << ", Speed: " << m_Speed << std::endl;
}

void Ball::reboundBottom()
{
    m_Position.y = (720 / 2) - m_Shape.getRadius();
    m_Position.x = (1366 / 2) - m_Shape.getRadius();
    m_DirectionY = -m_DirectionY;

    std::cout << "Ball hit bottom. Reset to center: (" << m_Position.x << ", " << m_Position.y << ")" << std::endl;
}

void Ball::update(Time dt)
{
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

    m_Shape.setPosition(m_Position);
}

void Ball::reboundSides()
{
    m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatOrTop()
{
    m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom()
{
    m_Position.y = 0;
    m_Position.x = 500;
    m_DirectionY = -m_DirectionY;
}
