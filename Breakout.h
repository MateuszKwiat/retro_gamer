#pragma once;

#include "Game.h"
#include "Paddle.h"
#include "Ball.h"

class Breakout final : public Game {
private:
    Paddle *paddle{};
    Ball *ball{};

private:
    void draw() const override;
    void handleCollisions() const override;
    void handleMovement() const override;
    void initializer() override;
    void initializePaddle();
    void initializeBall();

public:
    Breakout(const int window_width, const int window_height);
    ~Breakout() override;
};
