#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Entities/Paddle.hpp"
#include "Entity.hpp"
#include "Utils/Common.hpp"

Paddle::Paddle(PaddleType _type, sf::RenderTarget *_window) : Entity(sf::Vector2f(P_WIDTH, P_HEIGHT), sf::Vector2f(0, S_HEIGHT / 2), sf::Color::White), type(_type), score(0), window(_window)
{
    if (!this->font.loadFromFile("res/bit5x3.ttf"))
    {
        std::cout << "Error while loading font\n";
    }

    this->scoreText.setFont(this->font);
    this->scoreText.setString(std::to_string(this->score));
    this->scoreText.setCharacterSize(100);

    switch (_type)
    {
    case PaddleType::left:
        this->pos.x = P_PADDING;
        this->scoreText.setPosition(sf::Vector2f((S_WIDTH / 4) - P_WIDTH / 2, 30));
        break;
    case PaddleType::right:
        this->pos.x = S_WIDTH - (P_WIDTH + P_PADDING);
        this->scoreText.setPosition(sf::Vector2f(3 * (S_WIDTH / 4) - P_WIDTH / 2, 30));
        break;
    }
}

void Paddle::update()
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

    this->window->draw(this->getRect());
    this->window->draw(this->scoreText);
}

void Paddle::updateScore()
{
    this->score += 1;
    this->scoreText.setString(std::to_string(this->score));
    this->window->draw(this->scoreText);
}