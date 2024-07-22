#include "game.hpp"

GAME::GAME(sf::Texture *texture, sf::Vector2u imagecount, float switchtime) : window(sf::VideoMode(640, 480), "Mario")
{
    texture->setRepeated(true);
    this->imagecount = imagecount;
    this->switchtime = switchtime;

    player.setSize(sf::Vector2f(50, 100));
    player.setTexture(texture);

    uvrect.width = texture->getSize().x / imagecount.x;
    uvrect.height = texture->getSize().y / imagecount.y;
};

void GAME::r()
{
    while (window.isOpen())
    {
        events();
        render();
    }
}

void GAME::inputs(bool up, sf::Keyboard::Key key)
{
}

void GAME::render()
{
    window.clear();
    window.draw(player);
    window.display();
}

void GAME::update(unsigned int row, float dt)
{
    totaltime+=dt;
    if (totaltime>=switchtime)
    {
        totaltime-=switchtime;
    }
    
}

void GAME::events()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            inputs(true, event.key.code);
            break;

        case sf::Event::KeyReleased:
            inputs(false, event.key.code);
            break;

        case sf::Event::Closed:
            window.close();
        }
    }
}