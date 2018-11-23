#include "render.h"
#include "engine.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <memory>

using namespace std ; 
using namespace render ; 
using namespace state; 
using namespace engine ; 


void Affichage::draw (sf::RenderTarget& target, sf::RenderStates states) const 
{	
}

void Affichage::AfficheChoixNbrArmees(state::State& state, sf::RenderWindow& window)
		{
						sf::Texture texture ;
						sf::Texture texture2 ;
						sf::Texture texture3 ;
						sf::Texture texture4 ;
						sf::Texture texture5 ;
						sf::Texture texture6 ;
						sf::Texture texture7 ;
						sf::Texture texture8 ;
						sf::Texture texture9 ;
						if(!texture.loadFromFile("./res/nombres/numbers-1.png"))
						{
							//erreur
						}
						if(!texture2.loadFromFile("./res/nombres/numbers-2.png"))
												{
													//erreur
												}
						if(!texture3.loadFromFile("./res/nombres/numbers-3.png"))
												{
													//erreur
												}
						if(!texture4.loadFromFile("./res/nombres/numbers-4.png"))
												{
													//erreur
												}
						if(!texture5.loadFromFile("./res/nombres/numbers-5.png"))
												{
													//erreur
												}
						if(!texture6.loadFromFile("./res/nombres/numbers-6.png"))
												{
													//erreur
												}
						if(!texture7.loadFromFile("./res/nombres/numbers-7.png"))
												{
													//erreur
												}
						if(!texture8.loadFromFile("./res/nombres/numbers-8.png"))
												{
													//erreur
												}
						if(!texture9.loadFromFile("./res/nombres/numbers-9.png"))
												{
													//erreur
												}
						texture.setSmooth(true); texture2.setSmooth(true); texture3.setSmooth(true); texture4.setSmooth(true); texture5.setSmooth(true);
						texture6.setSmooth(true); texture7.setSmooth(true); texture8.setSmooth(true); texture9.setSmooth(true); 
						 sf::Sprite sprite ; sf::Sprite sprite2 ; sf::Sprite sprite3 ; sf::Sprite sprite4 ; sf::Sprite sprite5 ; sf::Sprite sprite6 ;
						 sf::Sprite sprite7 ; sf::Sprite sprite8 ; sf::Sprite sprite9 ;
						 sprite.setTexture(texture);  sprite2.setTexture(texture2);  sprite3.setTexture(texture3);  sprite4.setTexture(texture4);  sprite5.setTexture(texture5);
						 sprite6.setTexture(texture6);  sprite7.setTexture(texture7);  sprite8.setTexture(texture8);  sprite9.setTexture(texture9);
						 
						 sprite.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite.setPosition(sf::Vector2f(1080.f, 150.f));
						 sprite2.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite2.setPosition(sf::Vector2f(1130.f, 150.f));
						 sprite3.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite3.setPosition(sf::Vector2f(1180.f, 150.f));
						 sprite4.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite4.setPosition(sf::Vector2f(1080.f, 220.f));
						 sprite5.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite5.setPosition(sf::Vector2f(1130.f, 220.f));
						 sprite6.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite6.setPosition(sf::Vector2f(1180.f, 220.f));
						 sprite7.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite7.setPosition(sf::Vector2f(1080.f, 290.f));
						 sprite8.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite8.setPosition(sf::Vector2f(1130.f, 290.f));
						 sprite9.setScale(sf::Vector2f(0.50f, 0.50f));
						 sprite9.setPosition(sf::Vector2f(1180.f, 290.f));
						
						window.draw(sprite);
						window.draw(sprite2);
						window.draw(sprite3);
						window.draw(sprite4);
						window.draw(sprite5);
						window.draw(sprite6);
						window.draw(sprite7);
						window.draw(sprite8);
						window.draw(sprite9);						
						
						//window.display() ;
		}
void Affichage::AfficheMap(state::State& state, sf::RenderWindow& window)
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
					
					window.draw(sprite);
					
					Affichage::AfficheArmees(state, window) ;
					Affichage::AfficheNombre(state, window) ;
					
					//window.display() ; 
			    }


