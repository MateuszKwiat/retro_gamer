#include "Pong.h"

Pong::Pong(const int window_width, const int window_height) : Game(window_width, window_height) {
    this->initializer();
}

void Pong::initializer() {
    this->initializePaddles();
    this->initializeNet();
    this->initializeScores();
    this->initializeBall();
}

void Pong::initializePaddles() {
    constexpr float move_value = 0.35f;
    const auto paddle_window_proportions = sf::Vector2f(1.f / 60.f, 1.f / 6.f);
    const auto paddle_size = sf::Vector2f(static_cast<float>(Game::window->getSize().x) * paddle_window_proportions.x,
                                          static_cast<float>(Game::window->getSize().y) * paddle_window_proportions.y);

    const auto paddle_position = sf::Vector2f(static_cast<float>(Game::window->getSize().x) / 40.f,
                                              static_cast<float>(Game::window->getSize().y) / 2.f);

    player_one = new Paddle(move_value, paddle_position, paddle_size, sf::Keyboard::W, sf::Keyboard::S);
    player_two = new Paddle(move_value, sf::Vector2f(static_cast<float>(Game::window->getSize().x) - paddle_size.x,
                            paddle_size.y), paddle_size, sf::Keyboard::P, sf::Keyboard::L);

}

void Pong::initializeNet() {
    net = new Net(Game::window->getSize());
}

void Pong::initializeScores() {
    const float score_distance_from_wall = static_cast<float>(Game::window->getSize().x) / 4.f;
    player_one_score = new Score(Game::window->getSize(), score_distance_from_wall);
    player_two_score = new Score(Game::window->getSize(), static_cast<float>(Game::window->getSize().x)
                                                    - score_distance_from_wall);
}

void Pong::initializeBall() {
    const float ball_radius = static_cast<float>(Game::window->getSize().x) / 100.f;
    constexpr float delta_value = 0.4f;

    ball = new Ball(ball_radius, delta_value, Game::window->getSize());
}

Pong::~Pong() {
    delete player_one;
    delete player_two;
    delete net;
    delete player_one_score;
    delete player_two_score;
    delete ball;
}

void Pong::handleCollisions() const {
    ball->collisions(Game::window->getSize(), *player_one, *player_two, *player_one_score, *player_two_score);

}

void Pong::handleMovement() const {
    player_two->moveVertically(Game::window->getSize().y);
    player_one->moveVertically(Game::window->getSize().y);

    ball->move();
}

void Pong::draw() const {
    Game::window->draw(*player_two);
    Game::window->draw(*player_one);

    for (const auto net_part : net->getVector()) {
        Game::window->draw(*net_part);
    }
    Game::window->draw(*player_one_score);
    Game::window->draw(*player_two_score);
    Game::window->draw(*ball);
}
