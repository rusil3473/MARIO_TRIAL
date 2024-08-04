#include "game.cpp"



int main(){
sf::Texture t1;
t1.loadFromFile("images/texture.jpeg");
//vadhae focus na kar kai kaam nu nathi sf::RenderWindow window(sf::VideoMode(640,480),"Mario");z
GAME g(&t1,sf::Vector2u(9,4),0.2f);
g.r();
return 0;
};