void Affichage::AfficheNombre (state::State& state, sf::RenderWindow& window)
		{
			state::ElementTab& tabArmee = state.getArmeeTab();
			std::vector<std::shared_ptr<state::Element>> listeArmee2 = tabArmee.getElementList();
			
		
			state::Element* Nombre = 0 ;
			sf::Texture textureNombre0 ;
			sf::Texture textureNombre1 ; sf::Texture textureNombre6 ; sf::Texture textureNombre11 ; sf::Texture textureNombre16 ;
			sf::Texture textureNombre2 ; sf::Texture textureNombre7 ; sf::Texture textureNombre12 ; sf::Texture textureNombre17 ;
			sf::Texture textureNombre3 ; sf::Texture textureNombre8 ; sf::Texture textureNombre13 ; sf::Texture textureNombre18 ;
			sf::Texture textureNombre4 ; sf::Texture textureNombre9 ; sf::Texture textureNombre14 ; sf::Texture textureNombre19 ;
			sf::Texture textureNombre5 ; sf::Texture textureNombre10 ; sf::Texture textureNombre15 ; sf::Texture textureNombre20 ;
			
			textureNombre0.loadFromFile("./res/nombres/numbers-0.png");
			textureNombre1.loadFromFile("./res/nombres/numbers-1.png");
			textureNombre2.loadFromFile("./res/nombres/numbers-2.png");
			textureNombre3.loadFromFile("./res/nombres/numbers-3.png");
			textureNombre4.loadFromFile("./res/nombres/numbers-4.png");
			textureNombre5.loadFromFile("./res/nombres/numbers-5.png");
			textureNombre6.loadFromFile("./res/nombres/numbers-6.png");
			textureNombre7.loadFromFile("./res/nombres/numbers-7.png");
			textureNombre8.loadFromFile("./res/nombres/numbers-8.png");
			textureNombre9.loadFromFile("./res/nombres/numbers-9.png");
			textureNombre0.setSmooth(true) ; textureNombre3.setSmooth(true) ; textureNombre5.setSmooth(true) ; textureNombre7.setSmooth(true) ;
			textureNombre1.setSmooth(true) ; textureNombre4.setSmooth(true) ; textureNombre6.setSmooth(true) ; textureNombre8.setSmooth(true) ;
			textureNombre2.setSmooth(true) ; textureNombre9.setSmooth(true) ;
			
			
			sf::Sprite nombreCongo ; 
			nombreCongo.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreCongo.setPosition(sf::Vector2f(551.f, 463.f));
			Nombre = listeArmee2[0].get() ;
			int nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreCongo.setTexture(textureNombre0); break; 
			          case 1 : nombreCongo.setTexture(textureNombre1); break;
			          case 2 : nombreCongo.setTexture(textureNombre2); break;
			          case 3 : nombreCongo.setTexture(textureNombre3); break;
			          case 4 : nombreCongo.setTexture(textureNombre4); break;
			          case 5 : nombreCongo.setTexture(textureNombre5); break;
					  case 6 : nombreCongo.setTexture(textureNombre6); break;
					  case 7 : nombreCongo.setTexture(textureNombre7); break;
					  case 8 : nombreCongo.setTexture(textureNombre8); break;
					  case 9 : nombreCongo.setTexture(textureNombre9); break;
					  case 10 : nombreCongo.setTexture(textureNombre10); break;
					  case 11 : nombreCongo.setTexture(textureNombre11); break;
					  case 12 : nombreCongo.setTexture(textureNombre12); break;
					  case 13 : nombreCongo.setTexture(textureNombre13); break;
					  case 14 : nombreCongo.setTexture(textureNombre14); break;
					  case 15 : nombreCongo.setTexture(textureNombre15); break;
					  case 16 : nombreCongo.setTexture(textureNombre16); break;
					  case 17 : nombreCongo.setTexture(textureNombre17); break;
					  case 18 : nombreCongo.setTexture(textureNombre18); break;
					  case 19 : nombreCongo.setTexture(textureNombre19); break;
					  case 20 : nombreCongo.setTexture(textureNombre20); break;
			        }
			sf::Sprite nombreAfriqueDeLEst ; 
			nombreAfriqueDeLEst.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAfriqueDeLEst.setPosition(sf::Vector2f(600.f, 430.f));
			Nombre = listeArmee2[1].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAfriqueDeLEst.setTexture(textureNombre0); break; 
					  case 1 : nombreAfriqueDeLEst.setTexture(textureNombre1); break;
					  case 2 : nombreAfriqueDeLEst.setTexture(textureNombre2); break;
					  case 3 : nombreAfriqueDeLEst.setTexture(textureNombre3); break;
					  case 4 : nombreAfriqueDeLEst.setTexture(textureNombre4); break;
					  case 5 : nombreAfriqueDeLEst.setTexture(textureNombre5); break;
					  case 6 : nombreAfriqueDeLEst.setTexture(textureNombre6); break;
					  case 7 : nombreAfriqueDeLEst.setTexture(textureNombre7); break;
					  case 8 : nombreAfriqueDeLEst.setTexture(textureNombre8); break;
					  case 9 : nombreAfriqueDeLEst.setTexture(textureNombre9); break;
					  case 10 : nombreAfriqueDeLEst.setTexture(textureNombre10); break;
					  case 11 : nombreAfriqueDeLEst.setTexture(textureNombre11); break;
					  case 12 : nombreAfriqueDeLEst.setTexture(textureNombre12); break;
					  case 13 : nombreAfriqueDeLEst.setTexture(textureNombre13); break;
					  case 14 : nombreAfriqueDeLEst.setTexture(textureNombre14); break;
					  case 15 : nombreAfriqueDeLEst.setTexture(textureNombre15); break;
					  case 16 : nombreAfriqueDeLEst.setTexture(textureNombre16); break;
					  case 17 : nombreAfriqueDeLEst.setTexture(textureNombre17); break;
					  case 18 : nombreAfriqueDeLEst.setTexture(textureNombre18); break;
					  case 19 : nombreAfriqueDeLEst.setTexture(textureNombre19); break;
					  case 20 : nombreAfriqueDeLEst.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreEgypte ; 
			nombreEgypte.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreEgypte.setPosition(sf::Vector2f(570.f, 361.f));
			Nombre = listeArmee2[2].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreEgypte.setTexture(textureNombre0); break; 
					  case 1 : nombreEgypte.setTexture(textureNombre1); break;
					  case 2 : nombreEgypte.setTexture(textureNombre2); break;
					  case 3 : nombreEgypte.setTexture(textureNombre3); break;
					  case 4 : nombreEgypte.setTexture(textureNombre4); break;
					  case 5 : nombreEgypte.setTexture(textureNombre5); break;
					  case 6 : nombreEgypte.setTexture(textureNombre6); break;
					  case 7 : nombreEgypte.setTexture(textureNombre7); break;
					  case 8 : nombreEgypte.setTexture(textureNombre8); break;
					  case 9 : nombreEgypte.setTexture(textureNombre9); break;
					  case 10 : nombreEgypte.setTexture(textureNombre10); break;
					  case 11 : nombreEgypte.setTexture(textureNombre11); break;
					  case 12 : nombreEgypte.setTexture(textureNombre12); break;
					  case 13 : nombreEgypte.setTexture(textureNombre13); break;
					  case 14 : nombreEgypte.setTexture(textureNombre14); break;
					  case 15 : nombreEgypte.setTexture(textureNombre15); break;
					  case 16 : nombreEgypte.setTexture(textureNombre16); break;
					  case 17 : nombreEgypte.setTexture(textureNombre17); break;
					  case 18 : nombreEgypte.setTexture(textureNombre18); break;
					  case 19 : nombreEgypte.setTexture(textureNombre19); break;
					  case 20 : nombreEgypte.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreMadagascar ; 
			nombreMadagascar.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreMadagascar.setPosition(sf::Vector2f(635.f, 508.f));
			Nombre = listeArmee2[3].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreMadagascar.setTexture(textureNombre0); break; 
					  case 1 : nombreMadagascar.setTexture(textureNombre1); break;
					  case 2 : nombreMadagascar.setTexture(textureNombre2); break;
					  case 3 : nombreMadagascar.setTexture(textureNombre3); break;
					  case 4 : nombreMadagascar.setTexture(textureNombre4); break;
					  case 5 : nombreMadagascar.setTexture(textureNombre5); break;
					  case 6 : nombreMadagascar.setTexture(textureNombre6); break;
					  case 7 : nombreMadagascar.setTexture(textureNombre7); break;
					  case 8 : nombreMadagascar.setTexture(textureNombre8); break;
					  case 9 : nombreMadagascar.setTexture(textureNombre9); break;
					  case 10 : nombreMadagascar.setTexture(textureNombre10); break;
					  case 11 : nombreMadagascar.setTexture(textureNombre11); break;
					  case 12 : nombreMadagascar.setTexture(textureNombre12); break;
					  case 13 : nombreMadagascar.setTexture(textureNombre13); break;
					  case 14 : nombreMadagascar.setTexture(textureNombre14); break;
					  case 15 : nombreMadagascar.setTexture(textureNombre15); break;
					  case 16 : nombreMadagascar.setTexture(textureNombre16); break;
					  case 17 : nombreMadagascar.setTexture(textureNombre17); break;
					  case 18 : nombreMadagascar.setTexture(textureNombre18); break;
					  case 19 : nombreMadagascar.setTexture(textureNombre19); break;
					  case 20 : nombreMadagascar.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAfriqueDuNord ; 
			nombreAfriqueDuNord.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAfriqueDuNord.setPosition(sf::Vector2f(491.f, 388.f));
			Nombre = listeArmee2[4].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAfriqueDuNord.setTexture(textureNombre0); break; 
					  case 1 : nombreAfriqueDuNord.setTexture(textureNombre1); break;
					  case 2 : nombreAfriqueDuNord.setTexture(textureNombre2); break;
					  case 3 : nombreAfriqueDuNord.setTexture(textureNombre3); break;
					  case 4 : nombreAfriqueDuNord.setTexture(textureNombre4); break;
					  case 5 : nombreAfriqueDuNord.setTexture(textureNombre5); break;
					  case 6 : nombreAfriqueDuNord.setTexture(textureNombre6); break;
					  case 7 : nombreAfriqueDuNord.setTexture(textureNombre7); break;
					  case 8 : nombreAfriqueDuNord.setTexture(textureNombre8); break;
					  case 9 : nombreAfriqueDuNord.setTexture(textureNombre9); break;
					  case 10 : nombreAfriqueDuNord.setTexture(textureNombre10); break;
					  case 11 : nombreAfriqueDuNord.setTexture(textureNombre11); break;
					  case 12 : nombreAfriqueDuNord.setTexture(textureNombre12); break;
					  case 13 : nombreAfriqueDuNord.setTexture(textureNombre13); break;
					  case 14 : nombreAfriqueDuNord.setTexture(textureNombre14); break;
					  case 15 : nombreAfriqueDuNord.setTexture(textureNombre15); break;
					  case 16 : nombreAfriqueDuNord.setTexture(textureNombre16); break;
					  case 17 : nombreAfriqueDuNord.setTexture(textureNombre17); break;
					  case 18 : nombreAfriqueDuNord.setTexture(textureNombre18); break;
					  case 19 : nombreAfriqueDuNord.setTexture(textureNombre19); break;
					  case 20 : nombreAfriqueDuNord.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAfriqueDuSud ; 
			nombreAfriqueDuSud.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAfriqueDuSud.setPosition(sf::Vector2f(568.f, 521.f));
			Nombre = listeArmee2[5].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAfriqueDuSud.setTexture(textureNombre0); break; 
					  case 1 : nombreAfriqueDuSud.setTexture(textureNombre1); break;
					  case 2 : nombreAfriqueDuSud.setTexture(textureNombre2); break;
					  case 3 : nombreAfriqueDuSud.setTexture(textureNombre3); break;
					  case 4 : nombreAfriqueDuSud.setTexture(textureNombre4); break;
					  case 5 : nombreAfriqueDuSud.setTexture(textureNombre5); break;
					  case 6 : nombreAfriqueDuSud.setTexture(textureNombre6); break;
					  case 7 : nombreAfriqueDuSud.setTexture(textureNombre7); break;
					  case 8 : nombreAfriqueDuSud.setTexture(textureNombre8); break;
					  case 9 : nombreAfriqueDuSud.setTexture(textureNombre9); break;
					  case 10 : nombreAfriqueDuSud.setTexture(textureNombre10); break;
					  case 11 : nombreAfriqueDuSud.setTexture(textureNombre11); break;
					  case 12 : nombreAfriqueDuSud.setTexture(textureNombre12); break;
					  case 13 : nombreAfriqueDuSud.setTexture(textureNombre13); break;
					  case 14 : nombreAfriqueDuSud.setTexture(textureNombre14); break;
					  case 15 : nombreAfriqueDuSud.setTexture(textureNombre15); break;
					  case 16 : nombreAfriqueDuSud.setTexture(textureNombre16); break;
					  case 17 : nombreAfriqueDuSud.setTexture(textureNombre17); break;
					  case 18 : nombreAfriqueDuSud.setTexture(textureNombre18); break;
					  case 19 : nombreAfriqueDuSud.setTexture(textureNombre19); break;
					  case 20 : nombreAfriqueDuSud.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAfghanistan ; 
			nombreAfghanistan.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAfghanistan.setPosition(sf::Vector2f(687.f, 294.f));
			Nombre = listeArmee2[6].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAfghanistan.setTexture(textureNombre0); break; 
					  case 1 : nombreAfghanistan.setTexture(textureNombre1); break;
					  case 2 : nombreAfghanistan.setTexture(textureNombre2); break;
					  case 3 : nombreAfghanistan.setTexture(textureNombre3); break;
					  case 4 : nombreAfghanistan.setTexture(textureNombre4); break;
					  case 5 : nombreAfghanistan.setTexture(textureNombre5); break;
					  case 6 : nombreAfghanistan.setTexture(textureNombre6); break;
					  case 7 : nombreAfghanistan.setTexture(textureNombre7); break;
					  case 8 : nombreAfghanistan.setTexture(textureNombre8); break;
					  case 9 : nombreAfghanistan.setTexture(textureNombre9); break;
					  case 10 : nombreAfghanistan.setTexture(textureNombre10); break;
					  case 11 : nombreAfghanistan.setTexture(textureNombre11); break;
					  case 12 : nombreAfghanistan.setTexture(textureNombre12); break;
					  case 13 : nombreAfghanistan.setTexture(textureNombre13); break;
					  case 14 : nombreAfghanistan.setTexture(textureNombre14); break;
					  case 15 : nombreAfghanistan.setTexture(textureNombre15); break;
					  case 16 : nombreAfghanistan.setTexture(textureNombre16); break;
					  case 17 : nombreAfghanistan.setTexture(textureNombre17); break;
					  case 18 : nombreAfghanistan.setTexture(textureNombre18); break;
					  case 19 : nombreAfghanistan.setTexture(textureNombre19); break;
					  case 20 : nombreAfghanistan.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreChine ; 
			nombreChine.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreChine.setPosition(sf::Vector2f(805.f, 326.f));
			Nombre = listeArmee2[7].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreChine.setTexture(textureNombre0); break; 
					  case 1 : nombreChine.setTexture(textureNombre1); break;
					  case 2 : nombreChine.setTexture(textureNombre2); break;
					  case 3 : nombreChine.setTexture(textureNombre3); break;
					  case 4 : nombreChine.setTexture(textureNombre4); break;
					  case 5 : nombreChine.setTexture(textureNombre5); break;
					  case 6 : nombreChine.setTexture(textureNombre6); break;
					  case 7 : nombreChine.setTexture(textureNombre7); break;
					  case 8 : nombreChine.setTexture(textureNombre8); break;
					  case 9 : nombreChine.setTexture(textureNombre9); break;
					  case 10 : nombreChine.setTexture(textureNombre10); break;
					  case 11 : nombreChine.setTexture(textureNombre11); break;
					  case 12 : nombreChine.setTexture(textureNombre12); break;
					  case 13 : nombreChine.setTexture(textureNombre13); break;
					  case 14 : nombreChine.setTexture(textureNombre14); break;
					  case 15 : nombreChine.setTexture(textureNombre15); break;
					  case 16 : nombreChine.setTexture(textureNombre16); break;
					  case 17 : nombreChine.setTexture(textureNombre17); break;
					  case 18 : nombreChine.setTexture(textureNombre18); break;
					  case 19 : nombreChine.setTexture(textureNombre19); break;
					  case 20 : nombreChine.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreInde ; 
			nombreInde.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreInde.setPosition(sf::Vector2f(726.f, 373.f));
			Nombre = listeArmee2[8].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreInde.setTexture(textureNombre0); break; 
					  case 1 : nombreInde.setTexture(textureNombre1); break;
					  case 2 : nombreInde.setTexture(textureNombre2); break;
					  case 3 : nombreInde.setTexture(textureNombre3); break;
					  case 4 : nombreInde.setTexture(textureNombre4); break;
					  case 5 : nombreInde.setTexture(textureNombre5); break;
					  case 6 : nombreInde.setTexture(textureNombre6); break;
					  case 7 : nombreInde.setTexture(textureNombre7); break;
					  case 8 : nombreInde.setTexture(textureNombre8); break;
					  case 9 : nombreInde.setTexture(textureNombre9); break;
					  case 10 : nombreInde.setTexture(textureNombre10); break;
					  case 11 : nombreInde.setTexture(textureNombre11); break;
					  case 12 : nombreInde.setTexture(textureNombre12); break;
					  case 13 : nombreInde.setTexture(textureNombre13); break;
					  case 14 : nombreInde.setTexture(textureNombre14); break;
					  case 15 : nombreInde.setTexture(textureNombre15); break;
					  case 16 : nombreInde.setTexture(textureNombre16); break;
					  case 17 : nombreInde.setTexture(textureNombre17); break;
					  case 18 : nombreInde.setTexture(textureNombre18); break;
					  case 19 : nombreInde.setTexture(textureNombre19); break;
					  case 20 : nombreInde.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreTchita ; 
			nombreTchita.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreTchita.setPosition(sf::Vector2f(822.f, 220.f));
			Nombre = listeArmee2[9].get() ;
			nbrArmees = Nombre -> getNombre(); 
			switch (nbrArmees) {
					  case 0 : nombreTchita.setTexture(textureNombre0); break; 
					  case 1 : nombreTchita.setTexture(textureNombre1); break;
					  case 2 : nombreTchita.setTexture(textureNombre2); break;
					  case 3 : nombreTchita.setTexture(textureNombre3); break;
					  case 4 : nombreTchita.setTexture(textureNombre4); break;
					  case 5 : nombreTchita.setTexture(textureNombre5); break;
					  case 6 : nombreTchita.setTexture(textureNombre6); break;
					  case 7 : nombreTchita.setTexture(textureNombre7); break;
					  case 8 : nombreTchita.setTexture(textureNombre8); break;
					  case 9 : nombreTchita.setTexture(textureNombre9); break;
					  case 10 : nombreTchita.setTexture(textureNombre10); break;
					  case 11 : nombreTchita.setTexture(textureNombre11); break;
					  case 12 : nombreTchita.setTexture(textureNombre12); break;
					  case 13 : nombreTchita.setTexture(textureNombre13); break;
					  case 14 : nombreTchita.setTexture(textureNombre14); break;
					  case 15 : nombreTchita.setTexture(textureNombre15); break;
					  case 16 : nombreTchita.setTexture(textureNombre16); break;
					  case 17 : nombreTchita.setTexture(textureNombre17); break;
					  case 18 : nombreTchita.setTexture(textureNombre18); break;
					  case 19 : nombreTchita.setTexture(textureNombre19); break;
					  case 20 : nombreTchita.setTexture(textureNombre20); break;
					}
			
			sf::Sprite nombreJapon ; 
			nombreJapon.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreJapon.setPosition(sf::Vector2f(912.f, 325.f));
			Nombre = listeArmee2[10].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreJapon.setTexture(textureNombre0); break; 
					  case 1 : nombreJapon.setTexture(textureNombre1); break;
					  case 2 : nombreJapon.setTexture(textureNombre2); break;
					  case 3 : nombreJapon.setTexture(textureNombre3); break;
					  case 4 : nombreJapon.setTexture(textureNombre4); break;
					  case 5 : nombreJapon.setTexture(textureNombre5); break;
					  case 6 : nombreJapon.setTexture(textureNombre6); break;
					  case 7 : nombreJapon.setTexture(textureNombre7); break;
					  case 8 : nombreJapon.setTexture(textureNombre8); break;
					  case 9 : nombreJapon.setTexture(textureNombre9); break;
					  case 10 : nombreJapon.setTexture(textureNombre10); break;
					  case 11 : nombreJapon.setTexture(textureNombre11); break;
					  case 12 : nombreJapon.setTexture(textureNombre12); break;
					  case 13 : nombreJapon.setTexture(textureNombre13); break;
					  case 14 : nombreJapon.setTexture(textureNombre14); break;
					  case 15 : nombreJapon.setTexture(textureNombre15); break;
					  case 16 : nombreJapon.setTexture(textureNombre16); break;
					  case 17 : nombreJapon.setTexture(textureNombre17); break;
					  case 18 : nombreJapon.setTexture(textureNombre18); break;
					  case 19 : nombreJapon.setTexture(textureNombre19); break;
					  case 20 : nombreJapon.setTexture(textureNombre20); break;
					}
						
			sf::Sprite nombreKamtchatka ; 
			nombreKamtchatka.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreKamtchatka.setPosition(sf::Vector2f(950.f, 190.f));
			Nombre = listeArmee2[11].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreKamtchatka.setTexture(textureNombre0); break; 
					  case 1 : nombreKamtchatka.setTexture(textureNombre1); break;
					  case 2 : nombreKamtchatka.setTexture(textureNombre2); break;
					  case 3 : nombreKamtchatka.setTexture(textureNombre3); break;
					  case 4 : nombreKamtchatka.setTexture(textureNombre4); break;
					  case 5 : nombreKamtchatka.setTexture(textureNombre5); break;
					  case 6 : nombreKamtchatka.setTexture(textureNombre6); break;
					  case 7 : nombreKamtchatka.setTexture(textureNombre7); break;
					  case 8 : nombreKamtchatka.setTexture(textureNombre8); break;
					  case 9 : nombreKamtchatka.setTexture(textureNombre9); break;
					  case 10 : nombreKamtchatka.setTexture(textureNombre10); break;
					  case 11 : nombreKamtchatka.setTexture(textureNombre11); break;
					  case 12 : nombreKamtchatka.setTexture(textureNombre12); break;
					  case 13 : nombreKamtchatka.setTexture(textureNombre13); break;
					  case 14 : nombreKamtchatka.setTexture(textureNombre14); break;
					  case 15 : nombreKamtchatka.setTexture(textureNombre15); break;
					  case 16 : nombreKamtchatka.setTexture(textureNombre16); break;
					  case 17 : nombreKamtchatka.setTexture(textureNombre17); break;
					  case 18 : nombreKamtchatka.setTexture(textureNombre18); break;
					  case 19 : nombreKamtchatka.setTexture(textureNombre19); break;
					  case 20 : nombreKamtchatka.setTexture(textureNombre20); break;
					}
			
			sf::Sprite nombreMoyenOrient ; 
			nombreMoyenOrient.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreMoyenOrient.setPosition(sf::Vector2f(643.f, 352.f));
			Nombre = listeArmee2[12].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreMoyenOrient.setTexture(textureNombre0); break; 
					  case 1 : nombreMoyenOrient.setTexture(textureNombre1); break;
					  case 2 : nombreMoyenOrient.setTexture(textureNombre2); break;
					  case 3 : nombreMoyenOrient.setTexture(textureNombre3); break;
					  case 4 : nombreMoyenOrient.setTexture(textureNombre4); break;
					  case 5 : nombreMoyenOrient.setTexture(textureNombre5); break;
					  case 6 : nombreMoyenOrient.setTexture(textureNombre6); break;
					  case 7 : nombreMoyenOrient.setTexture(textureNombre7); break;
					  case 8 : nombreMoyenOrient.setTexture(textureNombre8); break;
					  case 9 : nombreMoyenOrient.setTexture(textureNombre9); break;
					  case 10 : nombreMoyenOrient.setTexture(textureNombre10); break;
					  case 11 : nombreMoyenOrient.setTexture(textureNombre11); break;
					  case 12 : nombreMoyenOrient.setTexture(textureNombre12); break;
					  case 13 : nombreMoyenOrient.setTexture(textureNombre13); break;
					  case 14 : nombreMoyenOrient.setTexture(textureNombre14); break;
					  case 15 : nombreMoyenOrient.setTexture(textureNombre15); break;
					  case 16 : nombreMoyenOrient.setTexture(textureNombre16); break;
					  case 17 : nombreMoyenOrient.setTexture(textureNombre17); break;
					  case 18 : nombreMoyenOrient.setTexture(textureNombre18); break;
					  case 19 : nombreMoyenOrient.setTexture(textureNombre19); break;
					  case 20 : nombreMoyenOrient.setTexture(textureNombre20); break;
					}
									
			sf::Sprite nombreMongolie ; 
			nombreMongolie.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreMongolie.setPosition(sf::Vector2f(827.f, 277.f));
			Nombre = listeArmee2[13].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreMongolie.setTexture(textureNombre0); break; 
					  case 1 : nombreMongolie.setTexture(textureNombre1); break;
					  case 2 : nombreMongolie.setTexture(textureNombre2); break;
					  case 3 : nombreMongolie.setTexture(textureNombre3); break;
					  case 4 : nombreMongolie.setTexture(textureNombre4); break;
					  case 5 : nombreMongolie.setTexture(textureNombre5); break;
					  case 6 : nombreMongolie.setTexture(textureNombre6); break;
					  case 7 : nombreMongolie.setTexture(textureNombre7); break;
					  case 8 : nombreMongolie.setTexture(textureNombre8); break;
					  case 9 : nombreMongolie.setTexture(textureNombre9); break;
					  case 10 : nombreMongolie.setTexture(textureNombre10); break;
					  case 11 : nombreMongolie.setTexture(textureNombre11); break;
					  case 12 : nombreMongolie.setTexture(textureNombre12); break;
					  case 13 : nombreMongolie.setTexture(textureNombre13); break;
					  case 14 : nombreMongolie.setTexture(textureNombre14); break;
					  case 15 : nombreMongolie.setTexture(textureNombre15); break;
					  case 16 : nombreMongolie.setTexture(textureNombre16); break;
					  case 17 : nombreMongolie.setTexture(textureNombre17); break;
					  case 18 : nombreMongolie.setTexture(textureNombre18); break;
					  case 19 : nombreMongolie.setTexture(textureNombre19); break;
					  case 20 : nombreMongolie.setTexture(textureNombre20); break;
					}
						
						
			sf::Sprite nombreSiam ; 
			nombreSiam.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreSiam.setPosition(sf::Vector2f(771.f, 401.f));
			Nombre = listeArmee2[14].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreSiam.setTexture(textureNombre0); break; 
					  case 1 : nombreSiam.setTexture(textureNombre1); break;
					  case 2 : nombreSiam.setTexture(textureNombre2); break;
					  case 3 : nombreSiam.setTexture(textureNombre3); break;
					  case 4 : nombreSiam.setTexture(textureNombre4); break;
					  case 5 : nombreSiam.setTexture(textureNombre5); break;
					  case 6 : nombreSiam.setTexture(textureNombre6); break;
					  case 7 : nombreSiam.setTexture(textureNombre7); break;
					  case 8 : nombreSiam.setTexture(textureNombre8); break;
					  case 9 : nombreSiam.setTexture(textureNombre9); break;
					  case 10 : nombreSiam.setTexture(textureNombre10); break;
					  case 11 : nombreSiam.setTexture(textureNombre11); break;
					  case 12 : nombreSiam.setTexture(textureNombre12); break;
					  case 13 : nombreSiam.setTexture(textureNombre13); break;
					  case 14 : nombreSiam.setTexture(textureNombre14); break;
					  case 15 : nombreSiam.setTexture(textureNombre15); break;
					  case 16 : nombreSiam.setTexture(textureNombre16); break;
					  case 17 : nombreSiam.setTexture(textureNombre17); break;
					  case 18 : nombreSiam.setTexture(textureNombre18); break;
					  case 19 : nombreSiam.setTexture(textureNombre19); break;
					  case 20 : nombreSiam.setTexture(textureNombre20); break;
					}
												
			sf::Sprite nombreSiberie ; 
			nombreSiberie.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreSiberie.setPosition(sf::Vector2f(752.f, 197.f));
			Nombre = listeArmee2[15].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreSiberie.setTexture(textureNombre0); break; 
					  case 1 : nombreSiberie.setTexture(textureNombre1); break;
					  case 2 : nombreSiberie.setTexture(textureNombre2); break;
					  case 3 : nombreSiberie.setTexture(textureNombre3); break;
					  case 4 : nombreSiberie.setTexture(textureNombre4); break;
					  case 5 : nombreSiberie.setTexture(textureNombre5); break;
					  case 6 : nombreSiberie.setTexture(textureNombre6); break;
					  case 7 : nombreSiberie.setTexture(textureNombre7); break;
					  case 8 : nombreSiberie.setTexture(textureNombre8); break;
					  case 9 : nombreSiberie.setTexture(textureNombre9); break;
					  case 10 : nombreSiberie.setTexture(textureNombre10); break;
					  case 11 : nombreSiberie.setTexture(textureNombre11); break;
					  case 12 : nombreSiberie.setTexture(textureNombre12); break;
					  case 13 : nombreSiberie.setTexture(textureNombre13); break;
					  case 14 : nombreSiberie.setTexture(textureNombre14); break;
					  case 15 : nombreSiberie.setTexture(textureNombre15); break;
					  case 16 : nombreSiberie.setTexture(textureNombre16); break;
					  case 17 : nombreSiberie.setTexture(textureNombre17); break;
					  case 18 : nombreSiberie.setTexture(textureNombre18); break;
					  case 19 : nombreSiberie.setTexture(textureNombre19); break;
					  case 20 : nombreSiberie.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreOural ; 
			nombreOural.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreOural.setPosition(sf::Vector2f(684.f, 222.f));
			Nombre = listeArmee2[16].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreOural.setTexture(textureNombre0); break; 
					  case 1 : nombreOural.setTexture(textureNombre1); break;
					  case 2 : nombreOural.setTexture(textureNombre2); break;
					  case 3 : nombreOural.setTexture(textureNombre3); break;
					  case 4 : nombreOural.setTexture(textureNombre4); break;
					  case 5 : nombreOural.setTexture(textureNombre5); break;
					  case 6 : nombreOural.setTexture(textureNombre6); break;
					  case 7 : nombreOural.setTexture(textureNombre7); break;
					  case 8 : nombreOural.setTexture(textureNombre8); break;
					  case 9 : nombreOural.setTexture(textureNombre9); break;
					  case 10 : nombreOural.setTexture(textureNombre10); break;
					  case 11 : nombreOural.setTexture(textureNombre11); break;
					  case 12 : nombreOural.setTexture(textureNombre12); break;
					  case 13 : nombreOural.setTexture(textureNombre13); break;
					  case 14 : nombreOural.setTexture(textureNombre14); break;
					  case 15 : nombreOural.setTexture(textureNombre15); break;
					  case 16 : nombreOural.setTexture(textureNombre16); break;
					  case 17 : nombreOural.setTexture(textureNombre17); break;
					  case 18 : nombreOural.setTexture(textureNombre18); break;
					  case 19 : nombreOural.setTexture(textureNombre19); break;
					  case 20 : nombreOural.setTexture(textureNombre20); break;
					}

			sf::Sprite nombreYakoutie ; 
			nombreYakoutie.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreYakoutie.setPosition(sf::Vector2f(843.f, 158.f));
			Nombre = listeArmee2[17].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreYakoutie.setTexture(textureNombre0); break; 
					  case 1 : nombreYakoutie.setTexture(textureNombre1); break;
					  case 2 : nombreYakoutie.setTexture(textureNombre2); break;
					  case 3 : nombreYakoutie.setTexture(textureNombre3); break;
					  case 4 : nombreYakoutie.setTexture(textureNombre4); break;
					  case 5 : nombreYakoutie.setTexture(textureNombre5); break;
					  case 6 : nombreYakoutie.setTexture(textureNombre6); break;
					  case 7 : nombreYakoutie.setTexture(textureNombre7); break;
					  case 8 : nombreYakoutie.setTexture(textureNombre8); break;
					  case 9 : nombreYakoutie.setTexture(textureNombre9); break;
					  case 10 : nombreYakoutie.setTexture(textureNombre10); break;
					  case 11 : nombreYakoutie.setTexture(textureNombre11); break;
					  case 12 : nombreYakoutie.setTexture(textureNombre12); break;
					  case 13 : nombreYakoutie.setTexture(textureNombre13); break;
					  case 14 : nombreYakoutie.setTexture(textureNombre14); break;
					  case 15 : nombreYakoutie.setTexture(textureNombre15); break;
					  case 16 : nombreYakoutie.setTexture(textureNombre16); break;
					  case 17 : nombreYakoutie.setTexture(textureNombre17); break;
					  case 18 : nombreYakoutie.setTexture(textureNombre18); break;
					  case 19 : nombreYakoutie.setTexture(textureNombre19); break;
					  case 20 : nombreYakoutie.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAlaska ; 
			nombreAlaska.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAlaska.setPosition(sf::Vector2f(87.f, 168.f));
			Nombre = listeArmee2[18].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAlaska.setTexture(textureNombre0); break; 
					  case 1 : nombreAlaska.setTexture(textureNombre1); break;
					  case 2 : nombreAlaska.setTexture(textureNombre2); break;
					  case 3 : nombreAlaska.setTexture(textureNombre3); break;
					  case 4 : nombreAlaska.setTexture(textureNombre4); break;
					  case 5 : nombreAlaska.setTexture(textureNombre5); break;
					  case 6 : nombreAlaska.setTexture(textureNombre6); break;
					  case 7 : nombreAlaska.setTexture(textureNombre7); break;
					  case 8 : nombreAlaska.setTexture(textureNombre8); break;
					  case 9 : nombreAlaska.setTexture(textureNombre9); break;
					  case 10 : nombreAlaska.setTexture(textureNombre10); break;
					  case 11 : nombreAlaska.setTexture(textureNombre11); break;
					  case 12 : nombreAlaska.setTexture(textureNombre12); break;
					  case 13 : nombreAlaska.setTexture(textureNombre13); break;
					  case 14 : nombreAlaska.setTexture(textureNombre14); break;
					  case 15 : nombreAlaska.setTexture(textureNombre15); break;
					  case 16 : nombreAlaska.setTexture(textureNombre16); break;
					  case 17 : nombreAlaska.setTexture(textureNombre17); break;
					  case 18 : nombreAlaska.setTexture(textureNombre18); break;
					  case 19 : nombreAlaska.setTexture(textureNombre19); break;
					  case 20 : nombreAlaska.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAlberta ; 
			nombreAlberta.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAlberta.setPosition(sf::Vector2f(184.f, 218.f));
			Nombre = listeArmee2[19].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAlberta.setTexture(textureNombre0); break; 
					  case 1 : nombreAlberta.setTexture(textureNombre1); break;
					  case 2 : nombreAlberta.setTexture(textureNombre2); break;
					  case 3 : nombreAlberta.setTexture(textureNombre3); break;
					  case 4 : nombreAlberta.setTexture(textureNombre4); break;
					  case 5 : nombreAlberta.setTexture(textureNombre5); break;
					  case 6 : nombreAlberta.setTexture(textureNombre6); break;
					  case 7 : nombreAlberta.setTexture(textureNombre7); break;
					  case 8 : nombreAlberta.setTexture(textureNombre8); break;
					  case 9 : nombreAlberta.setTexture(textureNombre9); break;
					  case 10 : nombreAlberta.setTexture(textureNombre10); break;
					  case 11 : nombreAlberta.setTexture(textureNombre11); break;
					  case 12 : nombreAlberta.setTexture(textureNombre12); break;
					  case 13 : nombreAlberta.setTexture(textureNombre13); break;
					  case 14 : nombreAlberta.setTexture(textureNombre14); break;
					  case 15 : nombreAlberta.setTexture(textureNombre15); break;
					  case 16 : nombreAlberta.setTexture(textureNombre16); break;
					  case 17 : nombreAlberta.setTexture(textureNombre17); break;
					  case 18 : nombreAlberta.setTexture(textureNombre18); break;
					  case 19 : nombreAlberta.setTexture(textureNombre19); break;
					  case 20 : nombreAlberta.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAmeriqueCentrale ; 
			nombreAmeriqueCentrale.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAmeriqueCentrale.setPosition(sf::Vector2f(207.f, 343.f));
			Nombre = listeArmee2[20].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAmeriqueCentrale.setTexture(textureNombre0); break; 
					  case 1 : nombreAmeriqueCentrale.setTexture(textureNombre1); break;
					  case 2 : nombreAmeriqueCentrale.setTexture(textureNombre2); break;
					  case 3 : nombreAmeriqueCentrale.setTexture(textureNombre3); break;
					  case 4 : nombreAmeriqueCentrale.setTexture(textureNombre4); break;
					  case 5 : nombreAmeriqueCentrale.setTexture(textureNombre5); break;
					  case 6 : nombreAmeriqueCentrale.setTexture(textureNombre6); break;
					  case 7 : nombreAmeriqueCentrale.setTexture(textureNombre7); break;
					  case 8 : nombreAmeriqueCentrale.setTexture(textureNombre8); break;
					  case 9 : nombreAmeriqueCentrale.setTexture(textureNombre9); break;
					  case 10 : nombreAmeriqueCentrale.setTexture(textureNombre10); break;
					  case 11 : nombreAmeriqueCentrale.setTexture(textureNombre11); break;
					  case 12 : nombreAmeriqueCentrale.setTexture(textureNombre12); break;
					  case 13 : nombreAmeriqueCentrale.setTexture(textureNombre13); break;
					  case 14 : nombreAmeriqueCentrale.setTexture(textureNombre14); break;
					  case 15 : nombreAmeriqueCentrale.setTexture(textureNombre15); break;
					  case 16 : nombreAmeriqueCentrale.setTexture(textureNombre16); break;
					  case 17 : nombreAmeriqueCentrale.setTexture(textureNombre17); break;
					  case 18 : nombreAmeriqueCentrale.setTexture(textureNombre18); break;
					  case 19 : nombreAmeriqueCentrale.setTexture(textureNombre19); break;
					  case 20 : nombreAmeriqueCentrale.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreEtatDeLEst ; 
			nombreEtatDeLEst.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreEtatDeLEst.setPosition(sf::Vector2f(259.f, 286.f));
			Nombre = listeArmee2[21].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreEtatDeLEst.setTexture(textureNombre0); break; 
					  case 1 : nombreEtatDeLEst.setTexture(textureNombre1); break;
					  case 2 : nombreEtatDeLEst.setTexture(textureNombre2); break;
					  case 3 : nombreEtatDeLEst.setTexture(textureNombre3); break;
					  case 4 : nombreEtatDeLEst.setTexture(textureNombre4); break;
					  case 5 : nombreEtatDeLEst.setTexture(textureNombre5); break;
					  case 6 : nombreEtatDeLEst.setTexture(textureNombre6); break;
					  case 7 : nombreEtatDeLEst.setTexture(textureNombre7); break;
					  case 8 : nombreEtatDeLEst.setTexture(textureNombre8); break;
					  case 9 : nombreEtatDeLEst.setTexture(textureNombre9); break;
					  case 10 : nombreEtatDeLEst.setTexture(textureNombre10); break;
					  case 11 : nombreEtatDeLEst.setTexture(textureNombre11); break;
					  case 12 : nombreEtatDeLEst.setTexture(textureNombre12); break;
					  case 13 : nombreEtatDeLEst.setTexture(textureNombre13); break;
					  case 14 : nombreEtatDeLEst.setTexture(textureNombre14); break;
					  case 15 : nombreEtatDeLEst.setTexture(textureNombre15); break;
					  case 16 : nombreEtatDeLEst.setTexture(textureNombre16); break;
					  case 17 : nombreEtatDeLEst.setTexture(textureNombre17); break;
					  case 18 : nombreEtatDeLEst.setTexture(textureNombre18); break;
					  case 19 : nombreEtatDeLEst.setTexture(textureNombre19); break;
					  case 20 : nombreEtatDeLEst.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreGroenland ; 
			nombreGroenland.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreGroenland.setPosition(sf::Vector2f(388.f, 98.f));
			Nombre = listeArmee2[22].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreGroenland.setTexture(textureNombre0); break; 
					  case 1 : nombreGroenland.setTexture(textureNombre1); break;
					  case 2 : nombreGroenland.setTexture(textureNombre2); break;
					  case 3 : nombreGroenland.setTexture(textureNombre3); break;
					  case 4 : nombreGroenland.setTexture(textureNombre4); break;
					  case 5 : nombreGroenland.setTexture(textureNombre5); break;
					  case 6 : nombreGroenland.setTexture(textureNombre6); break;
					  case 7 : nombreGroenland.setTexture(textureNombre7); break;
					  case 8 : nombreGroenland.setTexture(textureNombre8); break;
					  case 9 : nombreGroenland.setTexture(textureNombre9); break;
					  case 10 : nombreGroenland.setTexture(textureNombre10); break;
					  case 11 : nombreGroenland.setTexture(textureNombre11); break;
					  case 12 : nombreGroenland.setTexture(textureNombre12); break;
					  case 13 : nombreGroenland.setTexture(textureNombre13); break;
					  case 14 : nombreGroenland.setTexture(textureNombre14); break;
					  case 15 : nombreGroenland.setTexture(textureNombre15); break;
					  case 16 : nombreGroenland.setTexture(textureNombre16); break;
					  case 17 : nombreGroenland.setTexture(textureNombre17); break;
					  case 18 : nombreGroenland.setTexture(textureNombre18); break;
					  case 19 : nombreGroenland.setTexture(textureNombre19); break;
					  case 20 : nombreGroenland.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreTerritoireDuNordOuest ; 
			nombreTerritoireDuNordOuest.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreTerritoireDuNordOuest.setPosition(sf::Vector2f(181.f, 170.f));
			Nombre = listeArmee2[23].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreTerritoireDuNordOuest.setTexture(textureNombre0); break; 
					  case 1 : nombreTerritoireDuNordOuest.setTexture(textureNombre1); break;
					  case 2 : nombreTerritoireDuNordOuest.setTexture(textureNombre2); break;
					  case 3 : nombreTerritoireDuNordOuest.setTexture(textureNombre3); break;
					  case 4 : nombreTerritoireDuNordOuest.setTexture(textureNombre4); break;
					  case 5 : nombreTerritoireDuNordOuest.setTexture(textureNombre5); break;
					  case 6 : nombreTerritoireDuNordOuest.setTexture(textureNombre6); break;
					  case 7 : nombreTerritoireDuNordOuest.setTexture(textureNombre7); break;
					  case 8 : nombreTerritoireDuNordOuest.setTexture(textureNombre8); break;
					  case 9 : nombreTerritoireDuNordOuest.setTexture(textureNombre9); break;
					  case 10 : nombreTerritoireDuNordOuest.setTexture(textureNombre10); break;
					  case 11 : nombreTerritoireDuNordOuest.setTexture(textureNombre11); break;
					  case 12 : nombreTerritoireDuNordOuest.setTexture(textureNombre12); break;
					  case 13 : nombreTerritoireDuNordOuest.setTexture(textureNombre13); break;
					  case 14 : nombreTerritoireDuNordOuest.setTexture(textureNombre14); break;
					  case 15 : nombreTerritoireDuNordOuest.setTexture(textureNombre15); break;
					  case 16 : nombreTerritoireDuNordOuest.setTexture(textureNombre16); break;
					  case 17 : nombreTerritoireDuNordOuest.setTexture(textureNombre17); break;
					  case 18 : nombreTerritoireDuNordOuest.setTexture(textureNombre18); break;
					  case 19 : nombreTerritoireDuNordOuest.setTexture(textureNombre19); break;
					  case 20 : nombreTerritoireDuNordOuest.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreOntario ; 
			nombreOntario.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreOntario.setPosition(sf::Vector2f(251.f, 237.f));
			Nombre = listeArmee2[24].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreOntario.setTexture(textureNombre0); break; 
					  case 1 : nombreOntario.setTexture(textureNombre1); break;
					  case 2 : nombreOntario.setTexture(textureNombre2); break;
					  case 3 : nombreOntario.setTexture(textureNombre3); break;
					  case 4 : nombreOntario.setTexture(textureNombre4); break;
					  case 5 : nombreOntario.setTexture(textureNombre5); break;
					  case 6 : nombreOntario.setTexture(textureNombre6); break;
					  case 7 : nombreOntario.setTexture(textureNombre7); break;
					  case 8 : nombreOntario.setTexture(textureNombre8); break;
					  case 9 : nombreOntario.setTexture(textureNombre9); break;
					  case 10 : nombreOntario.setTexture(textureNombre10); break;
					  case 11 : nombreOntario.setTexture(textureNombre11); break;
					  case 12 : nombreOntario.setTexture(textureNombre12); break;
					  case 13 : nombreOntario.setTexture(textureNombre13); break;
					  case 14 : nombreOntario.setTexture(textureNombre14); break;
					  case 15 : nombreOntario.setTexture(textureNombre15); break;
					  case 16 : nombreOntario.setTexture(textureNombre16); break;
					  case 17 : nombreOntario.setTexture(textureNombre17); break;
					  case 18 : nombreOntario.setTexture(textureNombre18); break;
					  case 19 : nombreOntario.setTexture(textureNombre19); break;
					  case 20 : nombreOntario.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreQuebec ; 
			nombreQuebec.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreQuebec.setPosition(sf::Vector2f(318.f, 225.f));
			Nombre = listeArmee2[25].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreQuebec.setTexture(textureNombre0); break; 
					  case 1 : nombreQuebec.setTexture(textureNombre1); break;
					  case 2 : nombreQuebec.setTexture(textureNombre2); break;
					  case 3 : nombreQuebec.setTexture(textureNombre3); break;
					  case 4 : nombreQuebec.setTexture(textureNombre4); break;
					  case 5 : nombreQuebec.setTexture(textureNombre5); break;
					  case 6 : nombreQuebec.setTexture(textureNombre6); break;
					  case 7 : nombreQuebec.setTexture(textureNombre7); break;
					  case 8 : nombreQuebec.setTexture(textureNombre8); break;
					  case 9 : nombreQuebec.setTexture(textureNombre9); break;
					  case 10 : nombreQuebec.setTexture(textureNombre10); break;
					  case 11 : nombreQuebec.setTexture(textureNombre11); break;
					  case 12 : nombreQuebec.setTexture(textureNombre12); break;
					  case 13 : nombreQuebec.setTexture(textureNombre13); break;
					  case 14 : nombreQuebec.setTexture(textureNombre14); break;
					  case 15 : nombreQuebec.setTexture(textureNombre15); break;
					  case 16 : nombreQuebec.setTexture(textureNombre16); break;
					  case 17 : nombreQuebec.setTexture(textureNombre17); break;
					  case 18 : nombreQuebec.setTexture(textureNombre18); break;
					  case 19 : nombreQuebec.setTexture(textureNombre19); break;
					  case 20 : nombreQuebec.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreEtatDeLOuest ; 
			nombreEtatDeLOuest.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreEtatDeLOuest.setPosition(sf::Vector2f(188.f, 274.f));
			Nombre = listeArmee2[26].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreEtatDeLOuest.setTexture(textureNombre0); break; 
					  case 1 : nombreEtatDeLOuest.setTexture(textureNombre1); break;
					  case 2 : nombreEtatDeLOuest.setTexture(textureNombre2); break;
					  case 3 : nombreEtatDeLOuest.setTexture(textureNombre3); break;
					  case 4 : nombreEtatDeLOuest.setTexture(textureNombre4); break;
					  case 5 : nombreEtatDeLOuest.setTexture(textureNombre5); break;
					  case 6 : nombreEtatDeLOuest.setTexture(textureNombre6); break;
					  case 7 : nombreEtatDeLOuest.setTexture(textureNombre7); break;
					  case 8 : nombreEtatDeLOuest.setTexture(textureNombre8); break;
					  case 9 : nombreEtatDeLOuest.setTexture(textureNombre9); break;
					  case 10 : nombreEtatDeLOuest.setTexture(textureNombre10); break;
					  case 11 : nombreEtatDeLOuest.setTexture(textureNombre11); break;
					  case 12 : nombreEtatDeLOuest.setTexture(textureNombre12); break;
					  case 13 : nombreEtatDeLOuest.setTexture(textureNombre13); break;
					  case 14 : nombreEtatDeLOuest.setTexture(textureNombre14); break;
					  case 15 : nombreEtatDeLOuest.setTexture(textureNombre15); break;
					  case 16 : nombreEtatDeLOuest.setTexture(textureNombre16); break;
					  case 17 : nombreEtatDeLOuest.setTexture(textureNombre17); break;
					  case 18 : nombreEtatDeLOuest.setTexture(textureNombre18); break;
					  case 19 : nombreEtatDeLOuest.setTexture(textureNombre19); break;
					  case 20 : nombreEtatDeLOuest.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreArgentine ; 
			nombreArgentine.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreArgentine.setPosition(sf::Vector2f(322.f, 530.f));
			Nombre = listeArmee2[27].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreArgentine.setTexture(textureNombre0); break; 
					  case 1 : nombreArgentine.setTexture(textureNombre1); break;
					  case 2 : nombreArgentine.setTexture(textureNombre2); break;
					  case 3 : nombreArgentine.setTexture(textureNombre3); break;
					  case 4 : nombreArgentine.setTexture(textureNombre4); break;
					  case 5 : nombreArgentine.setTexture(textureNombre5); break;
					  case 6 : nombreArgentine.setTexture(textureNombre6); break;
					  case 7 : nombreArgentine.setTexture(textureNombre7); break;
					  case 8 : nombreArgentine.setTexture(textureNombre8); break;
					  case 9 : nombreArgentine.setTexture(textureNombre9); break;
					  case 10 : nombreArgentine.setTexture(textureNombre10); break;
					  case 11 : nombreArgentine.setTexture(textureNombre11); break;
					  case 12 : nombreArgentine.setTexture(textureNombre12); break;
					  case 13 : nombreArgentine.setTexture(textureNombre13); break;
					  case 14 : nombreArgentine.setTexture(textureNombre14); break;
					  case 15 : nombreArgentine.setTexture(textureNombre15); break;
					  case 16 : nombreArgentine.setTexture(textureNombre16); break;
					  case 17 : nombreArgentine.setTexture(textureNombre17); break;
					  case 18 : nombreArgentine.setTexture(textureNombre18); break;
					  case 19 : nombreArgentine.setTexture(textureNombre19); break;
					  case 20 : nombreArgentine.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreBresil ; 
			nombreBresil.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreBresil.setPosition(sf::Vector2f(369.f, 456.f));
			Nombre = listeArmee2[28].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreBresil.setTexture(textureNombre0); break; 
					  case 1 : nombreBresil.setTexture(textureNombre1); break;
					  case 2 : nombreBresil.setTexture(textureNombre2); break;
					  case 3 : nombreBresil.setTexture(textureNombre3); break;
					  case 4 : nombreBresil.setTexture(textureNombre4); break;
					  case 5 : nombreBresil.setTexture(textureNombre5); break;
					  case 6 : nombreBresil.setTexture(textureNombre6); break;
					  case 7 : nombreBresil.setTexture(textureNombre7); break;
					  case 8 : nombreBresil.setTexture(textureNombre8); break;
					  case 9 : nombreBresil.setTexture(textureNombre9); break;
					  case 10 : nombreBresil.setTexture(textureNombre10); break;
					  case 11 : nombreBresil.setTexture(textureNombre11); break;
					  case 12 : nombreBresil.setTexture(textureNombre12); break;
					  case 13 : nombreBresil.setTexture(textureNombre13); break;
					  case 14 : nombreBresil.setTexture(textureNombre14); break;
					  case 15 : nombreBresil.setTexture(textureNombre15); break;
					  case 16 : nombreBresil.setTexture(textureNombre16); break;
					  case 17 : nombreBresil.setTexture(textureNombre17); break;
					  case 18 : nombreBresil.setTexture(textureNombre18); break;
					  case 19 : nombreBresil.setTexture(textureNombre19); break;
					  case 20 : nombreBresil.setTexture(textureNombre20); break;
					}
			sf::Sprite nombrePerou ; 
			nombrePerou.setScale(sf::Vector2f(0.5f, 0.5f));
			nombrePerou.setPosition(sf::Vector2f(316.f, 391.f));
			Nombre = listeArmee2[29].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombrePerou.setTexture(textureNombre0); break; 
					  case 1 : nombrePerou.setTexture(textureNombre1); break;
					  case 2 : nombrePerou.setTexture(textureNombre2); break;
					  case 3 : nombrePerou.setTexture(textureNombre3); break;
					  case 4 : nombrePerou.setTexture(textureNombre4); break;
					  case 5 : nombrePerou.setTexture(textureNombre5); break;
					  case 6 : nombrePerou.setTexture(textureNombre6); break;
					  case 7 : nombrePerou.setTexture(textureNombre7); break;
					  case 8 : nombrePerou.setTexture(textureNombre8); break;
					  case 9 : nombrePerou.setTexture(textureNombre9); break;
					  case 10 : nombrePerou.setTexture(textureNombre10); break;
					  case 11 : nombrePerou.setTexture(textureNombre11); break;
					  case 12 : nombrePerou.setTexture(textureNombre12); break;
					  case 13 : nombrePerou.setTexture(textureNombre13); break;
					  case 14 : nombrePerou.setTexture(textureNombre14); break;
					  case 15 : nombrePerou.setTexture(textureNombre15); break;
					  case 16 : nombrePerou.setTexture(textureNombre16); break;
					  case 17 : nombrePerou.setTexture(textureNombre17); break;
					  case 18 : nombrePerou.setTexture(textureNombre18); break;
					  case 19 : nombrePerou.setTexture(textureNombre19); break;
					  case 20 : nombrePerou.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreVenezuela ; 
			nombreVenezuela.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreVenezuela.setPosition(sf::Vector2f(318.f, 474.f));
			Nombre = listeArmee2[30].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreVenezuela.setTexture(textureNombre0); break; 
					  case 1 : nombreVenezuela.setTexture(textureNombre1); break;
					  case 2 : nombreVenezuela.setTexture(textureNombre2); break;
					  case 3 : nombreVenezuela.setTexture(textureNombre3); break;
					  case 4 : nombreVenezuela.setTexture(textureNombre4); break;
					  case 5 : nombreVenezuela.setTexture(textureNombre5); break;
					  case 6 : nombreVenezuela.setTexture(textureNombre6); break;
					  case 7 : nombreVenezuela.setTexture(textureNombre7); break;
					  case 8 : nombreVenezuela.setTexture(textureNombre8); break;
					  case 9 : nombreVenezuela.setTexture(textureNombre9); break;
					  case 10 : nombreVenezuela.setTexture(textureNombre10); break;
					  case 11 : nombreVenezuela.setTexture(textureNombre11); break;
					  case 12 : nombreVenezuela.setTexture(textureNombre12); break;
					  case 13 : nombreVenezuela.setTexture(textureNombre13); break;
					  case 14 : nombreVenezuela.setTexture(textureNombre14); break;
					  case 15 : nombreVenezuela.setTexture(textureNombre15); break;
					  case 16 : nombreVenezuela.setTexture(textureNombre16); break;
					  case 17 : nombreVenezuela.setTexture(textureNombre17); break;
					  case 18 : nombreVenezuela.setTexture(textureNombre18); break;
					  case 19 : nombreVenezuela.setTexture(textureNombre19); break;
					  case 20 : nombreVenezuela.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreGrandeBretagne ; 
			nombreGrandeBretagne.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreGrandeBretagne.setPosition(sf::Vector2f(480.f, 231.f));
			Nombre = listeArmee2[31].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreGrandeBretagne.setTexture(textureNombre0); break; 
					  case 1 : nombreGrandeBretagne.setTexture(textureNombre1); break;
					  case 2 : nombreGrandeBretagne.setTexture(textureNombre2); break;
					  case 3 : nombreGrandeBretagne.setTexture(textureNombre3); break;
					  case 4 : nombreGrandeBretagne.setTexture(textureNombre4); break;
					  case 5 : nombreGrandeBretagne.setTexture(textureNombre5); break;
					  case 6 : nombreGrandeBretagne.setTexture(textureNombre6); break;
					  case 7 : nombreGrandeBretagne.setTexture(textureNombre7); break;
					  case 8 : nombreGrandeBretagne.setTexture(textureNombre8); break;
					  case 9 : nombreGrandeBretagne.setTexture(textureNombre9); break;
					  case 10 : nombreGrandeBretagne.setTexture(textureNombre10); break;
					  case 11 : nombreGrandeBretagne.setTexture(textureNombre11); break;
					  case 12 : nombreGrandeBretagne.setTexture(textureNombre12); break;
					  case 13 : nombreGrandeBretagne.setTexture(textureNombre13); break;
					  case 14 : nombreGrandeBretagne.setTexture(textureNombre14); break;
					  case 15 : nombreGrandeBretagne.setTexture(textureNombre15); break;
					  case 16 : nombreGrandeBretagne.setTexture(textureNombre16); break;
					  case 17 : nombreGrandeBretagne.setTexture(textureNombre17); break;
					  case 18 : nombreGrandeBretagne.setTexture(textureNombre18); break;
					  case 19 : nombreGrandeBretagne.setTexture(textureNombre19); break;
					  case 20 : nombreGrandeBretagne.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreIslande ; 
			nombreIslande.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreIslande.setPosition(sf::Vector2f(476.f, 172.f));
			Nombre = listeArmee2[32].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreIslande.setTexture(textureNombre0); break; 
					  case 1 : nombreIslande.setTexture(textureNombre1); break;
					  case 2 : nombreIslande.setTexture(textureNombre2); break;
					  case 3 : nombreIslande.setTexture(textureNombre3); break;
					  case 4 : nombreIslande.setTexture(textureNombre4); break;
					  case 5 : nombreIslande.setTexture(textureNombre5); break;
					  case 6 : nombreIslande.setTexture(textureNombre6); break;
					  case 7 : nombreIslande.setTexture(textureNombre7); break;
					  case 8 : nombreIslande.setTexture(textureNombre8); break;
					  case 9 : nombreIslande.setTexture(textureNombre9); break;
					  case 10 : nombreIslande.setTexture(textureNombre10); break;
					  case 11 : nombreIslande.setTexture(textureNombre11); break;
					  case 12 : nombreIslande.setTexture(textureNombre12); break;
					  case 13 : nombreIslande.setTexture(textureNombre13); break;
					  case 14 : nombreIslande.setTexture(textureNombre14); break;
					  case 15 : nombreIslande.setTexture(textureNombre15); break;
					  case 16 : nombreIslande.setTexture(textureNombre16); break;
					  case 17 : nombreIslande.setTexture(textureNombre17); break;
					  case 18 : nombreIslande.setTexture(textureNombre18); break;
					  case 19 : nombreIslande.setTexture(textureNombre19); break;
					  case 20 : nombreIslande.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreEuropeDuNord ; 
			nombreEuropeDuNord.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreEuropeDuNord.setPosition(sf::Vector2f(547.f, 252.f));
			Nombre = listeArmee2[33].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreEuropeDuNord.setTexture(textureNombre0); break; 
					  case 1 : nombreEuropeDuNord.setTexture(textureNombre1); break;
					  case 2 : nombreEuropeDuNord.setTexture(textureNombre2); break;
					  case 3 : nombreEuropeDuNord.setTexture(textureNombre3); break;
					  case 4 : nombreEuropeDuNord.setTexture(textureNombre4); break;
					  case 5 : nombreEuropeDuNord.setTexture(textureNombre5); break;
					  case 6 : nombreEuropeDuNord.setTexture(textureNombre6); break;
					  case 7 : nombreEuropeDuNord.setTexture(textureNombre7); break;
					  case 8 : nombreEuropeDuNord.setTexture(textureNombre8); break;
					  case 9 : nombreEuropeDuNord.setTexture(textureNombre9); break;
					  case 10 : nombreEuropeDuNord.setTexture(textureNombre10); break;
					  case 11 : nombreEuropeDuNord.setTexture(textureNombre11); break;
					  case 12 : nombreEuropeDuNord.setTexture(textureNombre12); break;
					  case 13 : nombreEuropeDuNord.setTexture(textureNombre13); break;
					  case 14 : nombreEuropeDuNord.setTexture(textureNombre14); break;
					  case 15 : nombreEuropeDuNord.setTexture(textureNombre15); break;
					  case 16 : nombreEuropeDuNord.setTexture(textureNombre16); break;
					  case 17 : nombreEuropeDuNord.setTexture(textureNombre17); break;
					  case 18 : nombreEuropeDuNord.setTexture(textureNombre18); break;
					  case 19 : nombreEuropeDuNord.setTexture(textureNombre19); break;
					  case 20 : nombreEuropeDuNord.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreScandinavie ; 
			nombreScandinavie.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreScandinavie.setPosition(sf::Vector2f(553.f, 200.f));
			Nombre = listeArmee2[34].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreScandinavie.setTexture(textureNombre0); break; 
					  case 1 : nombreScandinavie.setTexture(textureNombre1); break;
					  case 2 : nombreScandinavie.setTexture(textureNombre2); break;
					  case 3 : nombreScandinavie.setTexture(textureNombre3); break;
					  case 4 : nombreScandinavie.setTexture(textureNombre4); break;
					  case 5 : nombreScandinavie.setTexture(textureNombre5); break;
					  case 6 : nombreScandinavie.setTexture(textureNombre6); break;
					  case 7 : nombreScandinavie.setTexture(textureNombre7); break;
					  case 8 : nombreScandinavie.setTexture(textureNombre8); break;
					  case 9 : nombreScandinavie.setTexture(textureNombre9); break;
					  case 10 : nombreScandinavie.setTexture(textureNombre10); break;
					  case 11 : nombreScandinavie.setTexture(textureNombre11); break;
					  case 12 : nombreScandinavie.setTexture(textureNombre12); break;
					  case 13 : nombreScandinavie.setTexture(textureNombre13); break;
					  case 14 : nombreScandinavie.setTexture(textureNombre14); break;
					  case 15 : nombreScandinavie.setTexture(textureNombre15); break;
					  case 16 : nombreScandinavie.setTexture(textureNombre16); break;
					  case 17 : nombreScandinavie.setTexture(textureNombre17); break;
					  case 18 : nombreScandinavie.setTexture(textureNombre18); break;
					  case 19 : nombreScandinavie.setTexture(textureNombre19); break;
					  case 20 : nombreScandinavie.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreEuropeDuSud ; 
			nombreEuropeDuSud.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreEuropeDuSud.setPosition(sf::Vector2f(556.f, 298.f));
			Nombre = listeArmee2[35].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreEuropeDuSud.setTexture(textureNombre0); break; 
					  case 1 : nombreEuropeDuSud.setTexture(textureNombre1); break;
					  case 2 : nombreEuropeDuSud.setTexture(textureNombre2); break;
					  case 3 : nombreEuropeDuSud.setTexture(textureNombre3); break;
					  case 4 : nombreEuropeDuSud.setTexture(textureNombre4); break;
					  case 5 : nombreEuropeDuSud.setTexture(textureNombre5); break;
					  case 6 : nombreEuropeDuSud.setTexture(textureNombre6); break;
					  case 7 : nombreEuropeDuSud.setTexture(textureNombre7); break;
					  case 8 : nombreEuropeDuSud.setTexture(textureNombre8); break;
					  case 9 : nombreEuropeDuSud.setTexture(textureNombre9); break;
					  case 10 : nombreEuropeDuSud.setTexture(textureNombre10); break;
					  case 11 : nombreEuropeDuSud.setTexture(textureNombre11); break;
					  case 12 : nombreEuropeDuSud.setTexture(textureNombre12); break;
					  case 13 : nombreEuropeDuSud.setTexture(textureNombre13); break;
					  case 14 : nombreEuropeDuSud.setTexture(textureNombre14); break;
					  case 15 : nombreEuropeDuSud.setTexture(textureNombre15); break;
					  case 16 : nombreEuropeDuSud.setTexture(textureNombre16); break;
					  case 17 : nombreEuropeDuSud.setTexture(textureNombre17); break;
					  case 18 : nombreEuropeDuSud.setTexture(textureNombre18); break;
					  case 19 : nombreEuropeDuSud.setTexture(textureNombre19); break;
					  case 20 : nombreEuropeDuSud.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreUkraine ; 
			nombreUkraine.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreUkraine.setPosition(sf::Vector2f(614.f, 228.f));
			Nombre = listeArmee2[36].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreUkraine.setTexture(textureNombre0); break; 
					  case 1 : nombreUkraine.setTexture(textureNombre1); break;
					  case 2 : nombreUkraine.setTexture(textureNombre2); break;
					  case 3 : nombreUkraine.setTexture(textureNombre3); break;
					  case 4 : nombreUkraine.setTexture(textureNombre4); break;
					  case 5 : nombreUkraine.setTexture(textureNombre5); break;
					  case 6 : nombreUkraine.setTexture(textureNombre6); break;
					  case 7 : nombreUkraine.setTexture(textureNombre7); break;
					  case 8 : nombreUkraine.setTexture(textureNombre8); break;
					  case 9 : nombreUkraine.setTexture(textureNombre9); break;
					  case 10 : nombreUkraine.setTexture(textureNombre10); break;
					  case 11 : nombreUkraine.setTexture(textureNombre11); break;
					  case 12 : nombreUkraine.setTexture(textureNombre12); break;
					  case 13 : nombreUkraine.setTexture(textureNombre13); break;
					  case 14 : nombreUkraine.setTexture(textureNombre14); break;
					  case 15 : nombreUkraine.setTexture(textureNombre15); break;
					  case 16 : nombreUkraine.setTexture(textureNombre16); break;
					  case 17 : nombreUkraine.setTexture(textureNombre17); break;
					  case 18 : nombreUkraine.setTexture(textureNombre18); break;
					  case 19 : nombreUkraine.setTexture(textureNombre19); break;
					  case 20 : nombreUkraine.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreEuropeOccidentale ; 
			nombreEuropeOccidentale.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreEuropeOccidentale.setPosition(sf::Vector2f(498.f, 289.f));
			Nombre = listeArmee2[37].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreEuropeOccidentale.setTexture(textureNombre0); break; 
					  case 1 : nombreEuropeOccidentale.setTexture(textureNombre1); break;
					  case 2 : nombreEuropeOccidentale.setTexture(textureNombre2); break;
					  case 3 : nombreEuropeOccidentale.setTexture(textureNombre3); break;
					  case 4 : nombreEuropeOccidentale.setTexture(textureNombre4); break;
					  case 5 : nombreEuropeOccidentale.setTexture(textureNombre5); break;
					  case 6 : nombreEuropeOccidentale.setTexture(textureNombre6); break;
					  case 7 : nombreEuropeOccidentale.setTexture(textureNombre7); break;
					  case 8 : nombreEuropeOccidentale.setTexture(textureNombre8); break;
					  case 9 : nombreEuropeOccidentale.setTexture(textureNombre9); break;
					  case 10 : nombreEuropeOccidentale.setTexture(textureNombre10); break;
					  case 11 : nombreEuropeOccidentale.setTexture(textureNombre11); break;
					  case 12 : nombreEuropeOccidentale.setTexture(textureNombre12); break;
					  case 13 : nombreEuropeOccidentale.setTexture(textureNombre13); break;
					  case 14 : nombreEuropeOccidentale.setTexture(textureNombre14); break;
					  case 15 : nombreEuropeOccidentale.setTexture(textureNombre15); break;
					  case 16 : nombreEuropeOccidentale.setTexture(textureNombre16); break;
					  case 17 : nombreEuropeOccidentale.setTexture(textureNombre17); break;
					  case 18 : nombreEuropeOccidentale.setTexture(textureNombre18); break;
					  case 19 : nombreEuropeOccidentale.setTexture(textureNombre19); break;
					  case 20 : nombreEuropeOccidentale.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAustralieOrientale ; 
			nombreAustralieOrientale.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAustralieOrientale.setPosition(sf::Vector2f(908.f, 568.f));
			Nombre = listeArmee2[38].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAustralieOrientale.setTexture(textureNombre0); break; 
					  case 1 : nombreAustralieOrientale.setTexture(textureNombre1); break;
					  case 2 : nombreAustralieOrientale.setTexture(textureNombre2); break;
					  case 3 : nombreAustralieOrientale.setTexture(textureNombre3); break;
					  case 4 : nombreAustralieOrientale.setTexture(textureNombre4); break;
					  case 5 : nombreAustralieOrientale.setTexture(textureNombre5); break;
					  case 6 : nombreAustralieOrientale.setTexture(textureNombre6); break;
					  case 7 : nombreAustralieOrientale.setTexture(textureNombre7); break;
					  case 8 : nombreAustralieOrientale.setTexture(textureNombre8); break;
					  case 9 : nombreAustralieOrientale.setTexture(textureNombre9); break;
					  case 10 : nombreAustralieOrientale.setTexture(textureNombre10); break;
					  case 11 : nombreAustralieOrientale.setTexture(textureNombre11); break;
					  case 12 : nombreAustralieOrientale.setTexture(textureNombre12); break;
					  case 13 : nombreAustralieOrientale.setTexture(textureNombre13); break;
					  case 14 : nombreAustralieOrientale.setTexture(textureNombre14); break;
					  case 15 : nombreAustralieOrientale.setTexture(textureNombre15); break;
					  case 16 : nombreAustralieOrientale.setTexture(textureNombre16); break;
					  case 17 : nombreAustralieOrientale.setTexture(textureNombre17); break;
					  case 18 : nombreAustralieOrientale.setTexture(textureNombre18); break;
					  case 19 : nombreAustralieOrientale.setTexture(textureNombre19); break;
					  case 20 : nombreAustralieOrientale.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreIndonesie ; 
			nombreIndonesie.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreIndonesie.setPosition(sf::Vector2f(811.f, 462.f));
			Nombre = listeArmee2[39].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreIndonesie.setTexture(textureNombre0); break; 
					  case 1 : nombreIndonesie.setTexture(textureNombre1); break;
					  case 2 : nombreIndonesie.setTexture(textureNombre2); break;
					  case 3 : nombreIndonesie.setTexture(textureNombre3); break;
					  case 4 : nombreIndonesie.setTexture(textureNombre4); break;
					  case 5 : nombreIndonesie.setTexture(textureNombre5); break;
					  case 6 : nombreIndonesie.setTexture(textureNombre6); break;
					  case 7 : nombreIndonesie.setTexture(textureNombre7); break;
					  case 8 : nombreIndonesie.setTexture(textureNombre8); break;
					  case 9 : nombreIndonesie.setTexture(textureNombre9); break;
					  case 10 : nombreIndonesie.setTexture(textureNombre10); break;
					  case 11 : nombreIndonesie.setTexture(textureNombre11); break;
					  case 12 : nombreIndonesie.setTexture(textureNombre12); break;
					  case 13 : nombreIndonesie.setTexture(textureNombre13); break;
					  case 14 : nombreIndonesie.setTexture(textureNombre14); break;
					  case 15 : nombreIndonesie.setTexture(textureNombre15); break;
					  case 16 : nombreIndonesie.setTexture(textureNombre16); break;
					  case 17 : nombreIndonesie.setTexture(textureNombre17); break;
					  case 18 : nombreIndonesie.setTexture(textureNombre18); break;
					  case 19 : nombreIndonesie.setTexture(textureNombre19); break;
					  case 20 : nombreIndonesie.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreNouvelleGuinee ; 
			nombreNouvelleGuinee.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreNouvelleGuinee.setPosition(sf::Vector2f(914.f, 473.f));
			Nombre = listeArmee2[40].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreNouvelleGuinee.setTexture(textureNombre0); break; 
					  case 1 : nombreNouvelleGuinee.setTexture(textureNombre1); break;
					  case 2 : nombreNouvelleGuinee.setTexture(textureNombre2); break;
					  case 3 : nombreNouvelleGuinee.setTexture(textureNombre3); break;
					  case 4 : nombreNouvelleGuinee.setTexture(textureNombre4); break;
					  case 5 : nombreNouvelleGuinee.setTexture(textureNombre5); break;
					  case 6 : nombreNouvelleGuinee.setTexture(textureNombre6); break;
					  case 7 : nombreNouvelleGuinee.setTexture(textureNombre7); break;
					  case 8 : nombreNouvelleGuinee.setTexture(textureNombre8); break;
					  case 9 : nombreNouvelleGuinee.setTexture(textureNombre9); break;
					  case 10 : nombreNouvelleGuinee.setTexture(textureNombre10); break;
					  case 11 : nombreNouvelleGuinee.setTexture(textureNombre11); break;
					  case 12 : nombreNouvelleGuinee.setTexture(textureNombre12); break;
					  case 13 : nombreNouvelleGuinee.setTexture(textureNombre13); break;
					  case 14 : nombreNouvelleGuinee.setTexture(textureNombre14); break;
					  case 15 : nombreNouvelleGuinee.setTexture(textureNombre15); break;
					  case 16 : nombreNouvelleGuinee.setTexture(textureNombre16); break;
					  case 17 : nombreNouvelleGuinee.setTexture(textureNombre17); break;
					  case 18 : nombreNouvelleGuinee.setTexture(textureNombre18); break;
					  case 19 : nombreNouvelleGuinee.setTexture(textureNombre19); break;
					  case 20 : nombreNouvelleGuinee.setTexture(textureNombre20); break;
					}
			sf::Sprite nombreAustralieOccidentale ; 
			nombreAustralieOccidentale.setScale(sf::Vector2f(0.5f, 0.5f));
			nombreAustralieOccidentale.setPosition(sf::Vector2f(848.f, 552.f));
			Nombre = listeArmee2[41].get() ;
			nbrArmees = Nombre -> getNombre() ; 
			switch (nbrArmees) {
					  case 0 : nombreAustralieOccidentale.setTexture(textureNombre0); break; 
					  case 1 : nombreAustralieOccidentale.setTexture(textureNombre1); break;
					  case 2 : nombreAustralieOccidentale.setTexture(textureNombre2); break;
					  case 3 : nombreAustralieOccidentale.setTexture(textureNombre3); break;
					  case 4 : nombreAustralieOccidentale.setTexture(textureNombre4); break;
					  case 5 : nombreAustralieOccidentale.setTexture(textureNombre5); break;
					  case 6 : nombreAustralieOccidentale.setTexture(textureNombre6); break;
					  case 7 : nombreAustralieOccidentale.setTexture(textureNombre7); break;
					  case 8 : nombreAustralieOccidentale.setTexture(textureNombre8); break;
					  case 9 : nombreAustralieOccidentale.setTexture(textureNombre9); break;
					  case 10 : nombreAustralieOccidentale.setTexture(textureNombre10); break;
					  case 11 : nombreAustralieOccidentale.setTexture(textureNombre11); break;
					  case 12 : nombreAustralieOccidentale.setTexture(textureNombre12); break;
					  case 13 : nombreAustralieOccidentale.setTexture(textureNombre13); break;
					  case 14 : nombreAustralieOccidentale.setTexture(textureNombre14); break;
					  case 15 : nombreAustralieOccidentale.setTexture(textureNombre15); break;
					  case 16 : nombreAustralieOccidentale.setTexture(textureNombre16); break;
					  case 17 : nombreAustralieOccidentale.setTexture(textureNombre17); break;
					  case 18 : nombreAustralieOccidentale.setTexture(textureNombre18); break;
					  case 19 : nombreAustralieOccidentale.setTexture(textureNombre19); break;
					  case 20 : nombreAustralieOccidentale.setTexture(textureNombre20); break;
					}

						
			window.draw(nombreCongo);
			window.draw(nombreAfriqueDeLEst); 
			window.draw(nombreEgypte); 
			window.draw(nombreMadagascar);
			window.draw(nombreAfriqueDuNord); 
			window.draw(nombreAfriqueDuSud);
			window.draw(nombreAlaska);
			window.draw(nombreAlberta); 
			window.draw(nombreAmeriqueCentrale); 
			window.draw(nombreEtatDeLEst);
			window.draw(nombreGroenland); 
			window.draw(nombreTerritoireDuNordOuest);
			window.draw(nombreOntario);
			window.draw(nombreQuebec); 
			window.draw(nombreEtatDeLOuest); 
			window.draw(nombreArgentine);
			window.draw(nombreBresil); 
			window.draw(nombrePerou);
			window.draw(nombreVenezuela);
			window.draw(nombreAustralieOrientale); 
			window.draw(nombreIndonesie); 
			window.draw(nombreNouvelleGuinee);
			window.draw(nombreAustralieOccidentale); 
			window.draw(nombreAfghanistan);
			window.draw(nombreChine);
			window.draw(nombreInde); 
			window.draw(nombreTchita); 
			window.draw(nombreJapon);
			window.draw(nombreKamtchatka); 
			window.draw(nombreMoyenOrient);
			window.draw(nombreMongolie);
			window.draw(nombreSiam); 
			window.draw(nombreSiberie); 
			window.draw(nombreOural);
			window.draw(nombreYakoutie); 
			window.draw(nombreGrandeBretagne);
			window.draw(nombreIslande);
			window.draw(nombreEuropeDuNord); 
			window.draw(nombreScandinavie); 
			window.draw(nombreEuropeDuSud);
			window.draw(nombreUkraine); 
			window.draw(nombreEuropeOccidentale);
			//window.display(); 
		}
