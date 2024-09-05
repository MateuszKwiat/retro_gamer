#pragma once;

#include "Game.h"
#include "Paddle.h"

class Breakout final : public Game {
private:
    Paddle *paddle;

    void draw() const override;
    void handle_collisions() const override;
    void handle_movement() const override;


public:
    Breakout(const int window_width, const int window_height);
    ~Breakout() override;
};
