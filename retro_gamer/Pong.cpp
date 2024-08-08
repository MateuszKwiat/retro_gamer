#include "Pong.h"

Pong::Pong() {
	window = new sf::RenderWindow(sf::VideoMode(200, 200), "Pong");
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

        window->display();
    }
}