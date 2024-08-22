#include "Score.h"
#include <iostream>

Score::Score(const sf::Vector2u& window_size) : score(0) {
    if (!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/retro_gamer/Impact.ttf"))
        std::cerr << "Can't load font";

    this->setFont(font);
    this->setString(std::to_string(score));
    this->setOrigin(sf::Vector2f(this->getLocalBounds().width / 2.f, this->getLocalBounds().height / 2.f));
    this->setCharacterSize(30);
    this->setFillColor(sf::Color::White);
    this->setPosition(sf::Vector2f(window_size.x / 4.f, window_size.y / 20.f));


    //this->setFont(font);
    //this->setCharacterSize(30);
    //this->setString("AAAA");
    //this->setString(std::to_string(score));
    //this->setFillColor(sf::Color::White);
    //this->setOrigin(sf::Vector2f(this->getGlobalBounds().getSize().x / 2.f,
    //	this->getGlobalBounds().getSize().y / 2.f));
    //this->setPosition(window_size.x / 4.f, window_size.y / 10);
}