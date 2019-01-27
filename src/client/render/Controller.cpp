#include "Controller.h"

//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

using namespace std ;
using namespace render ;
using namespace state;
using namespace engine ;

Controller::Controller(int idJoueur){
	this->idJoueur = idJoueur;
	pays_select = "not selected" ;
	pays_depart ="not selected" ;
	pays_arrivee = "not selected" ;
}

void  Controller::Handle (state::State& state, sf::RenderWindow& window){
	int stepID = state.getStepId() ;

	sf::Event event;
	while (window.pollEvent(event)){
		switch (stepID){
			case DISTRIBUTION_s : HandleDistribution(state, event); break;
			case REPARTITION_ARMEES_s : HandlePlacerArmees(state, event, window); break;
			case CHOIX_PAYS_ATTAQUANT_s : HandleChoixPaysAttaquant(state, event, window); break;
			case CHOIX_PAYS_ATTAQUE_s : HandleChoixPaysAttaque(state, event, window); break;
			case NB_DES_ATTAQUANT_s : HandleNbDesAttaquant(state, event, window); break;
			case NB_DES_ATTAQUE_s : HandleNbDesAttaque(state, event, window); break;
			case DEFAUSSER_s : HandleDefausser(state, event); break;
			case PIOCHER_s : HandlePiocher(state, event); break;
			case ECHANGE_s : HandleEchange(state, event); break;
			case PLACER_NOUVELLES_ARMEES_s : HandlePlacerArmees(state, event, window); break;
			case DEPLACER_ARMEES_s: HandleDeplacerArmees(state, event, window) ; break;
			default: break;
		}
		if (event.type == sf::Event::Closed){
      window.close();
		}
	}
}

void  Controller::HandleUndo (state::State& state, sf::Event event ){
	if(event.key.code == sf::Keyboard::U){
		Undo* Commande;
		if (this->idJoueur != 0){
			Commande = new Undo(this->idJoueur);
		}
		else{
			Commande = new Undo(state.getIdJoueur());
		}
		std::cout << "pushing Passer" << std::endl;
		TourDeJeu::pushCommande(Commande) ;
	}
}

void  Controller::HandleDistribution (state::State& state, sf::Event event ){
	if(event.key.code == sf::Keyboard::D){
		Distribution* Commande;
		if (this->idJoueur != 0){
			Commande = new Distribution(this->idJoueur);
		}
		else{
			Commande = new Distribution(state.getIdJoueur());
		}
		std::cout << "pushing Distribution" << std::endl;
		TourDeJeu::pushCommande(Commande) ;
	}
}

void  Controller::HandlePlacerArmees (state::State& state, sf::Event event,sf::RenderWindow& window ){
	if(pays_select == "not selected"){
		pays_select = Affichage::PaysClic(window, event);
	}
	else {
		int armees_select =0 ;
		armees_select = Affichage::NombreClic(window, event) ;
		if(armees_select > 0) {
			PlacementArmees* Commande;

			if (this->idJoueur != 0){
				if (state.getArmeesRepartition(this->idJoueur) != 0){
					Commande = new PlacementArmees(this->idJoueur, pays_select, armees_select);
					std::cout << "Le joueur 1 a " << state.getArmeesRepartition(this->idJoueur) << " armées à placer. Il en place " << armees_select << " sur " << pays_select << std::endl;
				}
				else{
					Commande = new PlacementArmees(this->idJoueur, pays_select, 0);
				}
			}
			else{
				if (state.getArmeesRepartition(1) != 0){
					Commande = new PlacementArmees(1, pays_select, armees_select);
					std::cout << "Le joueur 1 a " << state.getArmeesRepartition(1) << " armées à placer. Il en place " << armees_select << " sur " << pays_select << std::endl;
				}
				else{
					Commande = new PlacementArmees(2, pays_select, armees_select);
					std::cout << "Le joueur 2 a " << state.getArmeesRepartition(2) << " armées à placer. Il en place " << armees_select << " sur " << pays_select << std::endl;
				}
			}
			TourDeJeu::pushCommande(Commande) ;
			pays_select = "not selected" ;
		}
	}
}

void  Controller::HandleChoixPaysAttaquant(state::State& state, sf::Event event, sf::RenderWindow& window){
	if (event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button ==sf::Mouse::Left){
			pays_select = Affichage::PaysClic(window, event) ;
			ChoixPaysAttaquant* Commande;
			if (this->idJoueur != 0){
				Commande = new ChoixPaysAttaquant(this->idJoueur, pays_select);
			}
			else{
				Commande = new ChoixPaysAttaquant(state.getIdJoueur(), pays_select);
			}
			TourDeJeu::pushCommande(Commande);
		}
	}
}

