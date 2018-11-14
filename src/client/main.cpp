#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <thread>
#include <mutex>

using namespace state;
using namespace engine;
using namespace render;
using namespace ai;

int main(int argc,char* argv[]){
	if (argc>1){                 // vérifie s'il y a un argument

		if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
	  	std::cout << "Bonjour le monde!" << std::endl;
	  }

	  else if (strcmp(argv[1],"state")==0){
	  	//Test_Unitaire()
		}

		else if (strcmp(argv[1],"engine")==0){
	  	std::cout << "Pour initialiser les pays : cliquez sur 'espace'" << std::endl ;
	    std::cout << "Pour placer ses armées : cliquez sur 'P'"<< std::endl;
	    std::cout << "JOUEUR 1 : Rouge" <<std::endl ;
	    std::cout << "JOUEUR 2 : Vert" <<std::endl ;
	    std::cout << "JOUEUR 3 : Bleu" <<std::endl ;

			//etape 2 de l'initialisation
			ElementTab tabArmee = ElementTab();
			tabArmee.remplirArmeeTab();
			ElementTab tabCartePioche = ElementTab();
			tabCartePioche.remplirCartePiocheTab();
			ElementTab tabCarteEnjeu = ElementTab();
			ElementTab tabCarteDefausse = ElementTab();
			ElementTab tabPays = ElementTab();
			tabPays.remplirPaysTab();
			ElementTab tabContinent = ElementTab();
			tabContinent.remplirContinentTab();

			State currentState = State() ;
			currentState.setArmeeTab(tabArmee);
			currentState.setCartePiocheTab(tabCartePioche);
			currentState.setCarteEnjeuTab(tabCarteEnjeu);
			currentState.setCarteDefausseTab(tabCarteDefausse);
			currentState.setPaysTab(tabPays);
			currentState.setContinentTab(tabContinent);

			//TourDeJeu::jouer(0,1,currentState);
			RandomAI intelligence = RandomAI();
			intelligence.aiJouer(0,1,currentState);

	    Affichage* map = new Affichage() ;
		}
	 }
	 return 0;
}
