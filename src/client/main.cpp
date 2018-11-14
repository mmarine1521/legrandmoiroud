#include "state.h"
#include "render.h"
#include "engine.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <thread>
#include <mutex>

using namespace state;
using namespace std ;
using namespace engine ;
using namespace render ;

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

	        else if (strcmp(argv[1],"engine")==0){
	            //Test Map
	        			std::cout << "Pour initialiser les pays : cliquez sur 'espace'" << std::endl ;
	        			std::cout << "Pour placer ses armées : cliquez sur 'P'"<< std::endl;
	        			std::cout << "JOUEUR 1 : Rouge" <<std::endl ;
	        			std::cout << "JOUEUR 2 : Vert" <<std::endl ; 
	        			std::cout << "JOUEUR 3 : Bleu" <<std::endl ; 

	        			
	        			ElementTab tabArmee = ElementTab() ; 
	        			tabArmee.ElementTab::setArmeeTab() ; 
	        			
	        			State EtatDepart = state::State() ;
	        			EtatDepart.setArmee(tabArmee); 
	        			 
	        			
	        			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);

	        			
	        			std::thread Attribution(AttributionTerritoires::repartitionArmees,1, EtatDepart);
	        			std::thread Clic(Affichage::PaysClic,window);
	        			Affichage::AfficheMap(EtatDepart,window);
	        			
	        			 
	        			
	        			 
						
	        			//window.display() ; 
							 
						cout<<"test"<<endl ; 	
						//Map.join() ; 
						Clic.join() ;
						Attribution.join() ; 
//							
//							
	   
//
//								//etape 2 de l'initialisation
//								ElementTab tabArmee = ElementTab();
//								tabArmee.ElementTab::remplirArmeeTab();
//						    ElementTab tabCartePioche = ElementTab();
//								tabCartePioche.ElementTab::remplirCartePiocheTab();
//						    ElementTab tabCarteEnjeu = ElementTab();
//						    ElementTab tabCarteDefausse = ElementTab();
//						    ElementTab tabPays = ElementTab();
//								tabPays.ElementTab::remplirPaysTab();
//						    ElementTab tabContinent = ElementTab();
//								tabContinent.ElementTab::remplirContinentTab();
//
//								State currentState = State() ;
//								currentState.setArmeeTab(tabArmee);
//						    currentState.setCartePiocheTab(tabCartePioche);
//						    currentState.setCarteEnjeuTab(tabCarteEnjeu);
//						    currentState.setCarteDefausseTab(tabCarteDefausse);
//						    currentState.setPaysTab(tabPays);
//						    currentState.setContinentTab(tabContinent);
//
//								TourDeJeu::jouer(0,1,currentState);
//
//
//	        			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
////	        			window.setActive() ;
////	        			window.setVerticalSyncEnabled(true);
//	        			//Affichage affiche = Affichage() ;
//	        			//while (window.isOpen())
////	        			{
//
//	        			Affichage::AfficheMap(currentState,window) ;
//
//	        			//window.display() ;
//
//						std:cout<<"test"<<std::endl ;
////
////
////							for(sf::Event e; window.pollEvent(e);){}
////		        			sf::Event event;
////
////
//
//
//
//
//
//							window.display() ;
//	        			}
//
//
//	        }
//
    }
	    }
 return 0;
}
