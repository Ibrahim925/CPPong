#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
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

    Paddle left(PaddleType::left, &window);
    Paddle right(PaddleType::right, &window);
    Ball ball({&left, &right}, &window);

    sf::Font font;

    if (!font.loadFromFile("res/bit5x3.ttf"))
    {
        std::cout << "Error while loading font\n";
    }

    int leftScore = 0;
    int rightScore = 0;

    sf::Text leftText(std::to_string(leftScore), font, 100);
    leftText.setPosition(sf::Vector2f((S_WIDTH / 4) - P_WIDTH / 2, 30));
    sf::Text rightText(std::to_string(rightScore), font, 100);
    rightText.setPosition(sf::Vector2f(3 * (S_WIDTH / 4) - P_WIDTH / 2, 30));

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
        left.update();
        right.update();
        ball.update();
        window.display();
    }
}