void Affichage::AfficheCartes(state::State& state, sf::RenderWindow& window)
{
	while(window.isOpen())
		{
			sf::Texture texture2 ;
			texture2.loadFromFile("./res/tank384px.png");					        
			texture2.setSmooth(true);
			sf::Sprite sprite2 ;
			sprite2.setTexture(texture2);
			sprite2.setScale(sf::Vector2f(0.08f, 0.08f));
			sprite2.setPosition(sf::Vector2f(95.f, 271.f));
		}
}

void Affichage::AfficheArmees(state::State& state, sf::RenderWindow& window)
{
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee2 = tabArmee.getElementList();
	
	state::Element* Armee;
	
	sf::Texture textureArmee ;
	textureArmee.loadFromFile("./res/pion_blanc.png");
	
								sf::Sprite armeeCongo ;
								armeeCongo.setTexture(textureArmee);
								armeeCongo.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeCongo.setPosition(sf::Vector2f(531.f, 463.f));
								Armee = listeArmee2[0].get() ;
									if(Armee -> getIdJoueur()==1)
									{
										armeeCongo.setColor(sf::Color(255, 0, 0));
									}
									if(Armee -> getIdJoueur()==2)
									{
										armeeCongo.setColor(sf::Color(0, 255, 0));
									}
									if(Armee -> getIdJoueur()==3)
									{
										armeeCongo.setColor(sf::Color(0, 0, 255));
									}
								sf::Sprite armeeAfriqueDeLEst ;
								armeeAfriqueDeLEst.setTexture(textureArmee);
								armeeAfriqueDeLEst.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAfriqueDeLEst.setPosition(sf::Vector2f(580.f, 429.f));
								Armee = listeArmee2[1].get() ;
									if(Armee -> getIdJoueur()==1)
									{
										armeeAfriqueDeLEst.setColor(sf::Color(255, 0, 0));
									}
									if(Armee -> getIdJoueur()==2)
									{
										armeeAfriqueDeLEst.setColor(sf::Color(0, 255, 0));
									}
									if(Armee -> getIdJoueur()==3)
									{
										armeeAfriqueDeLEst.setColor(sf::Color(0, 0, 255));
									}
								sf::Sprite armeeEgypte ;
								armeeEgypte.setTexture(textureArmee);
								armeeEgypte.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeEgypte.setPosition(sf::Vector2f(549.f, 361.f));
								Armee = listeArmee2[2].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeEgypte.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeEgypte.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeEgypte.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeMadagascar ;
								armeeMadagascar.setTexture(textureArmee);
								armeeMadagascar.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeMadagascar.setPosition(sf::Vector2f(627.f, 500.f));
								Armee = listeArmee2[3].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeMadagascar.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeMadagascar.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeMadagascar.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeAfriqueDuNord ;
								armeeAfriqueDuNord.setTexture(textureArmee);
								armeeAfriqueDuNord.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAfriqueDuNord.setPosition(sf::Vector2f(471.f, 388.f));
								Armee = listeArmee2[4].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAfriqueDuNord.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAfriqueDuNord.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAfriqueDuNord.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeAfriqueDuSud ;
								armeeAfriqueDuSud.setTexture(textureArmee);
								armeeAfriqueDuSud.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAfriqueDuSud.setPosition(sf::Vector2f(547.f, 521.f));
								Armee = listeArmee2[5].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAfriqueDuSud.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAfriqueDuSud.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAfriqueDuSud.setColor(sf::Color(0, 0, 255));
												}
			
								//ARMEE AMERIQUE DU NORD
								sf::Sprite armeeAlberta ;
								armeeAlberta.setTexture(textureArmee);
								armeeAlberta.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAlberta.setPosition(sf::Vector2f(164.f, 218.f));
								Armee = listeArmee2[19].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAlberta.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAlberta.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAlberta.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeAmeriqueCentrale ;
								armeeAmeriqueCentrale.setTexture(textureArmee);
								armeeAmeriqueCentrale.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAmeriqueCentrale.setPosition(sf::Vector2f(200.f, 327.f));
								Armee = listeArmee2[20].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAmeriqueCentrale.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAmeriqueCentrale.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAmeriqueCentrale.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeEtatDeLEst ;
								armeeEtatDeLEst.setTexture(textureArmee);
								armeeEtatDeLEst.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeEtatDeLEst.setPosition(sf::Vector2f(238.f, 286.f));
								Armee = listeArmee2[21].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeEtatDeLEst.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeEtatDeLEst.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeEtatDeLEst.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeGroenland ;
								armeeGroenland.setTexture(textureArmee);
								armeeGroenland.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeGroenland.setPosition(sf::Vector2f(362.f, 97.f));
								Armee = listeArmee2[22].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeGroenland.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeGroenland.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeGroenland.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeTerritoireDuNordOuest ;
								armeeTerritoireDuNordOuest.setTexture(textureArmee);
								armeeTerritoireDuNordOuest.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeTerritoireDuNordOuest.setPosition(sf::Vector2f(161.f, 170.f));
								Armee = listeArmee2[23].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeTerritoireDuNordOuest.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeTerritoireDuNordOuest.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeTerritoireDuNordOuest.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeOntario ;
								armeeOntario.setTexture(textureArmee);
								armeeOntario.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeOntario.setPosition(sf::Vector2f(231.f, 236.f));
								Armee = listeArmee2[24].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeOntario.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeOntario.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeOntario.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeQuebec ;
								armeeQuebec.setTexture(textureArmee);
								armeeQuebec.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeQuebec.setPosition(sf::Vector2f(298.f, 225.f));
								Armee = listeArmee2[25].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeQuebec.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeQuebec.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeQuebec.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeEtatDeLOuest ;
								armeeEtatDeLOuest.setTexture(textureArmee);
								armeeEtatDeLOuest.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeEtatDeLOuest.setPosition(sf::Vector2f(167.f, 274.f));
								Armee = listeArmee2[26].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeEtatDeLOuest.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeEtatDeLOuest.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeEtatDeLOuest.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeAlaska ;
								armeeAlaska.setTexture(textureArmee);
								armeeAlaska.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAlaska.setPosition(sf::Vector2f(66.f, 165.f));
								Armee = listeArmee2[18].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAlaska.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAlaska.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAlaska.setColor(sf::Color(0, 0, 255));
												}
			
								//armee AMERIQUE DU SUD
								sf::Sprite armeeArgentine ;
								armeeArgentine.setTexture(textureArmee);
								armeeArgentine.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeArgentine.setPosition(sf::Vector2f(302.f, 530.f));
								Armee = listeArmee2[27].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeArgentine.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeArgentine.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeArgentine.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeBresil ;
								armeeBresil.setTexture(textureArmee);
								armeeBresil.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeBresil.setPosition(sf::Vector2f(349.f, 456.f));
								Armee = listeArmee2[28].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeBresil.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeBresil.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeBresil.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeePerou ;
								armeePerou.setTexture(textureArmee);
								armeePerou.setScale(sf::Vector2f(0.2f, 0.2f));
								armeePerou.setPosition(sf::Vector2f(295.f, 391.f));
								Armee = listeArmee2[29].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeePerou.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeePerou.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeePerou.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeVenezuela ;
								armeeVenezuela.setTexture(textureArmee);
								armeeVenezuela.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeVenezuela.setPosition(sf::Vector2f(298.f, 474.f));
								Armee = listeArmee2[30].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeVenezuela.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeVenezuela.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeVenezuela.setColor(sf::Color(0, 0, 255));
												}
			
			
								//armee EUROPE
								sf::Sprite armeeGrandeBretagne ;
								armeeGrandeBretagne.setTexture(textureArmee);
								armeeGrandeBretagne.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeGrandeBretagne.setPosition(sf::Vector2f(460.f, 231.f));
								Armee = listeArmee2[31].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeGrandeBretagne.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeGrandeBretagne.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeGrandeBretagne.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeIslande ;
								armeeIslande.setTexture(textureArmee);
								armeeIslande.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeIslande.setPosition(sf::Vector2f(456.f, 171.f));
								Armee = listeArmee2[32].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeIslande.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeIslande.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeIslande.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeEuropeDuNord ;
								armeeEuropeDuNord.setTexture(textureArmee);
								armeeEuropeDuNord.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeEuropeDuNord.setPosition(sf::Vector2f(527.f, 252.f));
								Armee = listeArmee2[33].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeEuropeDuNord.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeEuropeDuNord.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeEuropeDuNord.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeScandinavie ;
								armeeScandinavie.setTexture(textureArmee);
								armeeScandinavie.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeScandinavie.setPosition(sf::Vector2f(532.f, 200.f));
								Armee = listeArmee2[34].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeScandinavie.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeScandinavie.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeScandinavie.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeEuropeDuSud ;
								armeeEuropeDuSud.setTexture(textureArmee);
								armeeEuropeDuSud.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeEuropeDuSud.setPosition(sf::Vector2f(536.f, 297.f));
								Armee = listeArmee2[35].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeEuropeDuSud.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeEuropeDuSud.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeEuropeDuSud.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeUkraine ;
								armeeUkraine.setTexture(textureArmee);
								armeeUkraine.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeUkraine.setPosition(sf::Vector2f(594.f, 227.f));
								Armee = listeArmee2[36].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeUkraine.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeUkraine.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeUkraine.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeEuropeOccidentale ;
								armeeEuropeOccidentale.setTexture(textureArmee);
								armeeEuropeOccidentale.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeEuropeOccidentale.setPosition(sf::Vector2f(478.f, 289.f));
								Armee = listeArmee2[37].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeEuropeOccidentale.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeEuropeOccidentale.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeEuropeOccidentale.setColor(sf::Color(0, 0, 255));
												}
			
			
								//armee ASIE
								sf::Sprite armeeAfghanistan ;
								armeeAfghanistan.setTexture(textureArmee);
								armeeAfghanistan.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAfghanistan.setPosition(sf::Vector2f(667.f, 293.f));
								Armee = listeArmee2[6].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAfghanistan.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAfghanistan.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAfghanistan.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeChine ;
								armeeChine.setTexture(textureArmee);
								armeeChine.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeChine.setPosition(sf::Vector2f(784.f, 325.f));
								Armee = listeArmee2[7].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeChine.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeChine.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeChine.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeInde ;
								armeeInde.setTexture(textureArmee);
								armeeInde.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeInde.setPosition(sf::Vector2f(706.f, 373.f));
								Armee = listeArmee2[8].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeInde.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeInde.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeInde.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeTchita ;
								armeeTchita.setTexture(textureArmee);
								armeeTchita.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeTchita.setPosition(sf::Vector2f(801.f, 220.f));
								Armee = listeArmee2[9].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeTchita.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeTchita.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeTchita.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeJapon ;
								armeeJapon.setTexture(textureArmee);
								armeeJapon.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeJapon.setPosition(sf::Vector2f(892.f, 324.f));
								Armee = listeArmee2[10].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeJapon.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeJapon.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeJapon.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeKamtchatka ;
								armeeKamtchatka.setTexture(textureArmee);
								armeeKamtchatka.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeKamtchatka.setPosition(sf::Vector2f(930.f, 190.f));
								Armee = listeArmee2[11].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeKamtchatka.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeKamtchatka.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeKamtchatka.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeMoyenOrient ;
								armeeMoyenOrient.setTexture(textureArmee);
								armeeMoyenOrient.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeMoyenOrient.setPosition(sf::Vector2f(620.f, 351.f));
								Armee = listeArmee2[12].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeMoyenOrient.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeMoyenOrient.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeMoyenOrient.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeMongolie ;
								armeeMongolie.setTexture(textureArmee);
								armeeMongolie.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeMongolie.setPosition(sf::Vector2f(806.f, 276.f));
								Armee = listeArmee2[13].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeMongolie.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeMongolie.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeMongolie.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeSiam ;
								armeeSiam.setTexture(textureArmee);
								armeeSiam.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeSiam.setPosition(sf::Vector2f(770.f, 381.f));
								Armee = listeArmee2[14].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeSiam.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeSiam.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeSiam.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeSiberie ;
								armeeSiberie.setTexture(textureArmee);
								armeeSiberie.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeSiberie.setPosition(sf::Vector2f(731.f, 197.f));
								Armee = listeArmee2[15].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeSiberie.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeSiberie.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeSiberie.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeOural ;
								armeeOural.setTexture(textureArmee);
								armeeOural.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeOural.setPosition(sf::Vector2f(664.f, 222.f));
								Armee = listeArmee2[16].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeOural.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeOural.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeOural.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeYakoutie ;
								armeeYakoutie.setTexture(textureArmee);
								armeeYakoutie.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeYakoutie.setPosition(sf::Vector2f(823.f, 158.f));
								Armee = listeArmee2[17].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeYakoutie.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeYakoutie.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeYakoutie.setColor(sf::Color(0, 0, 255));
												}
			
								//armee AUSTRALIE
								sf::Sprite armeeAustralieOrientale ;
								armeeAustralieOrientale.setTexture(textureArmee);
								armeeAustralieOrientale.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAustralieOrientale.setPosition(sf::Vector2f(887.f, 567.f));
								Armee = listeArmee2[38].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAustralieOrientale.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAustralieOrientale.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAustralieOrientale.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeIndonesie ;
								armeeIndonesie.setTexture(textureArmee);
								armeeIndonesie.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeIndonesie.setPosition(sf::Vector2f(791.f, 462.f));
								Armee = listeArmee2[39].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeIndonesie.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeIndonesie.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeIndonesie.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeNouvelleGuinee ;
								armeeNouvelleGuinee.setTexture(textureArmee);
								armeeNouvelleGuinee.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeNouvelleGuinee.setPosition(sf::Vector2f(894.f, 473.f));
								Armee = listeArmee2[40].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeNouvelleGuinee.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeNouvelleGuinee.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeNouvelleGuinee.setColor(sf::Color(0, 0, 255));
												}
								sf::Sprite armeeAustralieOccidentale ;
								armeeAustralieOccidentale.setTexture(textureArmee);
								armeeAustralieOccidentale.setScale(sf::Vector2f(0.2f, 0.2f));
								armeeAustralieOccidentale.setPosition(sf::Vector2f(828.f, 552.f));
								Armee = listeArmee2[41].get() ;
												if(Armee -> getIdJoueur()==1)
												{
													armeeAustralieOccidentale.setColor(sf::Color(255, 0, 0));
												}
												if(Armee -> getIdJoueur()==2)
												{
													armeeAustralieOccidentale.setColor(sf::Color(0, 255, 0));
												}
												if(Armee -> getIdJoueur()==3)
												{
													armeeAustralieOccidentale.setColor(sf::Color(0, 0, 255));
												}
			
								//window.clear();
								window.draw(armeeCongo);
								window.draw(armeeAfriqueDeLEst);
								window.draw(armeeEgypte);
								window.draw(armeeMadagascar);
								window.draw(armeeAfriqueDuNord);
								window.draw(armeeAfriqueDuSud);
								window.draw(armeeAlberta);
								window.draw(armeeAmeriqueCentrale);
								window.draw(armeeEtatDeLOuest);
								window.draw(armeeEtatDeLEst);
								window.draw(armeeGroenland);
								window.draw(armeeTerritoireDuNordOuest);
								window.draw(armeeOntario);
								window.draw(armeeQuebec);
								window.draw(armeeAlaska);
								window.draw(armeePerou);
								window.draw(armeeArgentine);
								window.draw(armeeBresil);
								window.draw(armeeVenezuela);
								window.draw(armeeGrandeBretagne);
								window.draw(armeeIslande);
								window.draw(armeeEuropeDuNord);
								window.draw(armeeScandinavie);
								window.draw(armeeEuropeDuSud);
								window.draw(armeeUkraine);
								window.draw(armeeEuropeOccidentale);
								window.draw(armeeMoyenOrient);
								window.draw(armeeMongolie);
								window.draw(armeeSiam);
								window.draw(armeeSiberie);
								window.draw(armeeOural);
								window.draw(armeeYakoutie);
								window.draw(armeeAfghanistan);
								window.draw(armeeChine);
								window.draw(armeeInde);
								window.draw(armeeTchita);
								window.draw(armeeJapon);
								window.draw(armeeKamtchatka);
								window.draw(armeeAustralieOrientale);
								window.draw(armeeAustralieOccidentale);
								window.draw(armeeNouvelleGuinee);
								window.draw(armeeIndonesie);
								//window.display();
	
}

