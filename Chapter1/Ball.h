#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
    Vector2f m_Position;        // Ball's current position
    CircleShape m_Shape;        // Visual representation of the ball
    float m_Speed = 300.0f;     // Speed of the ball

    float m_DirectionX = 0.2f;  // Horizontal movement direction
    float m_DirectionY = 0.2f;  // Vertical movement direction

public:
    // Constructor
    Ball(float startX, float startY);

    // Get the bounding box for collision detection
    FloatRect getPosition();

    // Get the shape for rendering
    CircleShape getShape();

    // Get current horizontal direction
    float getXVelocity();

    // Handle collisions
    void reboundSides();         // Reverse horizontal direction (side walls)
    void reboundBatOrTop();      // Reverse vertical direction (bat or top wall)
    void reboundBottom();        // Reverse vertical direction and reset position (bottom wall)

    // Update position based on direction and time
    void update(Time dt);
};

