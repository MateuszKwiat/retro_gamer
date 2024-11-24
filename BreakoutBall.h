#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class BreakoutBall final : public Ball {
private:
    void paddleCollision(const Paddle& paddle);
    void wallCollision(const sf::Vector2u &window_size, Paddle& paddle, bool& can_play);

public:
    BreakoutBall(float radius, float delta_value, const sf::Vector2u& window_size);
    void collisions(const sf::Vector2u &window_size, Paddle &paddle, bool& can_play);
    void brickCollision(Brick& brick);
};
