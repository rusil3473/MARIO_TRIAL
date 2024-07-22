#include "game.cpp"
int main(){
sf::Texture t1;
t1.loadFromFile("images/texture.jpeg");
//sf::RenderWindow window(sf::VideoMode(640,480),"Mario");
GAME g(&t1,sf::Vector2u(4,9),0.2f);
g.r();




    return 0;
};