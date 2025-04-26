#include "Ball.h" // Include the Ball class definition
#include <cstdlib> // For rand()
#include <iostream> // For std::cout

// Constructor
Ball::Ball(float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setRadius(15); // Increased ball size
    m_Shape.setPosition(m_Position);
    m_Shape.setFillColor(Color::White);

    m_Speed = 500.0f; // Increased initial speed
}

// Get the bounding box for collision detection
FloatRect Ball::getPosition() {
    return m_Shape.getGlobalBounds();
}

// Get the shape for rendering
CircleShape Ball::getShape() {
    return m_Shape;
}

// Get current horizontal direction
float Ball::getXVelocity() {
    return m_DirectionX;
}

// Handle collisions
void Ball::reboundSides() {
    m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatOrTop() {
    m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom() {
    m_Position.y = (720 / 2) - m_Shape.getRadius();
    m_Position.x = (1366 / 2) - m_Shape.getRadius();

    // Reset speed to initial value
    m_Speed = 500.0f; // Increased reset speed

    // Randomize direction slightly
    m_DirectionX = (rand() % 2 == 0 ? 0.2f : -0.2f);
    m_DirectionY = -0.2f;

    // Update the shape's position to match the new position
    m_Shape.setPosition(m_Position);

    std::cout << "Ball hit bottom. Reset to center: (" << m_Position.x << ", " << m_Position.y << ")" << std::endl;
}

// Increase ball speed
void Ball::increaseSpeed() {
    m_Speed += 50.0f; // Increment speed by a fixed value
}

// Update position based on direction and time
void Ball::update(Time dt) {
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

    // Gradually increase speed
    m_Speed += 0.1f;

    // Update the shape's position to match the new position
    m_Shape.setPosition(m_Position);
}

