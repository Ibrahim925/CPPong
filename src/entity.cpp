#include <SFML/Graphics.hpp>
#include "Entity.hpp"

Entity::Entity(sf::Vector2f _rect, sf::Vector2f _pos, sf::Color _color) : rect(sf::RectangleShape(_rect)), pos(_pos)
{
    this->rect.setFillColor(_color);
    this->rect.setPosition(this->pos);
}

sf::Vector2f Entity::getPos() const
{
    return this->pos;
}

sf::RectangleShape Entity::getRect() const
{
    return this->rect;
}

void Entity::addPos(float x, float y)
{
    this->pos.x += x;
    this->pos.y += y;
    this->rect.setPosition(this->pos);
}