std::string Affichage::PaysClic(sf::RenderWindow& window, sf::Event event)
{
	std::cout<<"test clib demarre"<<std::endl ; 
	float fa_x = 0.9;
	float fa_y = 0.9 ;
	std::string pays_clic = "";
	
			       
			        window.setKeyRepeatEnabled(false) ; //annule la répétition des clics
			       //cas où la fenêtre est redimensionnée
			        
			  
			        if (event.type == sf::Event::Resized)
			        {
			            //std::cout << "new width: " << event.size.width << std::endl;
			            //std::cout << "new height: " << event.size.height << std::endl;
			            fa_x = float(0.9*(event.size.width/1280));
			            fa_y = float(0.9*(event.size.width/720));
			        }
			        
			        if (event.type == sf::Event::MouseButtonPressed)
						{
							if(event.mouseButton.button ==sf::Mouse::Right)
							{
								std::cout << "Bouton droit pressé" <<std::endl ;
								std::cout << "Position souris x: " << event.mouseButton.x << std::endl;
								std::cout << "Position souris y: " << event.mouseButton.y << std::endl;


							}
							if(event.mouseButton.button ==sf::Mouse::Left)
							{
								std::cout << "Bouton gauche pressé" <<std::endl ;
								std::cout << "Position souris x: " << event.mouseButton.x << std::endl;
								std::cout << "Position souris y: " << event.mouseButton.y << std::endl;
								if(event.mouseButton.x>(72*fa_x) && event.mouseButton.x <(134*fa_x) && event.mouseButton.y >(187*fa_y) && event.mouseButton.y<(230*fa_y))
													{
														pays_clic = "Alaska";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;

													}
								if(event.mouseButton.x>(179*fa_x) && event.mouseButton.x <(244*fa_x) && event.mouseButton.y >(241*fa_y) && event.mouseButton.y<(290*fa_y))
													{
														pays_clic = "Alberta";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(239*fa_x) && event.mouseButton.x <(258*fa_x) && event.mouseButton.y >(374*fa_y) && event.mouseButton.y<(396*fa_y))
													{
														pays_clic = "Amerique Centrale";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(271*fa_x) && event.mouseButton.x <(317*fa_x) && event.mouseButton.y >(317*fa_y) && event.mouseButton.y<(355*fa_y))
													{
														pays_clic = "Etat De L'Est";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(395*fa_x) && event.mouseButton.x <(480*fa_x) && event.mouseButton.y >(81*fa_x) && event.mouseButton.y<(171*fa_y))
													{
														pays_clic = "Groenland";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(166*fa_x) && event.mouseButton.x <(251*fa_x) && event.mouseButton.y >(200*fa_y) && event.mouseButton.y<(226*fa_y))
													{
														pays_clic = "Territoire Du Nord-Ouest";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(257*fa_x) && event.mouseButton.x <(315*fa_x) && event.mouseButton.y >(268*fa_y) && event.mouseButton.y<(294*fa_y))
													{
														pays_clic = "Ontario";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(335*fa_x) && event.mouseButton.x <(386*fa_x) && event.mouseButton.y >(256*fa_y) && event.mouseButton.y<(281*fa_y))
													{
														pays_clic = "Quebec";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(186*fa_x) && event.mouseButton.x <(244*fa_x) && event.mouseButton.y >(304*fa_y) && event.mouseButton.y<(341*fa_y))
													{
														pays_clic = "Etat De L'Ouest";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(350*fa_x) && event.mouseButton.x <(379*fa_x) && event.mouseButton.y >(587*fa_y) && event.mouseButton.y<(627*fa_y))
													{
														pays_clic = "Argentine";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(393*fa_x) && event.mouseButton.x <(441*fa_x) && event.mouseButton.y >(495*fa_y) && event.mouseButton.y<(555*fa_y))
													{
														pays_clic = "Brésil";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(333*fa_x) && event.mouseButton.x <(382*fa_x) && event.mouseButton.y >(445*fa_y) && event.mouseButton.y<(460*fa_y))
													{
														pays_clic = "Pérou";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(348*fa_x) && event.mouseButton.x <(373*fa_x) && event.mouseButton.y >(531*fa_y) && event.mouseButton.y<(560*fa_y))
													{
														pays_clic = "Vénézuela";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(593*fa_x) && event.mouseButton.x <(646*fa_x) && event.mouseButton.y >(503*fa_y) && event.mouseButton.y<(563*fa_y))
													{
														pays_clic = "Congo";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(652*fa_x) && event.mouseButton.x <(696*fa_x) && event.mouseButton.y >(442*fa_y) && event.mouseButton.y<(549*fa_y))
													{
														pays_clic = "Afrique De L'Est";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(610*fa_x) && event.mouseButton.x <(669*fa_x) && event.mouseButton.y >(398*fa_y) && event.mouseButton.y<(440*fa_y))
													{
														pays_clic = "Egypte";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(709*fa_x) && event.mouseButton.x <(729*fa_x) && event.mouseButton.y >(552*fa_y) && event.mouseButton.y<(602*fa_y))
													{
														pays_clic = "Madagascar";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(511*fa_x) && event.mouseButton.x <(595*fa_x) && event.mouseButton.y >(392*fa_y) && event.mouseButton.y<(507*fa_y))
													{
														pays_clic = "Afrique Du Nord";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(615*fa_x) && event.mouseButton.x <(660*fa_x) && event.mouseButton.y >(579*fa_y) && event.mouseButton.y<(616*fa_y))
													{
														pays_clic = "Afrique Du Sud";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(986*fa_x) && event.mouseButton.x <(1045*fa_x) && event.mouseButton.y >(609*fa_y) && event.mouseButton.y<(688*fa_y))
													{
														pays_clic = "Australie Orientale";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(857*fa_x) && event.mouseButton.x <(959*fa_x) && event.mouseButton.y >(499*fa_y) && event.mouseButton.y<(564*fa_y))
													{
														pays_clic = "Indonésie";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(990*fa_x) && event.mouseButton.x <(1056*fa_x) && event.mouseButton.y >(522*fa_y) && event.mouseButton.y<(565*fa_y))
													{
														pays_clic = "Nouvelle-Guinée";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(913*fa_x) && event.mouseButton.x <(985*fa_x) && event.mouseButton.y >(589*fa_y) && event.mouseButton.y<(674*fa_y))
													{
														pays_clic = "Australie Occidentale";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(734*fa_x) && event.mouseButton.x <(808*fa_x) && event.mouseButton.y >(324*fa_y) && event.mouseButton.y<(364*fa_y))
													{
														pays_clic = "Afghanistan";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(861*fa_x) && event.mouseButton.x <(940*fa_x) && event.mouseButton.y >(357*fa_y) && event.mouseButton.y<(402*fa_y))
													{
														pays_clic = "Chine";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(776*fa_x) && event.mouseButton.x <(852*fa_x) && event.mouseButton.y >(393*fa_y) && event.mouseButton.y<(472*fa_y))
													{
														pays_clic = "Inde";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(882*fa_x) && event.mouseButton.x <(957*fa_x) && event.mouseButton.y >(239*fa_y) && event.mouseButton.y<(297*fa_y))
													{
														pays_clic = "Tchita";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(994*fa_x) && event.mouseButton.x <(1046*fa_x) && event.mouseButton.y >(345*fa_y) && event.mouseButton.y<(412*fa_y))
													{
														pays_clic = "Japon";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(1044*fa_x) && event.mouseButton.x <(1134*fa_x) && event.mouseButton.y >(210*fa_y) && event.mouseButton.y<(310*fa_y))
													{
														pays_clic = "Kamtchatka";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(979*fa_x) && event.mouseButton.x <(1034*fa_x) && event.mouseButton.y >(239*fa_y) && event.mouseButton.y<(329*fa_y))
													{
														pays_clic = "Kamtchatka";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(686*fa_x) && event.mouseButton.x <(756*fa_x) && event.mouseButton.y >(371*fa_y) && event.mouseButton.y<(446*fa_y))
													{
														pays_clic = "Moyen-Orient";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(896*fa_x) && event.mouseButton.x <(955*fa_x) && event.mouseButton.y >(312*fa_y) && event.mouseButton.y<(339*fa_y))
													{
														pays_clic = "Mongolie";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(860*fa_x) && event.mouseButton.x <(890*fa_x) && event.mouseButton.y >(413*fa_y) && event.mouseButton.y<(492*fa_y))
													{
														pays_clic = "Siam";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(809*fa_x) && event.mouseButton.x <(875*fa_x) && event.mouseButton.y >(198*fa_y) && event.mouseButton.y<(276*fa_y))
													{
														pays_clic = "Sibérie";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(745*fa_x) && event.mouseButton.x <(790*fa_x) && event.mouseButton.y >(227*fa_y) && event.mouseButton.y<(303*fa_y))
													{
														pays_clic = "Oural";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(790*fa_x) && event.mouseButton.x <(818*fa_x) && event.mouseButton.y >(293*fa_y) && event.mouseButton.y<(318*fa_y))
													{
														pays_clic = "Oural";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(886*fa_x) && event.mouseButton.x <(1001*fa_x) && event.mouseButton.y >(159*fa_y) && event.mouseButton.y<(217*fa_y))
													{
														pays_clic = "Yakoutie";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(513*fa_x) && event.mouseButton.x <(567*fa_x) && event.mouseButton.y >(253*fa_y) && event.mouseButton.y<(297*fa_y))
													{
														pays_clic = "Grande-Bretagne";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(501*fa_x) && event.mouseButton.x <(571*fa_x) && event.mouseButton.y >(187*fa_y) && event.mouseButton.y<(230*fa_y))
													{
														pays_clic = "Islande";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(590*fa_x) && event.mouseButton.x <(639*fa_x) && event.mouseButton.y >(280*fa_y) && event.mouseButton.y<(316*fa_y))
													{
														pays_clic = "Europe Du Nord";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(589*fa_x) && event.mouseButton.x <(653*fa_x) && event.mouseButton.y >(205*fa_y) && event.mouseButton.y<(276*fa_y))
													{
														pays_clic = "Scandinavie";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(596*fa_x) && event.mouseButton.x <(655*fa_x) && event.mouseButton.y >(323*fa_y) && event.mouseButton.y<(374*fa_y))
													{
														pays_clic = "Europe Du Sud";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(658*fa_x) && event.mouseButton.x <(721*fa_x) && event.mouseButton.y >(214*fa_y) && event.mouseButton.y<(328*fa_y))
													{
														pays_clic = "Ukraine";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								if(event.mouseButton.x>(537*fa_x) && event.mouseButton.x <(583*fa_x) && event.mouseButton.y >(306*fa_y) && event.mouseButton.y<(372*fa_y))
													{
														pays_clic = "Europe Occidentale";
														std::cout << "Vous êtes en :" << pays_clic << std::endl ;
													}
								}
						}
		return pays_clic ; 				
			    
}
