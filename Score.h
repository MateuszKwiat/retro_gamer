#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Score : public sf::Text {
private:
    int score;
    sf::Font font;

public:
    Score(const sf::Vector2u& window_size, const sf::Vector2f& position, const std::string& text, int starting_score);
    virtual bool reachedScore() const = 0;
    int operator++(int);
    int operator--(int);
};