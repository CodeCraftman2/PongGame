# Pong Game Project based on *Beginning C++ Game Programming* by John Horton

This project is a **Pong Game** developed using **SFML (Simple and Fast Multimedia Library)** in C++. The structure of the project follows chapters from the book *Beginning C++ Game Programming* by John Horton. The `Extra` folder contains additional classes and the main game logic for the Pong game.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Game Structure](#game-structure)
- [Installation](#installation)
- [Build and Run Instructions](#build-and-run-instructions)
- [How to Play](#how-to-play)
- [Acknowledgments](#acknowledgments)

---

## Introduction

**Pong Game** is a classic arcade-style game where two players control paddles to hit a ball back and forth. This project was developed as a learning exercise while following the book *Beginning C++ Game Programming* by John Horton. It uses **SFML** for rendering graphics and handling user input.

The game demonstrates core C++ programming concepts and builds upon them chapter by chapter, with additional enhancements in the `Extra` folder.

---

## Features

- **C++ Core Concepts**: Demonstrates object-oriented programming, functions, and basic game mechanics.
- **Graphics with SFML**: Implements a simple graphical interface using SFML.
- **Interactive Gameplay**: Allows two players to compete in a classic Pong game.
- **Modular Design**: Organized by chapters with additional features in the `Extra` folder.

---

## Game Structure

The game is divided into parts, with each folder representing a stage in development:

1. **Chapter1**: Initial setup of SFML and the game window.
2. **Chapter2**: Adding paddles, the ball, and other game objects.
3. **Extra**: 
   - Additional features and classes:
     - `Ball.cpp` and `Ball.h`: Handles the ball's behavior and movement.
     - `Bat.cpp` and `Bat.h`: Defines the paddle (bat) logic.
     - `Pong.cpp`: Main gameplay logic.
     - `fonts`: Contains font files used in the game.
     - `PongGame`: Compiled executable or build folder.

---

## Installation

To run this game, you will need:
- A C++ compiler (e.g., `g++`).
- **SFML** installed on your system. Follow the official [SFML installation guide](https://www.sfml-dev.org/tutorials/2.5/).

---

## Build and Run Instructions

The `Extra` folder contains the main game logic and files. Use the following commands to compile and run the game:

### Steps to Build and Run:
1. Navigate to the `Extra` folder:
   ```bash
   cd Extra
   ```

2. Compile the code:
   ```bash
   c++ Pong.cpp Ball.cpp Bat.cpp -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o PongGame
   ```

3. Run the game:
   ```bash
   ./PongGame
   ```

---

## How to Play

- **Objective**: Score points by bouncing the ball past your opponent's paddle.
- **Controls**:
  - Player 1: `A` (Move left), `D` (Move Right)


- **Scoring**:
  - A player scores a point when their opponent fails to return the ball.
  - The game resets after each round.

---

## Acknowledgments

This project was inspired by the book *Beginning C++ Game Programming* by John Horton. Special thanks to the authors of SFML for providing a powerful library for multimedia applications.

---

Happy Gaming!
