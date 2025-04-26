#include <sstream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h" // Ensure Ball.h is included

using namespace sf;

int main()
{
    const int SCREEN_WIDTH = 1366;
    const int SCREEN_HEIGHT = 720;
    VideoMode vm(SCREEN_WIDTH, SCREEN_HEIGHT);
    RenderWindow window(vm, "Pong", Style::Default);

    std::cout << "Window created with resolution: " << vm.width << "x" << vm.height << std::endl;

    int score = 0;
    int lives = 3;

    // Create a bat
    Bat bat(SCREEN_WIDTH, SCREEN_HEIGHT - 25);
    // Create a ball
    Ball ball(SCREEN_WIDTH / 2, 0);
    // Create a Text object called HUD
    Text hud;

    Font font;
    if (!font.loadFromFile("fonts/DS-DIGI.TTF")) {
        std::cout << "Error: Could not load font" << std::endl;
        return -1;
    }
    hud.setFont(font);
    hud.setCharacterSize(50);
    hud.setFillColor(Color::White);
    hud.setPosition(20, 20);

    bool isPaused = false; // Add a pause state

    Text pauseText;
    Font pauseFont;
    if (!pauseFont.loadFromFile("fonts/DS-DIGIB.TTF")) {
        std::cout << "Error: Could not load pause font" << std::endl;
        return -1;
    }
    pauseText.setFont(pauseFont);
    pauseText.setCharacterSize(75);
    pauseText.setFillColor(Color::Red);
    pauseText.setString("Game is Paused");
    pauseText.setPosition(SCREEN_WIDTH / 2 - pauseText.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - pauseText.getGlobalBounds().height / 2);

    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
                isPaused = !isPaused; // Toggle pause state
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        if (isPaused) {
            window.clear();
            window.draw(pauseText);
            window.display();
            continue; // Skip the rest of the game loop when paused
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
            bat.moveLeft();
        else
            bat.stopLeft();

        if (Keyboard::isKeyPressed(Keyboard::Right))
            bat.moveRight();
        else
            bat.stopRight();

        // Update the delta time
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        // Update the HUD text
        std::stringstream ss;
        ss << "Score: " << score << "    Lives: " << lives;
        hud.setString(ss.str());

        // Handle ball hitting bottom
        if (ball.getPosition().top > window.getSize().y)
        {
            ball.reboundBottom();
            lives--;
            bat.increaseSpeed(-bat.getSpeed() + 600.0f); // Reset bat speed to initial value
            if (lives < 1) {
                score = 0;
                lives = 3;
            }
        }

        // Handle ball hitting top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
            score++; // Increase score
            ball.increaseSpeed(); // Adjust ball speed
            bat.increaseSpeed(50.0f); // Adjust bat speed by the same increment
        }

        // Handle ball hitting sides
        if (ball.getPosition().left < 0 ||
            ball.getPosition().left + ball.getPosition().width > window.getSize().x)
        {
            ball.reboundSides();
            score++; // Increase score
            ball.increaseSpeed(); // Adjust ball speed
            bat.increaseSpeed(50.0f); // Adjust bat speed by the same increment
        }

        // Handle ball hitting bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
            ball.increaseSpeed(); // Adjust ball speed
            bat.increaseSpeed(50.0f); // Adjust bat speed by the same increment
        }

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }

    return 0;
}
