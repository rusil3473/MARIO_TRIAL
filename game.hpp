#include <SFML/Graphics.hpp>
// #include "camera.hpp"

class GAME
{
private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::IntRect uvrect;
    sf::Vector2u current_img;

private:
    sf::Vector2u imagecount;
    bool up, down, right, left;
    float switchtime;
    float totaltime;

public:
    float speed=48;

    GAME(sf::Texture *texture, sf::Vector2u imagecount, float switchtime);
    void r();
    unsigned int row = 2;
    void inputs(float dt);
    void render();
    void update(unsigned int &row, float dt, bool faceright, bool faceleft);
    void draw()
    {
        window.draw(player);
    };
};
