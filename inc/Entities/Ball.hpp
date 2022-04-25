#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"
#include "Entities/Paddle.hpp"

class Ball : public Entity
{
private:
    sf::RenderTarget *window;
    int xDir;
    int yDir;
    std::vector<Paddle *> paddles;

public:
    Ball(std::vector<Paddle *>, sf::RenderTarget *);
    void update();
};