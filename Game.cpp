#include "Game.h"

Game::Game(const unsigned int& window_width, const unsigned int& window_height, const sf::Keyboard::Key& game_start_key) :
game_start_key(game_start_key), can_play(false) {
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height),
           "Retro Gamer", sf::Style::Default);
    window->setFramerateLimit(120);
}

Game::~Game() {
    delete window;
}

void Game::game_start() {
    if (!can_play && sf::Keyboard::isKeyPressed(game_start_key))
        can_play = true;
}


void Game::run() {
    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Escape))
                window->close();
        }

        this->game_start();

        window->clear();

        if (can_play)
            this->handleMovement();

        this->handleCollisions();
        this->handleEndGame();
        this->draw();

        window->display();
    }
}
