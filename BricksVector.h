#pragma once

#include "Brick.h"

#include <vector>

class BricksVector final {
private:
    std::vector<Brick*> bricks;

public:
    BricksVector(const sf::Vector2f& brick_size);
    ~BricksVector();
    std::vector<Brick*> getVector() const {return bricks;}
};