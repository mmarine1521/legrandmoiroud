// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

void testSFML() {
    sf::Texture texture;
}
// Fin test SFML

#include "state.h"
#include "render.h"
#include <iostream>
using namespace state;
using namespace render ;

int main(int argc,char* argv[]){
  sf::RenderWindow window(sf::VideoMode(1300,700), "RISK");

  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed)
    	 window.close();
    }
    sf::Texture texture ;
    sf::Texture texture2 ;
    sf::Texture test ;
    if(!texture.loadFromFile("res/MapJeu2.png")){
      //erreur
    }

    texture2.loadFromFile("res/tank384px.png");
    texture.setSmooth(true);
    texture2.setSmooth(true);
    sf::Sprite sprite ;
    sf::Sprite sprite2 ;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(1.5f, 1.5f));
    sprite2.setTexture(texture2);
    sprite2.setScale(sf::Vector2f(0.08f, 0.08f));
    sprite2.setPosition(sf::Vector2f(245.f, 500.f));

    window.clear();
    //window.draw(sprite);
    //window.draw(sprite2);
    window.display();
  }

  return 0;
}
