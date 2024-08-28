#include <SFML/Graphics.hpp>
#include <math.h>

class collsion
{
public:
    sf::RectangleShape r1;
    sf::RectangleShape r2;
    collsion();
    int check_rr(sf::RectangleShape &r1, sf::RectangleShape &r2);
};
