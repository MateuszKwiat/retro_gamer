#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Score final : public sf::Text {
private:
    int score;
    int max_score;
    sf::Font font;

public:
    Score(const sf::Vector2u& window_size, const float x_position, int max_score);
    bool reachedMaxScore() const;
    void victory(const bool won, const sf::Vector2u& window_size = sf::Vector2u(), const std::string& player_name = "");
    int operator++(int);
};