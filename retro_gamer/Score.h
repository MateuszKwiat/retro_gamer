#pragma once

#include <SFML/Graphics.hpp>

class Score {
private:
	int score;
	sf::Text* text;

public:
	Score(const sf::Vector2u& window_size);
	sf::Text getSprite() { return *text; }
};

