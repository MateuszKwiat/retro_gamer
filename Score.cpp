#include "Score.h"
#include <iostream>

Score::Score(const sf::Vector2u& window_size, const float x_position) : score(0) {
    if (!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/retro_gamer/PixeloidSans-mLxMm.ttf"))
        std::cerr << "Can't load font";

    this->setFont(font);
    this->setString(std::to_string(score));
    this->setOrigin(sf::Vector2f(this->getLocalBounds().width / 2.f, this->getLocalBounds().height / 2.f));
    this->setCharacterSize(100);
    this->setFillColor(sf::Color::White);
    this->setPosition(sf::Vector2f(x_position, static_cast<float>(window_size.y) / 20.f));
}