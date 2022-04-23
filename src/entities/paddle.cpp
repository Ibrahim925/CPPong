#include <SFML/Graphics.hpp>
#include "Entities/Paddle.hpp"
#include "Entity.hpp"
#include "Utils/Common.hpp"

Paddle::Paddle(PaddleType _type) : Entity(sf::Vector2f(P_WIDTH, P_HEIGHT), sf::Vector2f(0, S_HEIGHT / 2), sf::Color::White), type(_type)
{
    switch (_type)
    {
    case PaddleType::left:
        this->pos.x = P_PADDING;
        break;
    case PaddleType::right:
        this->pos.x = S_WIDTH - (P_WIDTH + P_PADDING);
        break;
    }
}

void Paddle::update(sf::RenderTarget *window)
{
    int dy = 0;

    switch (this->type)
    {
    case PaddleType::left:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            dy = -P_SPEED;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            dy = P_SPEED;
        break;
    case PaddleType::right:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            dy = -P_SPEED;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            dy = P_SPEED;
        break;
    }

    if (this->pos.y + dy < 0 || this->pos.y + P_HEIGHT + dy > S_HEIGHT)
        dy = 0;

    this->addPos(0, dy);

    window->draw(this->getRect());
}