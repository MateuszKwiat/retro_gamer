#pragma once

#include "Game.h"
#include "Paddle.h"
#include "Net.h"
#include "Score.h"
#include "Ball.h"

class Pong final : public Game {
private:
    Paddle* player_one{};
    Paddle* player_two{};
    Net* net{};
    Score* player_one_score{};
    Score* player_two_score{};
    Ball* ball{};

private:
    void draw() const override;
    void handle_collisions() const override;
    void handle_movement() const override;
    void initializer() override;
    void initialize_paddles();
    void initialize_net();
    void initialize_scores();
    void initialize_ball();

public:
    Pong(const int window_width, const int window_height);
    ~Pong() override;
};