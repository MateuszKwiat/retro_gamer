#pragma once

#include "Ball.h"
#include "Paddle.h"

class BreakoutBall final : public Ball {
private:
    void paddleCollision(const Paddle& paddle);
    void wallCollision(const sf::Vector2u &window_size);

public:
    BreakoutBall(const float radius, const float delta_value, const sf::Vector2u& window_size);
    void collisions(const sf::Vector2u& window_size, const Paddle& paddle);
};