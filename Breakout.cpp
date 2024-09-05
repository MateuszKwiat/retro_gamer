#include "Breakout.h"

Breakout::Breakout(const int window_width, const int window_height) : Game(window_width, window_height) {
    constexpr float move_value = 0.35f;

    const auto paddle_window_proportions = sf::Vector2f(1.f / 10.f, 1.f / 35.f);

    const auto paddle_size = sf::Vector2f(static_cast<float>(Game::window->getSize().x) * paddle_window_proportions.x,
                                          static_cast<float>(Game::window->getSize().y) * paddle_window_proportions.y);

    const auto paddle_position = sf::Vector2f(static_cast<float>(Game::window->getSize().x) / 2.f,
                                              static_cast<float>(Game::window->getSize().y) - paddle_size.y * 2.f);

    paddle = new Paddle(move_value, paddle_position, paddle_size, sf::Keyboard::Left, sf::Keyboard::Right);
}

Breakout::~Breakout() {
    delete paddle;
}

void Breakout::handle_collisions() const {

}

void Breakout::handle_movement() const {
    paddle->move_horizontally(Game::window->getSize().x);

}

void Breakout::draw() const {
    Game::window->draw(*paddle);

}
