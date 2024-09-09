#include "PlayerScore.h"

// this->setPosition(sf::Vector2f(x_position - this->getLocalBounds().width / 2.f, static_cast<float>(window_size.y) / 20.f));

PlayerScore::PlayerScore(const sf::Vector2u &window_size, const sf::Vector2f &position,
                        const std::string &text, const int starting_score, int max_score) :
Score(window_size, position, text, starting_score), max_score(max_score) {}


bool PlayerScore::reachedMaxScore() const {
    return score >= max_score;
}

void PlayerScore::victory(const bool won, const sf::Vector2u &window_size, const std::string &player_name) {
    if (won) {
        this->setString(player_name + " has won!");
        this->setCharacterSize(window_size.y / 10u);
        this->setOutlineColor(sf::Color::Black);
        this->setOutlineThickness(20.f);
        this->setPosition(static_cast<float>(window_size.x) / 2.f - this->getLocalBounds().width / 2.f,
                        static_cast<float>(window_size.y) / 2.f - this->getLocalBounds().height / 2.f);
    }
    else {
        this->setString("");
    }
}