#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "Paddle.h"

class Ball : public sf::CircleShape {
private:
    float x_delta;
    float y_delta;

    void paddleCollision(const Paddle& player_one, const Paddle& player_two);
    bool wallCollision(const sf::Vector2u& window_size);

public:
    Ball(const float radius, const float delta_value, const sf::Vector2u&& window_size);
    void move();
    void collisions(const sf::Vector2u&& window_size,
        const Paddle& player_one, const Paddle& player_two);
};