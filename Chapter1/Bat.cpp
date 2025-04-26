#include "Bat.h"

using namespace sf;

Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(Vector2f(150, 20)); // Width x Height of the bat
	m_Shape.setPosition(m_Position);
	m_Shape.setFillColor(Color::White); // Optional: set bat color
}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveLeft()
{
	m_IsMovingLeft = true;
}

void Bat::moveRight()
{
	m_IsMovingRight = true;
}

void Bat::stopLeft()
{
	m_IsMovingLeft = false;
}

void Bat::stopRight()
{
	m_IsMovingRight = false;
}

void Bat::update(Time dt)
{
	if (m_IsMovingLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_IsMovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}

	// Keep bat within window bounds (assuming screen width = 1366)
	if (m_Position.x < 0)
		m_Position.x = 0;

	if (m_Position.x + m_Shape.getSize().x > 1366)
		m_Position.x = 1366 - m_Shape.getSize().x;

	m_Shape.setPosition(m_Position);
}
