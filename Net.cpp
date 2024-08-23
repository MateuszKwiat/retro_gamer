#include "Net.h"

Net::Net(const sf::Vector2u& window_size) {
    float half_net_part_length = static_cast<float>(window_size.y) / 61.f;
    float temp_y_position = half_net_part_length * 2.f;

    for (int i = 0; i < 20; i++) {
        net_parts.push_back(new sf::RectangleShape(sf::Vector2f(static_cast<float>(window_size.x) / 150.f,
            half_net_part_length * 2.f)));
        net_parts[i]->setFillColor(sf::Color::White);
        net_parts[i]->setOrigin(sf::Vector2f(net_parts[i]->getSize().x / 2.f,
            net_parts[i]->getSize().y / 2.f));
        net_parts[i]->setPosition(sf::Vector2f(static_cast<float>(window_size.x) / 2.f, temp_y_position));
        temp_y_position += half_net_part_length * 3.f;
    }
}