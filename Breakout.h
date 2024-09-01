#pragma once;

#include  <SFML/Graphics.hpp>

class Breakout final {
private:
    sf::RenderWindow *window;

public:
    Breakout(const int x_window, const int y_window);
    ~Breakout();
    void run() const;
};
