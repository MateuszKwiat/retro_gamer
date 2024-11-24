#pragma once

#include "Game.h"
#include "Paddle.h"
#include "Net.h"
#include "PlayerScore.h"
#include "PongBall.h"

class Pong final : public Game {
private:
    Paddle* player_one{};
    Paddle* player_two{};
    Net* net{};
    PlayerScore* player_one_score{};
    PlayerScore* player_two_score{};
    PongBall* ball{};

private:
    void draw() const override;
    void handleCollisions() override;
    void handleMovement() const override;
    void handleEndGame() const override;
    void initializer() override;
    void initializePaddles();
    void initializeNet();
    void initializeScores();
    void initializeBall();

public:
    Pong(int window_width, int window_height, sf::Keyboard::Key game_start_key);
    ~Pong() override;
};