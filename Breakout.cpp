#include "Breakout.h"

Breakout::Breakout(const int x_window, const int y_window) {
    window = new sf::RenderWindow(sf::VideoMode(x_window, y_window),
        "Breakout", sf::Style::Default);
}

Breakout::~Breakout() {
    delete window;
}

void Breakout::run() const {
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Escape))
                window->close();
        }


        window->clear();
        window->display();
    }
}