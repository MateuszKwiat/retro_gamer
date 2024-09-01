#pragma once;

#include  <SFML/Graphics.hpp>
#include "Paddle.h"

class Breakout final {
private:
    sf::RenderWindow *window;
    Paddle *paddle;

public:
    Breakout(const int x_window, const int y_window);
    ~Breakout();
    void run() const;
};
