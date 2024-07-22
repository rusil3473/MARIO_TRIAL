#include <SFML/Graphics.hpp>
class GAME
{
private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::IntRect uvrect;
    sf::Vector2u current_img;
private:
    sf::Vector2u imagecount;
    bool up,down,right,left;
    void events();
    float switchtime;
    float totaltime;

public:
    GAME(sf::Texture* texture,sf::Vector2u imagecount,float switchtime);
    void r();
    
    void inputs(bool up,sf::Keyboard::Key key);
    void render();
    void update(unsigned int row,float dt);
    void draw(){
        window.draw(player);
    };
};

