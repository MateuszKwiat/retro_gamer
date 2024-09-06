#include "BricksVector.h"

BricksVector::BricksVector(const sf::Vector2f& brick_size) {
    float current_x_position = brick_size.x / 2.f;
    float current_y_position = brick_size.y / 2.f + brick_size.y * 2.f;
    auto brick_index = 0;

    for (auto i = 0; i < 5; i++) {
        for (auto j = 0; j < 10; j++) {
            bricks.push_back(new Brick(brick_size));
            bricks[brick_index]->setPosition(sf::Vector2f(current_x_position, current_y_position));
            current_x_position += brick_size.x + 1.f;
            brick_index++;
        }

        current_y_position += brick_size.y + 1.f;
        current_x_position = brick_size.x / 2.f;
    }
}

BricksVector::~BricksVector() {
    for (const auto brick : bricks)
        delete brick;
}

