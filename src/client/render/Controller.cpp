#include "render.h"
#include "engine.h"
#include "state.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>


using namespace std ;
using namespace render ;
using namespace state;
using namespace engine ;

Controller::Controller()
{
	pays_select = "not selected" ;
	pays_depart ="not selected" ;
	pays_arrivee = "not selected" ;
}

void  Controller::Handle (state::State& state, sf::RenderWindow& window)
{
	int stepID = state.getStepId() ;

	sf::Event event;
	while (window.pollEvent(event))
	{
		//std::cout << " new event , steId: " << stepID << std::endl;
		switch (stepID)
		{
			case DISTRIBUTION_s :
				HandleDistribution(state, event);
				break ;
			case REPARTITION_ARMEES_s :
				//std::cout << "case repartition_armees" << std::endl;
				HandlePlacerArmees(state, event, window);
				break ;
			case CHOIX_PAYS_ATTAQUANT_s :
				HandleChoixPaysAttaquant(state, event, window);
				break ;
			case CHOIX_PAYS_ATTAQUE_s :
				HandleChoixPaysAttaque(state, event, window);
				break ;
			case NB_DES_ATTAQUANT_s :
				HandleNbDesAttaquant(state, event, window);
				break ;
			case NB_DES_ATTAQUE_s :
				HandleNbDesAttaque(state, event, window);
				break ;
			case DEFAUSSER_s :
				HandleDefausser(state, event);
				break ;
			case PIOCHER_s :
				HandlePiocher(state, event) ;
				break ;
			case ECHANGE_s :
				HandleEchange(state, event);
				break ;
			case PLACER_NOUVELLES_ARMEES_s :
				std::cout << "case placer_nouvelle_armees" << std::endl;
				HandlePlacerArmees(state, event, window);
				break ;
			case DEPLACER_ARMEES_s:
				HandleDeplacerArmees(state, event, window) ;
				break ;
			default:
				break;
		}
	}
}

void  Controller::HandleUndo (state::State& state, sf::Event event )
{
	if(event.key.code == sf::Keyboard::U)
		{
			Undo* Commande = new Undo(state.getIdJoueur());
			std::cout << "pushing Passer" << std::endl;
			TourDeJeu::pushCommande(Commande) ;
		}
}

void  Controller::HandleDistribution (state::State& state, sf::Event event )
{
	if(event.key.code == sf::Keyboard::D)
		{
			Distribution* Commande = new Distribution(state.getIdJoueur());
			std::cout << "pushing Distribution" << std::endl;
			TourDeJeu::pushCommande(Commande) ;
		}
}

void  Controller::HandlePlacerArmees (state::State& state, sf::Event event,sf::RenderWindow& window )
{
	//std::string pays_select ;
	//std::cout<< pays_select << std::endl ;
	//std::cout<< armees_select<<std::endl ;
	if(pays_select == "not selected")
	{
		pays_select = Affichage::PaysClic(window, event);
		//std::cout << "new selection " << pays_select << std::endl;
	}
	else {
		//std::cout << "selecting nb" << std::endl;
		int armees_select =0 ;
		armees_select = Affichage::NombreClic(window, event) ;
		if(armees_select > 0) {
			std::cout<< "commande push : " << pays_select << std::endl ;
			std::cout<< "commande push : "<<armees_select<<std::endl ;
			TourDeJeu::pushCommande(new PlacementArmees(state.getIdJoueur(), pays_select, armees_select));
			pays_select = "not selected" ;
		}
	}
}

void  Controller::HandleChoixPaysAttaquant(state::State& state, sf::Event event, sf::RenderWindow& window)
{
			//std::string pays_select ;
			std::cout<< "ok HandleChoixPays"<<std::endl ;

			pays_select = Affichage::PaysClic(window, event) ;
			TourDeJeu::pushCommande(new ChoixPaysAttaquant(state.getIdJoueur(), pays_select)) ;
}

void  Controller::HandleChoixPaysAttaque(state::State& state, sf::Event event, sf::RenderWindow& window)
{
			//std::string pays_select ;
			std::cout<< "ok HandleChoixPays"<<std::endl ;

			pays_select = Affichage::PaysClic(window, event) ;
			TourDeJeu::pushCommande(new ChoixPaysAttaque(state.getIdJoueur(), pays_select)) ;
}

void Controller::HandleNbDesAttaquant(state::State& state, sf::Event event, sf::RenderWindow& window)
{
	int nombreDesSelect ;
	nombreDesSelect = Affichage::NombreClic(window, event) ;
	TourDeJeu::pushCommande(new  DesAttaquant(state.getIdJoueur(), nombreDesSelect)) ;
}

void Controller::HandleNbDesAttaque(state::State& state, sf::Event event, sf::RenderWindow& window)
{
	int nombreDesSelect ;
	nombreDesSelect = Affichage::NombreClic(window, event) ;
	TourDeJeu::pushCommande(new  DesAttaque(state.getIdJoueur(), nombreDesSelect)) ;
}

void Controller::HandleDefausser (state::State& state, sf::Event event )
{///////////////////////////////////////////////////////////////////////
}

void  Controller::HandlePiocher (state::State& state, sf::Event event )
{
	if(event.key.code == sf::Keyboard::P)
		{
			TourDeJeu::pushCommande(new Piocher(state.getIdJoueur())) ;
		}
}

void  Controller::HandleEchange (state::State& state, sf::Event event )
{//////////////////////////////////////////////////////////////////////
}

void Controller::HandleDeplacerArmees (state::State& state, sf::Event event, sf::RenderWindow& window )
{
	//std::string pays_depart;
	//std::string pays_arrivee;
	int armees_select ;
	if(pays_depart == "not selected")
	{
		pays_depart = Affichage::PaysClic(window, event);
		cout << "pays depart: " << pays_depart << endl;
	}
	if (pays_arrivee == "not selected")
	{
		pays_arrivee = Affichage::PaysClic(window, event);
	}
	else {
		armees_select = Affichage::NombreClic(window, event) ;
		TourDeJeu::pushCommande(new DeplacerArmees(state.getIdJoueur(), pays_depart, pays_arrivee, armees_select));
		pays_depart = "not selected";
		pays_arrivee = "not selected";
	}
}

void  Controller::HandleFin (state::State& state, sf::Event event )
{
	if(event.key.code == sf::Keyboard::E)
		{
			Passer* Commande = new Passer(state.getIdJoueur(), 1);
			std::cout << "pushing Fin" << std::endl;
			TourDeJeu::pushCommande(Commande) ;
		}
}

void  Controller::HandlePasser (state::State& state, sf::Event event )
{
	if(event.key.code == sf::Keyboard::N)
		{
			Passer* Commande = new Passer(state.getIdJoueur(), 0);
			std::cout << "pushing Passer" << std::endl;
			TourDeJeu::pushCommande(Commande) ;
		}
}
