#include "map.hpp"

map::map(sf::Texture &t1)
{
for (size_t i = 0; i < 640/30; i++)
{
   R[i].setSize(sf::Vector2f(30.f,30.f));
   R[i].setPosition(sf::Vector2f(i*30,450));
}

}

void map::d1(sf::RenderWindow &w)
{
    for (size_t i = 0; i < 640/30; i++)
    {
     w.draw(R[i]);
        
    }
    
}
