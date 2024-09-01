#include "Pong.h"

Pong::Pong(const int x_window, const int y_window) {
    window = new sf::RenderWindow(sf::VideoMode(x_window,
                                                y_window),
                                  "Pong",
                                  sf::Style::Default);

    sf::Vector2f paddle_window_proportions = sf::Vector2f(1.f / 60.f, 1.f / 6.f);
    sf::Vector2f paddle_size = sf::Vector2f(window->getSize().x * paddle_window_proportions.x,
                                            window->getSize().y * paddle_window_proportions.y);

    float y_position = static_cast<float>(window->getSize().y) / 2.f;
    float x_distance_from_wall = static_cast<float>(window->getSize().x) / 40.f;
    float move_value = 0.35f;

    player_one = new Paddle(move_value,
                            y_position,
                            x_distance_from_wall,
                            paddle_size,
                            sf::Keyboard::W,
                            sf::Keyboard::S);

    player_two = new Paddle(move_value,
                            y_position,
                            static_cast<float>(window->getSize().x) - x_distance_from_wall,
                            paddle_size,
                            sf::Keyboard::P,
                            sf::Keyboard::L);

    net = new Net(window->getSize());
    player_one_score = new Score(window->getSize(), static_cast<float>(window->getSize().x) / 4.f);
    player_two_score = new Score(window->getSize(),
        static_cast<float>(window->getSize().x) - static_cast<float>(window->getSize().x) / 4.f);
    ball = new Ball(static_cast<float>(window->getSize().x) / 100.f, 0.4f, window->getSize());
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

        player_one->move(window->getSize().y);
        player_two->move(window->getSize().y);

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
