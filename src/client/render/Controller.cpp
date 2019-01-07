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


void  HandleDistribution (sf::Event event )
{
	if(event.key.code == sf::Keyboard::D)
		{
			Distribution* Commande = new Distribution();
			
			TourDeJeu::pushCommande(Commande) ; 
		}
}
void  HandleChoixPays(sf::Event event, sf::RenderWindow& window)
{
			std::string pays_select ; 
			pays_select = Affichage::PaysClic(window, event) ; 
			TourDeJeu::pushCommande(new ChoixPays(pays_select)) ; 
}

void HandleNbDes(sf::Event event, sf::RenderWindow& window)
{
	int nombreDesSelect ; 
	nombreDesSelect = Affichage::NombreClic(window, event) ;
	TourDeJeu::pushCommande(new  Des(nombreDesSelect)) ; 
	
}

void HandleDefausser (sf::Event event )
{
}
void  HandlePiocher (sf::Event event )
{
	if(event.key.code == sf::Keyboard::P)
		{
			TourDeJeu::pushCommande(new Piocher()) ; 
		}
}
void  HandleEchange (sf::Event event )
{
}
void  HandlePlacerArmees (sf::Event event,sf::RenderWindow& window )
{
	std::string pays_select ; 
	pays_select = Affichage::PaysClic(window, event); 
	int armees_select; 
	armees_select = Affichage::NombreClic(window, event) ;
	TourDeJeu::pushCommande(new PlacementArmees(pays_select, armees_select)); 
}
void HandleDeplacerArmees (sf::Event event, sf::RenderWindow& window )
{
	std::string pays_depart ; 
	std::string pays_arrivee; 
	pays_depart = Affichage::PaysClic(window, event);
	pays_arrivee = Affichage::PaysClic(window, event); 
	int armees_select ; 
	armees_select = Affichage::NombreClic(window, event) ;
	TourDeJeu::pushCommande(new DeplacerArmees(pays_depart, pays_arrivee, armees_select)); 
}

void  Handle (state::State& state, sf::RenderWindow& window)
{
	//sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);//initialisation fenêtre

	        			/*while (window.isOpen())
	        				{
								window.setVerticalSyncEnabled(true);
	        					window.setActive() ;*/

								/*State currentState = state::State() ;
								currentState.setArmeeTab(tabArmee);
								currentState.setCartePiocheTab(tabCartePioche);
								currentState.setCarteEnjeuTab(tabCarteEnjeu);
								currentState.setCarteDefausseTab(tabCarteDefausse);
								currentState.setPaysTab(tabPays);
								currentState.setContinentTab(tabContinent);*/

	        					//Affichage::AfficheMap(currentState,window) ;
	        					//Affichage::AfficheChoixNbrArmees(currentState, window) ;
	        					//Affichage::AfficheNombre(currentState, window) ;
								
	        					int stepID = state.getStepId() ; 
	        					
	        					sf::Event event;
	        					while (window.pollEvent(event))
	        					{
									switch (stepID)
									{
										case DISTRIBUTION_s :
											HandleDistribution(event);
											break ;
										case REPARTITION_ARMEES_s :
											HandlePlacerArmees(event, window);
											break ;
										case CHOIX_PAYS_ATTAQUANT_s :
											HandleChoixPays(event, window);
											break ;
										case CHOIX_PAYS_ATTAQUE_s :
											HandleChoixPays(event, window);
											break ;										 
										case NB_DES_ATTAQUANT_s :
											HandleNbDes(event, window);
											break ;
										case NB_DES_ATTAQUE_s :
											HandleNbDes(event, window);
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
											HandlePlacerArmees(event, window); 
											break ;
										case DEPLACER_ARMEES_s:
											HandleDeplacerArmees(event, window) ; 
											break ; 
										default:
									break;
									}

									

	        				}
	        					window.display() ;
}


