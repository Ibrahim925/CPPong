#include <SFML/Graphics.hpp>
#include <vector>
#include "Entities/Ball.hpp"
#include "Entities/Paddle.hpp"
#include "Utils/Common.hpp"

void drawNet(sf::RenderTarget *window)
{
    for (int i = 0; i < S_HEIGHT; ++i)
    {
        if (i % 5 == 0)
        {
            sf::RectangleShape rect(sf::Vector2f(2, 2));
            rect.setPosition(S_WIDTH / 2, i);
            window->draw(rect);
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(S_WIDTH, S_HEIGHT), "CPPong");

    Paddle left(PaddleType::left);
    Paddle right(PaddleType::right);
    Ball ball({&left, &right});

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawNet(&window);
        left.update(&window);
        right.update(&window);
        ball.update(&window);
        window.display();
    }
}