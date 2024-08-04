#include "game.hpp"

GAME::GAME(sf::Texture *texture, sf::Vector2u imagecount, float switchtime) : window(sf::VideoMode(640, 480), "Mario")
{
     texture->setRepeated(true);
    this->imagecount = imagecount;
    this->switchtime = switchtime;

    player.setSize(sf::Vector2f(200, 200));
    // player.setOrigin(sf::Vector2f(100,100));
    player.setPosition(sf::Vector2f(320, 240));
    player.setTexture(texture);

    uvrect.width = texture->getSize().x / imagecount.x;
    uvrect.height = texture->getSize().y / imagecount.y;

    
};

void GAME::r()
{
    sf::Clock clock;
    float dt;
    sf::Event event;
    while (window.isOpen())
    {
        dt = clock.restart().asSeconds();
        inputs(dt);
        update(row, dt, right, left);
        render();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }
}

void GAME::inputs(float dt)
{
    sf::Vector2f movement(0.f,0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        right = true;
        left = false;
        movement.x+=speed*dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        left = true;
        right = false;
        movement.x-=speed*dt;
    }
    
    player.move(movement);
}

void GAME::render()
{
    window.clear(sf::Color::Blue);
    window.draw(player);
    window.display();
}

void GAME::update(unsigned int &row, float dt, bool faceright, bool faceleft)
{

    if (faceright)
    {
        row = 3;
        right = false;
    }
    else if (faceleft)
    {
        row = 1;
        left = false;
    }
    else{
        row=2;
    }
    

    if (row == 2)
    {
        current_img.x = 0;
        current_img.y = 2;
    }

    else
    {
        current_img.y = row;
        totaltime += dt;
        if (totaltime >= switchtime)
        {

            totaltime -= switchtime;
            current_img.x++;
            if (current_img.x > imagecount.x)
            {
                current_img.x = 0;
            }
        }
    }

    uvrect.left = uvrect.width * current_img.x;
    uvrect.top = uvrect.height * current_img.y;
    player.setTextureRect(uvrect);
}

