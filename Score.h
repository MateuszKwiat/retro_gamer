#pragma once

#include <SFML/Graphics.hpp>

class Score final : public sf::Text {
private:
    int score;
    sf::Font font;

public:
    Score(const sf::Vector2u& window_size, const float x_position);
    int operator++(int);
};