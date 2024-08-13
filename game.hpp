#include <SFML/Graphics.hpp>
// #include "camera.hpp"
// #include "map.hpp"
class GAME
{
private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::RectangleShape brick;
    sf::IntRect uvrect;
    sf::Vector2u current_img;

    sf::RectangleShape brickBase[21];

private:
    sf::Vector2u imagecount;
    bool up, down, right, left;
    float switchtime;
    float totaltime;
    bool canJump = true;

public:
    float speed = 64;
    float vv;
    float g;
    GAME(sf::Texture *texture, sf::Texture *brick_t, sf::Vector2u imagecount, float switchtime);
    void r();
    unsigned int row = 2;
    void inputs(float dt);
    void render();
    void update(unsigned int &row, float dt, bool faceright, bool faceleft);
    void draw()
    {
        window.draw(player);
    };
    bool why_god_why_itis_always_me();  
};

