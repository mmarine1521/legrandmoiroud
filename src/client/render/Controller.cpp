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

void  Controller::HandlePasser (sf::Event event )
{
	if(event.key.code == sf::Keyboard::N)
		{
			Passer* Commande = new Passer(1, 0);
			std::cout << "pushing Passer" << std::endl;
			TourDeJeu::pushCommande(Commande) ;
		}
}
void  Controller::HandleFin (sf::Event event )
{
	if(event.key.code == sf::Keyboard::N)
		{
			Passer* Commande = new Passer(1, 1);
			std::cout << "pushing Fin" << std::endl;
			TourDeJeu::pushCommande(Commande) ;
		}
}
void  Controller::HandleDistribution (sf::Event event )
{
	if(event.key.code == sf::Keyboard::D)
		{
			Distribution* Commande = new Distribution(1);
			std::cout << "pushing Distribution" << std::endl;
			TourDeJeu::pushCommande(Commande) ;
		}
}
void  Controller::HandleChoixPaysAttaquant(sf::Event event, sf::RenderWindow& window)
{
			//std::string pays_select ;
			std::cout<< "ok HandleChoixPays"<<std::endl ;

			pays_select = Affichage::PaysClic(window, event) ;
			TourDeJeu::pushCommande(new ChoixPaysAttaquant(1, pays_select)) ;
}

void  Controller::HandleChoixPaysAttaque(sf::Event event, sf::RenderWindow& window)
{
			//std::string pays_select ;
			std::cout<< "ok HandleChoixPays"<<std::endl ;

			pays_select = Affichage::PaysClic(window, event) ;
			TourDeJeu::pushCommande(new ChoixPaysAttaque(1, pays_select)) ;
}

void Controller::HandleNbDesAttaquant(sf::Event event, sf::RenderWindow& window)
{
	int nombreDesSelect ;
	nombreDesSelect = Affichage::NombreClic(window, event) ;
	TourDeJeu::pushCommande(new  DesAttaquant(1, nombreDesSelect)) ;

}
void Controller::HandleNbDesAttaque(sf::Event event, sf::RenderWindow& window)
{
	int nombreDesSelect ;
	nombreDesSelect = Affichage::NombreClic(window, event) ;
	TourDeJeu::pushCommande(new  DesAttaque(1, nombreDesSelect)) ;

}

void Controller::HandleDefausser (sf::Event event )
{
}
void  Controller::HandlePiocher (sf::Event event )
{
	if(event.key.code == sf::Keyboard::P)
		{
			TourDeJeu::pushCommande(new Piocher(1)) ;
		}
}
void  Controller::HandleEchange (sf::Event event )
{
}
void  Controller::HandlePlacerArmees (sf::Event event,sf::RenderWindow& window )
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
			TourDeJeu::pushCommande(new PlacementArmees(1, pays_select, armees_select));
			pays_select = "not selected" ;
		}
	}
}
void Controller::HandleDeplacerArmees (sf::Event event, sf::RenderWindow& window )
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
		TourDeJeu::pushCommande(new DeplacerArmees(1, pays_depart, pays_arrivee, armees_select));
		pays_depart = "not selected";
		pays_arrivee = "not selected";
	}
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
					HandleDistribution(event);
					break ;
				case REPARTITION_ARMEES_s :
					//std::cout << "case repartition_armees" << std::endl;
					HandlePlacerArmees(event, window);
					break ;
				case CHOIX_PAYS_ATTAQUANT_s :
					HandleChoixPaysAttaquant(event, window);
					break ;
				case CHOIX_PAYS_ATTAQUE_s :
					HandleChoixPaysAttaque(event, window);
					break ;
				case NB_DES_ATTAQUANT_s :
					HandleNbDesAttaquant(event, window);
					break ;
				case NB_DES_ATTAQUE_s :
					HandleNbDesAttaque(event, window);
					break ;
				case DEFAUSSER_s :
					HandleDefausser(event);
					break ;
				case PIOCHER_s :
					HandlePiocher(event) ;
					break ;
				case ECHANGE_s :
					HandleEchange(event);
					break ;
				case PLACER_NOUVELLES_ARMEES_s :
					std::cout << "case placer_nouvelle_armees" << std::endl;
					HandlePlacerArmees(event, window);
					break ;
				case DEPLACER_ARMEES_s:
					HandleDeplacerArmees(event, window) ;
					break ;
				default:
					break;
			}



	     }
}
