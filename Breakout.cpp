#include "Breakout.h"

Breakout::Breakout(const int window_width, const int window_height, const sf::Keyboard::Key game_start_key) :
Game(window_width, window_height, game_start_key) {
    this->initializer();
}

void Breakout::initializer() {
    this->initializePaddle();
    this->initializeBall();
    this->initializeBricks();
}

void Breakout::initializePaddle() {
    constexpr float move_value = 3.35f;
    const auto paddle_window_proportions = sf::Vector2f(1.f / 10.f, 1.f / 35.f);
    const auto paddle_size = sf::Vector2f(static_cast<float>(Game::window->getSize().x) * paddle_window_proportions.x,
                                          static_cast<float>(Game::window->getSize().y) * paddle_window_proportions.y);

    const auto paddle_position = sf::Vector2f(static_cast<float>(Game::window->getSize().x) / 2.f,
                                              static_cast<float>(Game::window->getSize().y) - paddle_size.y * 2.f);

    paddle = new Paddle(move_value, paddle_position, paddle_size, sf::Keyboard::Left, sf::Keyboard::Right);
}

void Breakout::initializeBall() {
    const float ball_radius = static_cast<float>(Game::window->getSize().x) / 100.f;
    constexpr float delta_value = 3.3f;

    ball = new BreakoutBall(ball_radius, delta_value, Game::window->getSize());
}

void Breakout::initializeBricks() {
    const auto brick_size = sf::Vector2f((static_cast<float>(Game::window->getSize().x) - 9.f) / 10.f,
        ((static_cast<float>(Game::window->getSize().y) / 3.f) - 4.f) / 7.f);
    bricks = new BricksVector(brick_size);
}

Breakout::~Breakout() {
    delete paddle;
    delete bricks;
}

void Breakout::handleCollisions() {
    ball->collisions(Game::window->getSize(), *paddle, can_play);
    for (const auto brick : bricks->getVector())
        if (brick->inGame())
            ball->brickCollision(*brick);
}

void Breakout::handleMovement() const {
    paddle->moveHorizontally(Game::window->getSize().x);
    ball->move();
}

void Breakout::handleEndGame() const {

}

void Breakout::draw() const {
    Game::window->draw(*paddle);
    Game::window->draw(*ball);
    for (const auto brick : bricks->getVector())
        if (brick->inGame())
            Game::window->draw(*brick);
}
