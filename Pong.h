#pragma once

#include "Paddle.h"
#include "Net.h"
#include "Score.h"
#include "Ball.h"

class Pong final {
private:
    sf::RenderWindow* window;
    Paddle* player_one;
    Paddle* player_two;
    Net* net;
    Score* player_one_score;
    Score* player_two_score;
    Ball* ball;

public:
    Pong(const int x_window, const int y_window);
    ~Pong();
    void run() const;
};