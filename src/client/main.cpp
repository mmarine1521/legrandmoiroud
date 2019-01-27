<<<<<<< HEAD
#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
=======
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

	//Controller controller0 = Controller(0); //pour deux joueurs reels
	Controller controller1 = Controller(1);
	RandomAI CtrlRandomAI1 = RandomAI(1);
	RandomAI CtrlRandomAI2 = RandomAI(2);
	HeuristicAI CtrlHeuristicAI1 = HeuristicAI(1);
	HeuristicAI CtrlHeuristicAI2 = HeuristicAI(2);
	DeepAI CtrlDeepAI1 = DeepAI(1);
	DeepAI CtrlDeepAI2 = DeepAI(2);

>>>>>>> 0901670dad08a1332be4f2f0de957a2af793b941
	if (argc > 1){ // vérifie s'il y a un argument
		string av(argv[1]);
		if (av == "hello") {   // vérification que l'argument est le bon
	  	cout << "Bonjour le monde !" << endl;
	  }
<<<<<<< HEAD
=======
		else if (av == "state"){
	  	//Test_Unitaire();
	 	}
		else if (av=="render"){
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setKeyRepeatEnabled(false);
			while (window.isOpen()){
				window.setVerticalSyncEnabled(true);
				window.setActive() ;
				window.clear();

				Affichage::AfficheMap(currentState,window);
				Affichage::AfficheChoixNbrArmees(currentState, window);
				Affichage::AfficheNombre(currentState, window);

				window.display();

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
			window.setKeyRepeatEnabled(false); //annule la répétition des clics
			while (window.isOpen()){
				window.setVerticalSyncEnabled(true);
				window.setActive();
				window.clear();

				Affichage::AfficheMap(currentState,window);
				Affichage::AfficheChoixNbrArmees(currentState, window);
				Affichage::AfficheNombre(currentState, window);

				//controller0.Handle(currentState, window); // deux joueurs reels
				controller1.Handle(currentState, window); //un joueur reel
				CtrlHeuristicAI2.aiRemplirCommandes(&currentState); // une heuristic IA
				TourDeJeu::run(currentState);
				window.display();

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
			window.setKeyRepeatEnabled(false);
			while (window.isOpen()){
				window.setVerticalSyncEnabled(true);
				window.setActive();
				window.clear();

				Affichage::AfficheMap(currentState,window);
				Affichage::AfficheChoixNbrArmees(currentState, window);
				Affichage::AfficheNombre(currentState, window);

				CtrlRandomAI1.aiRemplirCommandes(&currentState);
				CtrlRandomAI2.aiRemplirCommandes(&currentState);
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
		else if (av=="heuristic_ai") {
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setVerticalSyncEnabled(true);
			window.setActive();
			window.setKeyRepeatEnabled(false);

			while (window.isOpen()){
				window.clear();

				Affichage::AfficheMap(currentState,window);
				Affichage::AfficheChoixNbrArmees(currentState, window);
				Affichage::AfficheNombre(currentState, window);
				window.display();

				CtrlHeuristicAI1.aiRemplirCommandes(&currentState);
				CtrlHeuristicAI2.aiRemplirCommandes(&currentState);
				TourDeJeu::run(currentState);
				std::this_thread::sleep_for (std::chrono::seconds(1));

				sf::Event event;
				while (window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
			}
		}
		else if (av=="deep_ai"){
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

				CtrlDeepAI1.aiRemplirCommandes(&currentState) ;
				CtrlDeepAI2.aiRemplirCommandes(&currentState) ;
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));

				sf::Event event;
				while (window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
			}
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

				if (compteur < 20){
					CtrlHeuristicAI1.aiRemplirCommandes(&currentState) ;
					CtrlHeuristicAI2.aiRemplirCommandes(&currentState) ;
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
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
			}
		}
		else if (av=="thread"){
			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setVerticalSyncEnabled(true);
			window.setActive() ;
			window.setKeyRepeatEnabled(false) ;

			std::thread th_ai3(run_ai, std::ref(CtrlHeuristicAI1), &currentState, 3);
			std::thread th_ai4(run_ai, std::ref(CtrlHeuristicAI2), &currentState, 4);
			std::thread th_tdj(run_tourdejeu, &currentState);

			while (window.isOpen()){
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
		else if (av=="record"){
			//mis dans TourDeJeu
			int compteur = 0;
			while(compteur < 100){
				CtrlHeuristicAI1.aiRemplirCommandes(&currentState);
				CtrlHeuristicAI2.aiRemplirCommandes(&currentState);
				TourDeJeu::run(currentState);
				compteur ++;
			}
		}
		else if (av=="play"){
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

				TourDeJeu::pushCommandeFichier("replay.txt");
				TourDeJeu::run(currentState) ;
				std::this_thread::sleep_for (std::chrono::seconds(1));

				sf::Event event;
				while (window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
			}
		}
>>>>>>> 0901670dad08a1332be4f2f0de957a2af793b941
	}
}
