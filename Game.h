#pragma once

#include <SFML/Graphics.hpp>

class Game {
protected:
    sf::RenderWindow* window;
    sf::Keyboard::Key game_start_key;
    bool can_play;

private:
    virtual void draw() const = 0;
    virtual void handleCollisions() = 0;
    virtual void handleMovement() const = 0;
    virtual void handleEndGame() const = 0;
    virtual void initializer() = 0;
    void game_start();

public:
    Game(const unsigned int& window_width, const unsigned int& window_height, const sf::Keyboard::Key& game_start_key);
    virtual ~Game();
    void run();
};