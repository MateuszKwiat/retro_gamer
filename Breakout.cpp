#include "Breakout.h"

Breakout::Breakout(const int x_window, const int y_window) {
    window = new sf::RenderWindow(sf::VideoMode(x_window, y_window),
        "Breakout", sf::Style::Default);

    constexpr float move_value = 0.35f;

    const auto paddle_window_proportions = sf::Vector2f(1.f / 10.f, 1.f / 35.f);

    const auto paddle_size = sf::Vector2f(static_cast<float>(window->getSize().x) * paddle_window_proportions.x,
                                          static_cast<float>(window->getSize().y) * paddle_window_proportions.y);

    const auto paddle_position = sf::Vector2f(static_cast<float>(window->getSize().x) / 2.f,
                                              static_cast<float>(window->getSize().y) - paddle_size.y * 2.f);

    paddle = new Paddle(move_value, paddle_position, paddle_size, sf::Keyboard::Left, sf::Keyboard::Right);
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

        paddle->move_horizontally(window->getSize().x);
        window->draw(*paddle);

        window->display();
    }
}