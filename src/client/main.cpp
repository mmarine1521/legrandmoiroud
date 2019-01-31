#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

int main(int argc,char* argv[]){
	srand (time(0)); //initialisation une fois pour toute du srand
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
	currentState.setStepId(state::DISTRIBUTION_s);
	currentState.setArmeeTab(tabArmee);
	currentState.setCartePiocheTab(tabCartePioche);
	currentState.setCarteEnjeuTab(tabCarteEnjeu);
	currentState.setCarteDefausseTab(tabCarteDefausse);
	currentState.setPaysTab(tabPays);
	currentState.setContinentTab(tabContinent);
	currentState.setTourId(1);
	currentState.setIdJoueur(1);
	currentState.setNbCartes(3);
	currentState.initializeArmeesRepartition();

	Controller controller0 = Controller(0);
	RandomAI CtrlRandomAI1 = RandomAI(1);
	RandomAI CtrlRandomAI2 = RandomAI(2);

	if (argc > 1){ // vérifie s'il y a un argument
		string av(argv[1]);
		if (av == "hello") {   // vérification que l'argument est le bon
	  	cout << "Bonjour le monde !" << endl;
	  }
		else if (av == "state"){
	  	//Test_Unitaire();
	 	}
		else if (av=="render"){
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setKeyRepeatEnabled(false) ;
			while (window.isOpen()){
				window.setVerticalSyncEnabled(true);
				window.setActive() ;
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;

				window.display() ;

				sf::Event event;
				while (window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
			}
		}
		else if (av == "engine"){
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setKeyRepeatEnabled(false) ; //annule la répétition des clics
			while (window.isOpen()){
				window.setVerticalSyncEnabled(true);
				window.setActive() ;
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;

				controller0.Handle(currentState, window); // deux joueurs réels
				TourDeJeu::run(currentState);
				window.display() ;

				sf::Event event;
				while (window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
	    }
		}
		else if (av=="random_ai"){
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setKeyRepeatEnabled(false) ;
			while (window.isOpen()){
				window.setVerticalSyncEnabled(true);
				window.setActive() ;
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;

				CtrlRandomAI1.aiRemplirCommandes(&currentState) ;
				CtrlRandomAI2.aiRemplirCommandes(&currentState) ;
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));
				window.display() ;

				sf::Event event;
				while (window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
			}
		}
	}
}
