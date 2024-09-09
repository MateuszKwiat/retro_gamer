#pragma once

#include <SFML/Graphics.hpp>

#include "Score.h"

class PlayerScore final : public Score {
private:
    int max_score;

public:
    PlayerScore(const sf::Vector2u& window_size, const sf::Vector2f& position, const std::string& text, int starting_score, int max_score);
    bool reachedScore() const override;
    void victory(bool won, const sf::Vector2u& window_size = sf::Vector2u(), const std::string& player_name = "");
};



