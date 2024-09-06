#include "Game.h"

Game::Game(const unsigned int& window_width, const unsigned int& window_height) {
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height),
           "Retro Gamer", sf::Style::Default);
}

Game::~Game() {
    delete window;
}

void Game::run() const {
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

        this->handleMovement();
        this->handleCollisions();
        this->handleEndGame();
        this->draw();

        window->display();
    }
}
