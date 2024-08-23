#include "Score.h"
#include <iostream>

Score::Score(const sf::Vector2u& window_size, const float x_position) : score(0) {
    if (!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/retro_gamer/PixeloidSans-mLxMm.ttf"))
        std::cerr << "Can't load font";

    this->setFont(font);
    this->setString(std::to_string(score));
    this->setCharacterSize(window_size.y / 10u);
    this->setFillColor(sf::Color::White);
    this->setPosition(sf::Vector2f(x_position - this->getLocalBounds().width / 2.f, static_cast<float>(window_size.y) / 20.f));
}

int Score::operator++(int) {
    const int old_score = score;
    score++;
    this->setString(std::to_string(score));

    return old_score;
}
