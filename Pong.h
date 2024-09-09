#pragma once

#include "Game.h"
#include "Paddle.h"
#include "Net.h"
#include "Score.h"
#include "PongBall.h"

class Pong final : public Game {
private:
    Paddle* player_one{};
    Paddle* player_two{};
    Net* net{};
    Score* player_one_score{};
    Score* player_two_score{};
    PongBall* ball{};

private:
    void draw() const override;
    void handleCollisions() const override;
    void handleMovement() const override;
    void handleEndGame() const override;
    void initializer() override;
    void initializePaddles();
    void initializeNet();
    void initializeScores();
    void initializeBall();

public:
    Pong(const int window_width, const int window_height, const sf::Keyboard::Key game_start_key);
    ~Pong() override;
};