#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Net {
private:
	std::vector<sf::RectangleShape*> net_parts;

public:
	Net(const sf::Vector2u& window_size);
	const std::vector<sf::RectangleShape*>& get_vector() { return net_parts; }
};

