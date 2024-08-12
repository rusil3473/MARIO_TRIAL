#include "game.hpp"

GAME::GAME(sf::Texture *texture, sf::Texture *brick_t, sf::Vector2u imagecount, float switchtime) : window(sf::VideoMode(640, 480), "Mario"), g(981), vv(0)
{
    texture->setRepeated(true);
    this->imagecount = imagecount;
    this->switchtime = switchtime;

    player.setSize(sf::Vector2f(60, 60));
    // player.setOrigin(sf::Vector2f(100,100));./t
    player.setPosition(sf::Vector2f(120, 250));
    player.setTexture(texture);

    brick.setSize(sf::Vector2f(30.f, 30.f));

    brick.setTexture(brick_t);

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
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        right = true;
        left = false;
        movement.x += speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        left = true;
        right = false;
        movement.x -= speed * dt;
    }
    if (player.getGlobalBounds().intersects(brick.getGlobalBounds()))
    {
        movement.y = 0;
        canJump = true;
    }

    else
    {

        vv += g * dt;
        movement.y += vv * dt;
    }
    /*  else
      {
          movement.y = 0;
          canJump=true;
      }*/
    if (canJump)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y))
        {
            movement.y -= speed;
            canJump = false;
            vv = 0;
        }
    }
    if (player.getPosition().y > 480)
    {
        window.close();
    }

    player.move(movement);
}

void GAME::render()
{
    window.clear(sf::Color::Blue);
    window.draw(player);
    /* for (size_t i = 0,j=0; i < 200 /16 && j<480/16; i++)
     {

         brick.setPosition(sf::Vector2f(i * brick.getSize().x, 450));
         window.draw(brick);
     }*/
    brick.setPosition(sf::Vector2f(120, 350));
    window.draw(brick);

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
    else
    {
        row = 2;
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
    //  player.setTextureRect(uvrect);
}
