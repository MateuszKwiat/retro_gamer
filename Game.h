#pragma once

#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow* window;

    virtual void draw() const = 0;
    virtual void handle_collisions() const = 0;
    virtual void handle_movement() const = 0;

public:
    Game(const unsigned int& window_width, const unsigned int& window_height);
    virtual ~Game();
    void run() const;
};