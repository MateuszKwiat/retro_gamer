#pragma once

#include <SFML/Graphics.hpp>

class Game {
protected:
    sf::RenderWindow* window;

private:
    virtual void draw() const = 0;
    virtual void handleCollisions() const = 0;
    virtual void handleMovement() const = 0;
    virtual void initializer() = 0;

public:
    Game(const unsigned int& window_width, const unsigned int& window_height);
    virtual ~Game();
    void run() const;
};