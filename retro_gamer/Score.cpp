#include "Score.h"
#include <iostream>

Score::Score(const sf::Vector2u& window_size) : score(0) {
	sf::Font font;
	if (!font.loadFromFile("ARIAL.TTF"))
		std::cerr << "Can't load font";
	
	text = new sf::Text("aaa", font);

	//this->setFont(font);
	//this->setCharacterSize(30);
	//this->setString("AAAA");
	//this->setString(std::to_string(score));
	//this->setFillColor(sf::Color::White);
	//this->setOrigin(sf::Vector2f(this->getGlobalBounds().getSize().x / 2.f,
	//	this->getGlobalBounds().getSize().y / 2.f));
	//this->setPosition(window_size.x / 4.f, window_size.y / 10);
}