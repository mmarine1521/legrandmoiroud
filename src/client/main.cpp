#include "state.h"
#include "render.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <memory>

#include <thread>
#include <mutex>

using namespace state;
using namespace std ;
using namespace render ;

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

void testSFML()
	{


	}

int main(int argc,char* argv[])
{
	 //testSFML();
	    if (argc>1){                 // vérifie s'il y a un argument
	        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
	            cout << "Bonjour le monde!" << endl;
	        }
	        else if (strcmp(argv[1],"state")==0){
	                //Test_Unitaire();

	        }

	        else if (strcmp(argv[1],"render")==0){
	            //Test Map
	        			std::cout << "Pour initialiser les pays : cliquez sur 'espace'" << std::endl ;
	        			std::cout << "Pour placer ses armées : cliquez sur 'P'"<< std::endl;
	        			std::cout << "JOUEUR 1 : Rouge" <<std::endl ;
	        			std::cout << "JOUEUR 2 : Vert" <<std::endl ; 
	        			std::cout << "JOUEUR 3 : Bleu" <<std::endl ; 

	        			
	        			ElementTab tabArmee = ElementTab() ; 
	        			tabArmee.ElementTab::remplirArmeeTab() ; 
						ElementTab tabCartePioche = ElementTab();
						tabCartePioche.ElementTab::remplirCartePiocheTab();
						ElementTab tabCarteEnjeu = ElementTab();
						ElementTab tabCarteDefausse = ElementTab();
						ElementTab tabPays = ElementTab();
						tabPays.ElementTab::remplirPaysTab();
						ElementTab tabContinent = ElementTab();
						tabContinent.ElementTab::remplirContinentTab();
	        			
	        			State currentState = state::State() ;
	        			currentState.setArmeeTab(tabArmee); 
						currentState.setCartePiocheTab(tabCartePioche);
						currentState.setCarteEnjeuTab(tabCarteEnjeu);
						currentState.setCarteDefausseTab(tabCarteDefausse);
						currentState.setPaysTab(tabPays);
						currentState.setContinentTab(tabContinent);
	        			
	        			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
	        			
	        			while (window.isOpen())
	        				{
								window.setVerticalSyncEnabled(true);
	        					window.setActive() ;	
	        					 
	        					
	        					Affichage::AfficheMap(currentState,window) ;
	        					
	        					sf::Event event;
	        					while (window.pollEvent(event))
	        					{
									switch (event.type)
									{
										case sf::Event::Closed :
											window.close();
											break ;
										case sf::Event::KeyPressed  :
											if(event.key.code == sf::Keyboard::Space)
											{
												std::cout<<"Touche espace pressée"<<std::endl ;
												std::cout <<"L'initialisation se fera içi"<<std::endl ; 
											}
									break;
										default:
									break;
									}
									
									if (event.type == sf::Event::MouseButtonPressed)
										{
											if(event.mouseButton.button ==sf::Mouse::Left)
												{
													Affichage::PaysClic(window, event); 
												}
										}
	        					
	        				}
	        	}  
    }
	    
	    }
 return 0;
}
