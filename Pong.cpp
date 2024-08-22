#include "Pong.h"

Pong::Pong(const int x_window, const int y_window) {
    window = new sf::RenderWindow(sf::VideoMode(x_window, y_window),
        "Pong", sf::Style::Default);
    player_one = new Paddle(0.2f, window->getSize().x / 40.f, window->getSize(),
        sf::Keyboard::W, sf::Keyboard::S);
    player_two = new Paddle(0.2f, window->getSize().x - window->getSize().x / 40.f,
        window->getSize(), sf::Keyboard::P, sf::Keyboard::L);
    net = new Net(window->getSize());
    score = new Score(window->getSize());
    ball = new Ball(window->getSize().x / 100.f, 0.2f, window->getSize());

}

Pong::~Pong() {
    delete player_one;
    delete player_two;
    delete net;
    delete score;
    delete ball;
    delete window;
}

void Pong::run() {
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
        ball->collisions(window->getSize(), *player_one, *player_two);

        window->clear();

        window->draw(*player_two);
        window->draw(*player_one);

        for (auto net_part : net->get_vector()) {
            window->draw(*net_part);
        }

        //window->draw(score->getSprite());
        window->draw(*ball);

        window->display();
    }
}