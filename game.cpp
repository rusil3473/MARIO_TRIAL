#include "game.hpp"

GAME::GAME(sf::Texture *texture, sf::Vector2u imagecount, float switchtime) : window(sf::VideoMode(640, 480), "Mario")
{
    //texture->setRepeated(true);
    this->imagecount = imagecount;
    this->switchtime = switchtime;

    player.setSize(sf::Vector2f(200, 200));
    //player.setOrigin(sf::Vector2f(100,100));
    player.setPosition(sf::Vector2f(320,240));
    player.setTexture(texture);

    uvrect.width = texture->getSize().x / imagecount.x;
    uvrect.height = texture->getSize().y / imagecount.y;
};

void GAME::r()
{   sf::Clock clock;
    float dt;
    
    while (window.isOpen())
    {
       dt=clock.restart().asSeconds();
        events();
        render();
        update(row,dt,true,false);
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

void GAME::update(unsigned int &row, float dt,bool faceright,bool faceleft)
{
    
    if (faceright)
    {
        row=3;
    }
    else if (faceleft)
    {
        row=1;
    }
    
    
    current_img.y=row;
    totaltime+=dt;
    if (totaltime>=switchtime)
    {
       
        
        totaltime-=switchtime;
        current_img.x++;
        if (current_img.x>imagecount.x)
        {
            current_img.x=0;
        
        }  
    }
  
    uvrect.left=uvrect.width*current_img.x;
    uvrect.top=uvrect.height*current_img.y;
    player.setTextureRect(uvrect);
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