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
    Bat bat(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 25);
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

    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

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
            if (lives < 1) {
                score = 0;
                lives = 3;
            }
        }

        // Handle ball hitting top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
            ball.increaseSpeed(); // Adjust speed using a method
            score++;
        }

        // Handle ball hitting sides
        if (ball.getPosition().left < 0 ||
            ball.getPosition().left + ball.getPosition().width > window.getSize().x)
        {
            ball.reboundSides();
            ball.increaseSpeed(); // Adjust speed using a method
        }

        // Handle ball hitting bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
            ball.increaseSpeed(); // Adjust speed using a method
        }

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }

    return 0;
}
