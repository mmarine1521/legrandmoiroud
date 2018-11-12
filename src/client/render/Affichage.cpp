#include "render.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std ; 
using namespace render ; 

Affichage::Affichage()
{
	sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize); 
}


void AfficheMap (sf::RenderWindow window)
{		
			    while (window.isOpen())
			    {
			    	sf::Texture texture ;
					sf::Texture texture2 ;
					if(!texture.loadFromFile("./res/risk.jpg"))
					{
						//erreur
					}
					texture.setSmooth(true);
					 sf::Sprite sprite ;
					 sprite.setTexture(texture);
					 sprite.setScale(sf::Vector2f(0.9f, 0.9f));
					 sprite.setPosition(sf::Vector2f(0.f, 0.f));
					 		        
					window.clear();
					window.draw(sprite);
					window.display() ; 
			    }
}
