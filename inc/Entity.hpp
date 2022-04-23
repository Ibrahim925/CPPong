#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::Vector2f pos;
    sf::RectangleShape rect;

public:
    Entity(sf::Vector2f, sf::Vector2f, sf::Color);
    sf::Vector2f getPos() const;
    sf::RectangleShape getRect() const;
    void addPos(float, float);
};