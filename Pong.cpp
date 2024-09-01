#include "Pong.h"

Pong::Pong(const int x_window, const int y_window) {
    window = new sf::RenderWindow(sf::VideoMode(x_window,
                                                y_window),
                                                "Pong",
                                                sf::Style::Default);

    constexpr float move_value = 0.35f;
    const auto paddle_window_proportions = sf::Vector2f(1.f / 60.f, 1.f / 6.f);
    const auto paddle_size = sf::Vector2f(static_cast<float>(window->getSize().x) * paddle_window_proportions.x,
                                          static_cast<float>(window->getSize().y) * paddle_window_proportions.y);

    const auto paddle_position = sf::Vector2f(static_cast<float>(window->getSize().y) / 2.f,
                                              static_cast<float>(window->getSize().x) / 40.f);

    player_one = new Paddle(move_value, paddle_position, paddle_size, sf::Keyboard::W, sf::Keyboard::S);
    player_two = new Paddle(move_value, sf::Vector2f(static_cast<float>(window->getSize().x) - paddle_size.x,
                            paddle_size.y), paddle_size, sf::Keyboard::P, sf::Keyboard::L);

    net = new Net(window->getSize());
    ball = new Ball(static_cast<float>(window->getSize().x) / 100.f, 0.4f, window->getSize());
    player_one_score = new Score(window->getSize(), static_cast<float>(window->getSize().x) / 4.f);
    player_two_score = new Score(window->getSize(), static_cast<float>(window->getSize().x)
                                                    - static_cast<float>(window->getSize().x) / 4.f);
}

Pong::~Pong() {
    delete player_one;
    delete player_two;
    delete net;
    //delete score;
    delete ball;
    delete window;
}

void Pong::run() const {
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Escape))
                window->close();
        }

        player_one->move_vertically(window->getSize().y);
        player_two->move_vertically(window->getSize().y);

        ball->move();
        ball->collisions(window->getSize(), *player_one, *player_two, *player_one_score, *player_two_score);

        window->clear();

        window->draw(*player_two);
        window->draw(*player_one);

        for (const auto net_part : net->get_vector()) {
            window->draw(*net_part);
        }
        window->draw(*player_one_score);
        window->draw(*player_two_score);
        window->draw(*ball);

        window->display();
    }
}
