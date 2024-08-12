#include "Pong.h"

Pong::Pong(int x_window, int y_window) {
    window = new sf::RenderWindow(sf::VideoMode(x_window, y_window), 
        "Pong", sf::Style::Fullscreen);
    ball = new Ball(window->getSize().x / 100.f, 1.f, window->getSize());
    player_one = new Paddle(1.f, window->getSize().x / 40, window->getSize(),
        sf::Keyboard::W, sf::Keyboard::S);

}

Pong::~Pong() {
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

        ball->move();
        ball->collision(window->getSize());

        window->clear();
        window->draw(*ball);
        window->draw(*player_one);
        window->display();
    }
}