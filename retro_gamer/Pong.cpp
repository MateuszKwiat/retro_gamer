#include "Pong.h"

Pong::Pong(int x_window, int y_window) {
    window = new sf::RenderWindow(sf::VideoMode(x_window, y_window), 
        "Pong", sf::Style::Fullscreen);
    ball = new Ball(window->getSize().x / 50.f, 0.5f, window->getSize());
}

Pong::~Pong() {
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

        ball->move();
        ball->collision(window->getSize());

        window->clear();
        window->draw(*ball);
        window->display();
    }
}