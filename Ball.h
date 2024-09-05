#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
protected:
    float x_delta;
    float y_delta;

    // void paddleCollision(const Paddle& paddle);
    // void wallCollision(const sf::Vector2u &window_size);

public:
    Ball(const float radius, const float delta_value, const sf::Vector2u& window_size);
    void move();
    // void collisions(const sf::Vector2u& window_size, const Paddle& paddle);
};