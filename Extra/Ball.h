#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
    Vector2f m_Position;        // Ball's current position
    CircleShape m_Shape;        // Visual representation of the ball
    float m_Speed = 300.0f;     // Speed of the ball
    int m_HitCount = 0;         // Count of hits to control speed increase

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
    void reboundSides();         
    void reboundBatOrTop();      
    void reboundBottom();        

    // Update position based on direction and time
    void update(Time dt);

    // Increase speed gradually
    void increaseSpeed();
    
    // Reset hit count
    void resetHitCount();
};