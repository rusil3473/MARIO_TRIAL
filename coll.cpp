#include "coll.hpp"

collsion::collsion()
{
    sf::RectangleShape r1, r2;
    r1.setSize(sf::Vector2f(30, 30));
    r1.setPosition(sf::Vector2f(100, 100));
    r1.setOrigin(sf::Vector2f(15, 15));

    r2.setSize(sf::Vector2f(30, 30));
    r2.setPosition(sf::Vector2f(200, 200));
    r2.setOrigin(sf::Vector2f(15, 15));
}

int collsion::check_rr(sf::RectangleShape &r1, sf::RectangleShape &r2)
{
    // to check collsion for top or bottom
    this->r1=r1;
    this->r2=r2;
    float hight_1 = r1.getSize().y;
    float hight_2 = r2.getSize().y;

    float max_dis_in_height = hight_1 + hight_2;

    /*float coordinate_y1, coordinate_y2;
    coordinate_y1 = r1.getPosition().y;
    coordinate_y2 = r2.getPosition().y;

    if (abs(coordinate_y2 - coordinate_y2) < max_dis_in_height)
    {
        return 1;
    }
*/
    // to check collsion in 2 sides left or right

    float length_1 = r1.getSize().x;
    float length_2 = r2.getSize().x;

    float max_dis_in_length = length_1 + length_2;

    float coordinate_x1, coordinate_x2;
    coordinate_x1 = r1.getPosition().x;
    coordinate_x2 = r2.getPosition().x;

    if (abs(coordinate_x2 - coordinate_x2) < max_dis_in_length)
    {
        return 2;
    }

    else
        return 0;
}