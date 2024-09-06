#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "Score.h"

class PongBall final : public Ball {
private:
    void paddleCollision(const Paddle& player_one, const Paddle& player_two);
    bool wallCollision(const sf::Vector2u& window_size, Score& player_one_score, Score& player_two_score);

public:
    PongBall(const float radius, const float delta_value, const sf::Vector2u&& window_size);
    void collisions(const sf::Vector2u&& window_size, const Paddle& player_one, const Paddle& player_two,
        Score& player_one_score, Score& player_two_score);
    void setDeltas(const float delta) {x_delta = y_delta = delta;}
};