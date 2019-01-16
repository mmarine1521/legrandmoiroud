#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <chrono>
#include <time.h>
#include <memory>
#include <fstream>
#include <thread>
#include <mutex>

using namespace state;
using namespace std;
using namespace engine;
using namespace render;
using namespace ai;

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

void run_ai(ai::HeuristicAI& ctrl, state::State* s, int n){
	while(1) {
		std::this_thread::sleep_for (std::chrono::seconds(1));
		std::cout << "run_ai " << n << " !!!" << std::endl;
		ctrl.aiRemplirCommandes(s) ;
	}
}

void run_tourdejeu(state::State* s) {
	while(1) {
		TourDeJeu::run(*s) ;
		std::this_thread::sleep_for (std::chrono::seconds(1));
	}
}

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

	Controller controller = Controller() ;
	RandomAI CtrlAI = RandomAI(1) ;
	RandomAI CtrlAI2 = RandomAI(2) ;
	HeuristicAI CtrlAI3 = HeuristicAI(1) ;
	HeuristicAI CtrlAI4 = HeuristicAI(2) ;

	if (argc > 1){ // vérifie s'il y a un argument
		string av(argv[1]);
		if (av == "hello") {   // vérification que l'argument est le bon
	  	cout << "Bonjour le monde !" << endl;
	  }
		else if (av == "state")
		{
	  	//Test_Unitaire();
	 	}
		else if (av == "engine")
		{
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setKeyRepeatEnabled(false) ; //annule la répétition des clics
			while (window.isOpen()){
				window.setVerticalSyncEnabled(true);
				window.setActive() ;
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;

				controller.Handle(currentState, window) ;
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));
				window.display() ;
				/*
				sf::Event event;
				while (window.pollEvent(event)){
					Affichage::PaysClic(window, event);
	      }
				*/
	    }
		}
		else if (av=="render")
		{
			//rendus aleatoires
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

				CtrlAI.aiRemplirCommandes(&currentState) ;
				CtrlAI2.aiRemplirCommandes(&currentState) ;
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));
				window.display() ;

				sf::Event event;
				while (window.pollEvent(event)){
				}
			}
		}
		else if (av=="heuristic_ai") {
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setVerticalSyncEnabled(true);
			window.setActive() ;
			window.setKeyRepeatEnabled(false) ;

			while (window.isOpen()){
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;
				window.display() ;

				CtrlAI3.aiRemplirCommandes(&currentState) ;
				CtrlAI4.aiRemplirCommandes(&currentState) ;
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));

				sf::Event event;
				while (window.pollEvent(event)){
				}
			}
		}
		else if (av=="deep_ai"){

		}
		else if (av=="rollback"){
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setVerticalSyncEnabled(true);
			window.setActive() ;
			window.setKeyRepeatEnabled(false) ;

			int compteur = 0;
			while (window.isOpen()){
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;
				window.display() ;

				if (compteur < 60){
					CtrlAI3.aiRemplirCommandes(&currentState) ;
					CtrlAI4.aiRemplirCommandes(&currentState) ;
				}
				else{
					while(TourDeJeu::getSizeUndos() != 0){
						TourDeJeu::pushCommande(new Undo(currentState.getIdJoueur()));
					}
				}
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));
				compteur ++;

				sf::Event event;
				while (window.pollEvent(event)){
				}
			}
		}
		else if (av=="thread"){
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setVerticalSyncEnabled(true);
			window.setActive() ;
			window.setKeyRepeatEnabled(false) ;

			std::thread th_ai3(run_ai, std::ref(CtrlAI3), &currentState, 3);
			std::thread th_ai4(run_ai, std::ref(CtrlAI4), &currentState, 4);
			std::thread th_tdj(run_tourdejeu, &currentState);

			while (window.isOpen()){
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;
				window.display() ;

				//std::cout << "state : " << currentState.getStepId() << std::endl;
				//std::this_thread::sleep_for (std::chrono::seconds(1));
				//window.display() ;
				sf::Event event;
				while (window.pollEvent(event)){
				}
			}
		}
		else if (av=="record"){//server

		}
		else if (av=="play"){/*
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setVerticalSyncEnabled(true);
			window.setActive() ;
			window.setKeyRepeatEnabled(false) ;

			while (window.isOpen()){
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;
				window.display() ;

				std::string line;
				ifstream myfile ("replay.txt");
  			if (myfile.is_open()){
    			while (getline (myfile,line)){
						engine::Commande* com = (engine::Commande*) line;
	      		engine::TourDeJeu::pushCommande(com);
    			}
    			myfile.close();
  			}
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));

				sf::Event event;
				while (window.pollEvent(event)){
				}
			}*/
		}
		else if (av=="listen"){//server

		}
		else if (av=="network"){

		}
	}
}
