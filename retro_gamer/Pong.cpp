#include "Pong.h"

Pong::Pong(int x_window, int y_window) {
	window = new sf::RenderWindow(sf::VideoMode(x_window, y_window), "Pong");
    ball = new Ball(20.f);
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
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->draw(*ball);
        window->display();
    }
}