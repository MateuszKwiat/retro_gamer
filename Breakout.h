#pragma once;

#include "Game.h"
#include "Paddle.h"
#include "BreakoutBall.h"
#include "BricksVector.h"

class Breakout final : public Game {
private:
    Paddle *paddle{};
    BreakoutBall *ball{};
    BricksVector *bricks{};

private:
    void draw() const override;
    void handleCollisions() const override;
    void handleMovement() const override;
    void handleEndGame() const override;
    void initializer() override;
    void initializePaddle();
    void initializeBall();
    void initializeBricks();

public:
    Breakout(int window_width, int window_height, sf::Keyboard::Key game_start_key);
    ~Breakout() override;
};
