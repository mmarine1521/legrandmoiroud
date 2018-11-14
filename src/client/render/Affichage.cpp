#include "render.h"

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



void Affichage::draw (sf::RenderTarget& target, sf::RenderStates states) const 
{	
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
					window.display() ; 
			    }


void static AfficheNombre (state::State& state, sf::RenderWindow& window)
		{
			state::ElementTab& tabArmee = state.getArmeeTab();
			std::vector<std::shared_ptr<state::Element>> listeArmee2 = tabArmee.getElementList();
			
		
			state::Element* Nombre;
		
			sf::Texture textureNombre1 ; sf::Texture textureNombre6 ; sf::Texture textureNombre11 ; sf::Texture textureNombre16 ;
			sf::Texture textureNombre2 ; sf::Texture textureNombre7 ; sf::Texture textureNombre12 ; sf::Texture textureNombre17 ;
			sf::Texture textureNombre3 ; sf::Texture textureNombre8 ; sf::Texture textureNombre13 ; sf::Texture textureNombre18 ;
			sf::Texture textureNombre4 ; sf::Texture textureNombre9 ; sf::Texture textureNombre14 ; sf::Texture textureNombre19 ;
			sf::Texture textureNombre5 ; sf::Texture textureNombre10 ; sf::Texture textureNombre15 ; sf::Texture textureNombre20 ;
			
			textureNombre1.loadFromFile("./res/nombres/1.png");
			textureNombre2.loadFromFile("./res/nombres/2.png");
			textureNombre3.loadFromFile("./res/nombres/3.png");
			textureNombre4.loadFromFile("./res/nombres/4.png");
			textureNombre5.loadFromFile("./res/nombres/5.png");
			textureNombre6.loadFromFile("./res/nombres/6.png");
			textureNombre7.loadFromFile("./res/nombres/7.png");
			textureNombre8.loadFromFile("./res/nombres/8.png");
			textureNombre9.loadFromFile("./res/nombres/9.png");
			textureNombre10.loadFromFile("./res/nombres/10.png");
			textureNombre11.loadFromFile("./res/nombres/11.png");
			textureNombre12.loadFromFile("./res/nombres/12.png");
			textureNombre13.loadFromFile("./res/nombres/13.png");
			textureNombre14.loadFromFile("./res/nombres/14.png");
			textureNombre15.loadFromFile("./res/nombres/15.png");
			textureNombre16.loadFromFile("./res/nombres/16.png");
			textureNombre17.loadFromFile("./res/nombres/17.png");
			textureNombre18.loadFromFile("./res/nombres/18.png");
			textureNombre19.loadFromFile("./res/nombres/19.png");
			textureNombre20.loadFromFile("./res/nombres/20.png");
			
			sf::Sprite nombreCongo ; 
			nombreCongo.setScale(sf::Vector2f(0.2f, 0.2f));
			nombreCongo.setPosition(sf::Vector2f(541.f, 463.f));
			Nombre = listeArmee2[0].get() ;
			int nbrArmees = Nombre -> getNombre()==1 ; 
			switch (nbrArmees) {
					  case 0 : nombreCongo.setTexture(textureNombre1); break; 
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
			window.draw(nombreCongo);
			window.display(); 
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
								armeeCongo.setPosition(sf::Vector2f(541.f, 463.f));
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
								armeeAfriqueDeLEst.setPosition(sf::Vector2f(590.f, 429.f));
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
								armeeEgypte.setPosition(sf::Vector2f(559.f, 361.f));
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
								armeeMadagascar.setPosition(sf::Vector2f(631.f, 503.f));
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
								armeeAfriqueDuNord.setPosition(sf::Vector2f(481.f, 388.f));
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
								armeeAfriqueDuSud.setPosition(sf::Vector2f(557.f, 521.f));
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
								armeeAlberta.setPosition(sf::Vector2f(174.f, 222.f));
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
								armeeAmeriqueCentrale.setPosition(sf::Vector2f(207.f, 330.f));
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
								armeeEtatDeLEst.setPosition(sf::Vector2f(248.f, 286.f));
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
								armeeGroenland.setPosition(sf::Vector2f(377.f, 97.f));
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
								armeeTerritoireDuNordOuest.setPosition(sf::Vector2f(171.f, 175.f));
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
								armeeOntario.setPosition(sf::Vector2f(241.f, 236.f));
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
								armeeQuebec.setPosition(sf::Vector2f(308.f, 225.f));
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
								armeeEtatDeLOuest.setPosition(sf::Vector2f(177.f, 274.f));
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
								armeeAlaska.setPosition(sf::Vector2f(76.f, 171.f));
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
								armeeArgentine.setPosition(sf::Vector2f(312.f, 530.f));
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
								armeeBresil.setPosition(sf::Vector2f(359.f, 456.f));
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
								armeePerou.setPosition(sf::Vector2f(305.f, 391.f));
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
								armeeVenezuela.setPosition(sf::Vector2f(308.f, 474.f));
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
								armeeGrandeBretagne.setPosition(sf::Vector2f(470.f, 231.f));
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
								armeeIslande.setPosition(sf::Vector2f(466.f, 171.f));
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
								armeeEuropeDuNord.setPosition(sf::Vector2f(537.f, 252.f));
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
								armeeScandinavie.setPosition(sf::Vector2f(542.f, 200.f));
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
								armeeEuropeDuSud.setPosition(sf::Vector2f(546.f, 297.f));
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
								armeeUkraine.setPosition(sf::Vector2f(604.f, 227.f));
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
								armeeEuropeOccidentale.setPosition(sf::Vector2f(488.f, 289.f));
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
								armeeAfghanistan.setPosition(sf::Vector2f(677.f, 293.f));
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
								armeeChine.setPosition(sf::Vector2f(794.f, 325.f));
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
								armeeInde.setPosition(sf::Vector2f(716.f, 373.f));
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
								armeeTchita.setPosition(sf::Vector2f(811.f, 225.f));
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
								armeeJapon.setPosition(sf::Vector2f(902.f, 324.f));
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
								armeeKamtchatka.setPosition(sf::Vector2f(964.f, 218.f));
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
								armeeMoyenOrient.setPosition(sf::Vector2f(632.f, 351.f));
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
								armeeMongolie.setPosition(sf::Vector2f(816.f, 276.f));
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
								armeeSiam.setPosition(sf::Vector2f(770.f, 391.f));
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
								armeeSiberie.setPosition(sf::Vector2f(741.f, 197.f));
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
								armeeOural.setPosition(sf::Vector2f(674.f, 222.f));
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
								armeeYakoutie.setPosition(sf::Vector2f(833.f, 153.f));
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
								armeeAustralieOrientale.setPosition(sf::Vector2f(897.f, 567.f));
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
								armeeIndonesie.setPosition(sf::Vector2f(801.f, 462.f));
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
								armeeNouvelleGuinee.setPosition(sf::Vector2f(904.f, 473.f));
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
								armeeAustralieOccidentale.setPosition(sf::Vector2f(838.f, 552.f));
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
								window.display();
	
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
