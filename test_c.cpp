#include "coll.cpp"
#include <iostream>
bool canmove_x = true, canmove_y = true;
void input(sf::Keyboard::Key k, sf::RectangleShape &r);

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Try collsion det", sf::Style::Close | sf::Style::Titlebar);

    sf::RectangleShape r1, r2;
    r1.setSize(sf::Vector2f(30, 30));
    r1.setPosition(sf::Vector2f(100, 100));
    r1.setOrigin(sf::Vector2f(15, 15));

    r2.setSize(sf::Vector2f(30, 30));
    r2.setPosition(sf::Vector2f(200, 100));
    r2.setOrigin(sf::Vector2f(15, 15));

    collsion c;

    while (window.isOpen())
    {
        sf::Event e;

        while (window.pollEvent(e))

        {
            switch (e.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                input(e.key.code, r1);
            }
        }
        int c1 = c.check_rr(r1, r2);
        switch (c1)
        {
        case 0:
            canmove_x = true;
            canmove_y = true;
            std::cout << "fuck both";
            break;

        case 1:
            canmove_x = true;
            canmove_y = false;
            std::cout << "fuck x soham" << std::endl;
            break;
        case 2:
            canmove_x = false;
            canmove_y = true;
            std::cout << "fuck x"<<std::endl;
            break;
        }
        window.clear();
        window.draw(r1);
        window.draw(r2);
        window.display();
    }

    return 0;
}

void input(sf::Keyboard::Key k, sf::RectangleShape &r)

{
    sf::Vector2f mov(0, 0);
    if (canmove_x)
    {
        if (k == sf::Keyboard::A)
        {
            mov.x -= 30;
        }
        if (k == sf::Keyboard::D)
        {
            mov.x += 30;
        }
    }
    if (canmove_y)
    {
        if (k == sf::Keyboard::W)
        {
            mov.y -= 30;
        }
        if (k == sf::Keyboard::S)
        {
            mov.y += 30;
        }
    }

    r.move(mov);
}