void  Controller::HandleChoixPaysAttaque(state::State& state, sf::Event event, sf::RenderWindow& window){
	if (event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button ==sf::Mouse::Left){
			pays_select = Affichage::PaysClic(window, event) ;
			ChoixPaysAttaque* Commande;
			if (this->idJoueur != 0){
				Commande = new ChoixPaysAttaque(this->idJoueur, pays_select);
			}
			else{
				Commande = new ChoixPaysAttaque(state.getIdJoueur(), pays_select);
			}
			TourDeJeu::pushCommande(Commande);
		}
	}
}

void Controller::HandleNbDesAttaquant(state::State& state, sf::Event event, sf::RenderWindow& window){
	if (event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button ==sf::Mouse::Right){
			int nombreDesSelect ;
			nombreDesSelect = Affichage::NombreClic(window, event) ;
			DesAttaquant* Commande;
			if (this->idJoueur != 0){
				Commande = new DesAttaquant(this->idJoueur, nombreDesSelect);
			}
			else{
				Commande = new DesAttaquant(state.getIdJoueur(), nombreDesSelect);
			}
			TourDeJeu::pushCommande(Commande);
		}
	}
}

void Controller::HandleNbDesAttaque(state::State& state, sf::Event event, sf::RenderWindow& window){
	if (event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button ==sf::Mouse::Right){
			int nombreDesSelect ;
			nombreDesSelect = Affichage::NombreClic(window, event) ;
			DesAttaque* Commande;
			if (this->idJoueur != 0){
				Commande = new DesAttaque(this->idJoueur, nombreDesSelect);
			}
			else{
				if (state.getIdJoueur() == 1){
					Commande = new DesAttaque(2, nombreDesSelect);
				}
				else{
					Commande = new DesAttaque(1, nombreDesSelect);
				}
			}
			TourDeJeu::pushCommande(Commande);
		}
	}
}

void Controller::HandleDefausser (state::State& state, sf::Event event ){
	///////////////////////////////////////////////////////////////////////
}

void  Controller::HandlePiocher (state::State& state, sf::Event event ){
	if(event.key.code == sf::Keyboard::P){
		Piocher* Commande;
		if (this->idJoueur != 0){
			Commande = new Piocher(this->idJoueur);
		}
		else{
			Commande = new Piocher(state.getIdJoueur());
		}
		TourDeJeu::pushCommande(Commande);
	}
}

void  Controller::HandleEchange (state::State& state, sf::Event event ){
	//////////////////////////////////////////////////////////////////////
}

void Controller::HandleDeplacerArmees (state::State& state, sf::Event event, sf::RenderWindow& window ){
	if (event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button ==sf::Mouse::Left){
			int armees_select ;
			if(pays_depart == "not selected"){
				pays_depart = Affichage::PaysClic(window, event);
				cout << "pays depart: " << pays_depart << endl;
			}
			if (pays_arrivee == "not selected"){
				pays_arrivee = Affichage::PaysClic(window, event);
			}
			else {
				armees_select = Affichage::NombreClic(window, event) ;
				DeplacerArmees* Commande;
				if (this->idJoueur != 0){
					Commande = new DeplacerArmees(this->idJoueur, pays_depart, pays_arrivee, armees_select);
				}
				else{
					Commande = new DeplacerArmees(state.getIdJoueur(), pays_depart, pays_arrivee, armees_select);
				}
				TourDeJeu::pushCommande(Commande);

				pays_depart = "not selected";
				pays_arrivee = "not selected";
			}
		}
	}
}

void  Controller::HandleFin (state::State& state, sf::Event event ){
	if(event.key.code == sf::Keyboard::E){
		std::cout << "pushing Fin" << std::endl;
		Passer* Commande;
		if (this->idJoueur != 0){
			Commande = new Passer(this->idJoueur, 1);
		}
		else{
			Commande = new Passer(state.getIdJoueur(), 1);
		}
		TourDeJeu::pushCommande(Commande);
	}
}

void  Controller::HandlePasser (state::State& state, sf::Event event ){
	if(event.key.code == sf::Keyboard::N){
		std::cout << "pushing Passer" << std::endl;
		Passer* Commande;
		if (this->idJoueur != 0){
			Commande = new Passer(this->idJoueur, 0);
		}
		else{
			Commande = new Passer(state.getIdJoueur(), 0);
		}
		TourDeJeu::pushCommande(Commande);
	}
}
