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
    int score;
    sf::Font font;
    sf::Text scoreText;
    sf::RenderTarget *window;

public:
    Paddle(PaddleType, sf::RenderTarget *);
    void update();
    void updateScore();
};