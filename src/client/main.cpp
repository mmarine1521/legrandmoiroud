#include "state.h"
#include "render.h"
#include "engine.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace state;
using namespace std ;
using namespace engine ;
using namespace render ;

void testSFML() 
	{
		std::cout << "Pour initialiser les pays : cliquez sur 'espace'" << std::endl ; 
		std::cout << "Pour placer ses armées : cliquez sur 'P'"<< std::endl; 
		std::cout << "JOUEUR 1 : Rouge" <<std::endl ;
		std::cout << "JOUEUR 2 : Vert" <<std::endl ; 
		std::cout << "JOUEUR 3 : Bleu" <<std::endl ; 


		sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
		//Affichage affiche = Affichage() ;
		Affichage::AfficheMap(window) ; 
		sf::Event event;
		
		State EtatDepart = state::State() ; 
		


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
		        				AttributionTerritoires::distribution (EtatDepart, 3);
		        				Affichage::AfficheArmees(EtatDepart, window) ; 
		        				std::cout <<"Initialisation Terminée"<<std::endl ; 
		        			}
		        			if(event.key.code == sf::Keyboard::P)
							{
								std::cout<<"Placement des armées joueur 1" << std::endl ; 
								//AttributionTerritoires::repartitionArmees(1, EtatDepart); 
								//AttributionTerritoires::repartitionArmees(2, EtatDepart);
								//AttributionTerritoires::repartitionArmees(3, EtatDepart);
								std::cout <<"Placement Terminée"<<std::endl ; 
								
							}
	                break;
	              default:
	                break;
		        	}
		        }
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
	        	testSFML();
	            
	        }

	    }
 return 0;
}
