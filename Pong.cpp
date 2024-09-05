#include "Pong.h"

Pong::Pong(const int window_width, const int window_height) : Game(window_width, window_height) {
    constexpr float move_value = 0.35f;
    const auto paddle_window_proportions = sf::Vector2f(1.f / 60.f, 1.f / 6.f);
    const auto paddle_size = sf::Vector2f(static_cast<float>(Game::get_const_window()->getSize().x) * paddle_window_proportions.x,
                                          static_cast<float>(Game::get_const_window()->getSize().y) * paddle_window_proportions.y);

    const auto paddle_position = sf::Vector2f(static_cast<float>(Game::get_const_window()->getSize().x) / 40.f,
                                              static_cast<float>(Game::get_const_window()->getSize().y) / 2.f);

    player_one = new Paddle(move_value, paddle_position, paddle_size, sf::Keyboard::W, sf::Keyboard::S);
    player_two = new Paddle(move_value, sf::Vector2f(static_cast<float>(Game::get_const_window()->getSize().x) - paddle_size.x,
                            paddle_size.y), paddle_size, sf::Keyboard::P, sf::Keyboard::L);

    net = new Net(Game::get_const_window()->getSize());
    ball = new Ball(static_cast<float>(Game::get_const_window()->getSize().x) / 100.f, 0.4f, Game::get_const_window()->getSize());
    player_one_score = new Score(Game::get_const_window()->getSize(), static_cast<float>(Game::get_const_window()->getSize().x) / 4.f);
    player_two_score = new Score(Game::get_const_window()->getSize(), static_cast<float>(Game::get_const_window()->getSize().x)
                                                    - static_cast<float>(Game::get_const_window()->getSize().x) / 4.f);
}

Pong::~Pong() {
    delete player_one;
    delete player_two;
    delete net;
    delete player_one_score;
    delete player_two_score;
    delete ball;
}

void Pong::handle_collisions() const {
    ball->collisions(Game::get_window()->getSize(), *player_one, *player_two, *player_one_score, *player_two_score);

}

void Pong::handle_movement() const {
    player_one->move_vertically(Game::get_window()->getSize().y);
    player_two->move_vertically(Game::get_window()->getSize().y);

    ball->move();
}

void Pong::draw() const {
    Game::get_window()->draw(*player_two);
    Game::get_window()->draw(*player_one);

    for (const auto net_part : net->get_vector()) {
        Game::get_window()->draw(*net_part);
    }
    Game::get_window()->draw(*player_one_score);
    Game::get_window()->draw(*player_two_score);
    Game::get_window()->draw(*ball);
}
