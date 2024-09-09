#include "Score.h"
#include <iostream>

Score::Score(const sf::Vector2u& window_size, const sf::Vector2f& position, const std::string& text, const int starting_score) :
score(starting_score) {
    if (!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/retro_gamer/PixeloidSans-mLxMm.ttf"))
        std::cerr << "Can't load font";

    this->setFont(font);
    this->setString(text + std::to_string(score));
    this->setCharacterSize(window_size.y / 15u);
    this->setFillColor(sf::Color::White);
    this->setPosition(sf::Vector2f(position.x - this->getLocalBounds().width / 2.f,
                                    position.y - this->getLocalBounds().height / 2.f));
}

int Score::operator++(int) {
    const int old_score = score;
    score++;
    this->setString(std::to_string(score));

    return old_score;
}

int Score::operator--(int) {
    const int old_score = score;
    score--;
    this->setString(std::to_string(score));

    return old_score;
}