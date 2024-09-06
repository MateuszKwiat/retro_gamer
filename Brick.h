#pragma once

#include <SFML/Graphics.hpp>

class Brick final : public sf::RectangleShape {
private:
    bool in_game;
public:
    explicit Brick(const sf::Vector2f& size);
    bool inGame() const {return in_game;}
    void setInGame(const bool in_game) {this->in_game = in_game;};
};