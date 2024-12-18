#pragma once

#include <SFML/Graphics.hpp>

class Paddle final : public sf::RectangleShape {
private:
    float move_value;
    sf::Vector2f position;
    sf::Keyboard::Key first_key;
    sf::Keyboard::Key second_key;

public:
    Paddle(float move_value,
            const sf::Vector2f& position,
            const sf::Vector2f& size,
            const sf::Keyboard::Key&& first_key,
            const sf::Keyboard::Key&& second_key);

    void moveVertically(unsigned int y_window);
    void moveHorizontally(unsigned int x_window);
    void setMoveValue(const float move_value) {this->move_value = move_value;}
    void resetHorizontally(unsigned int x_window);
};