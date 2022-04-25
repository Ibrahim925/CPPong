#include <SFML/Graphics.hpp>
#include <vector>
#include "Entities/Paddle.hpp"
#include "Utils/Common.hpp"
#include "Entities/Ball.hpp"

Ball::Ball(std::vector<Paddle *> _paddles, sf::RenderTarget *_window) : Entity(sf::Vector2f(B_SIZE, B_SIZE), sf::Vector2f(S_WIDTH / 2, S_HEIGHT / 2), sf::Color::White), xDir(1), yDir(1), paddles(_paddles), window(_window)
{
}

void Ball::update()
{
    int dx = B_X_SPEED * this->xDir;
    int dy = B_Y_SPEED * this->yDir;

    int leftEdge = this->getPos().x;
    int topEdge = this->getPos().y;
    int rightEdge = this->getPos().x + B_SIZE;
    int bottomEdge = this->getPos().y + B_SIZE;

    if (leftEdge < 0)
    {
        this->pos.x = S_WIDTH / 2;
        this->pos.y = S_HEIGHT / 2;

        this->paddles[1]->updateScore();

        return;
    }
    else if (rightEdge > S_WIDTH)
    {
        this->pos.x = S_WIDTH / 2;
        this->pos.y = S_HEIGHT / 2;

        this->paddles[0]->updateScore();

        return;
    }

    if (topEdge < 0 || bottomEdge > S_HEIGHT)
    {
        dy *= -1;
        this->yDir *= -1;
    }

    for (Paddle *paddle : this->paddles)
    {
        if (paddle->getRect().getGlobalBounds().intersects(this->getRect().getGlobalBounds()))
        {
            this->xDir *= -1;
            dx *= -1;
        }
    }

    this->addPos(dx, dy);

    this->window->draw(this->getRect());
}