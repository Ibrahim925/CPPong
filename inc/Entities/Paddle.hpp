#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

enum PaddleType
{
    left,
    right
};

class Paddle : public Entity
{
private:
    PaddleType type;

public:
    Paddle(PaddleType);
    void update(sf::RenderTarget *);
};