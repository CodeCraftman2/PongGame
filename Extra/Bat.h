#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat {
private:
    Vector2f m_Position;
    RectangleShape m_Shape;

    float m_Speed = 600.0f;
    bool m_IsMovingLeft = false;
    bool m_IsMovingRight = false;

public:
    Bat(float startX, float startY);

    FloatRect getPosition();       // For collision detection
    RectangleShape getShape();    // To draw the bat

    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();

    void update(Time dt);         // Move the bat each frame

    void increaseSpeed(float increment); // Method to increase bat speed
    float getSpeed() const; // Method to get the current speed of the bat
};

