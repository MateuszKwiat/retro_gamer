#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

class Paddle final : public sf::RectangleShape {
private:
    float move_value;
    float y_position;
    float x_position;

    sf::Keyboard::Key first_key;
    sf::Keyboard::Key second_key;

public:
    Paddle(const float move_value, const float y_position, const float x_position, const sf::Vector2f& size,
        const sf::Keyboard::Key&& first_key, const sf::Keyboard::Key&& second_key);
    void move(const unsigned int y_window);
};