//etape 10
#include "PlacementArmees.h"
#include "state.h"
#include "render.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace state ;
using namespace render ; 
namespace engine {


PlacementArmees::~PlacementArmees (){
}

IdCommande const PlacementArmees::getIdCommande (){
	return PLACEARMEES;
}

//verifier idJoueur
void PlacementArmees::placerNouvellesArmees (int idJoueur, int nouvellesArmees, state::State state, sf::RenderWindow& window){
	int armeesAPlacer = nouvellesArmees;
	std::string pays;
	int nombre = 0;
	while(armeesAPlacer != 0){
		std::string tmp;
		
		std::string paysClic = "";
		//Affichage::PaysClic()
		std::cout << "test : pays_clic"<< paysClic << std::endl ; 
		
		getline(std::cin,tmp);
		std::cout << "Il vous reste " << armeesAPlacer << " nouvelles armées à placer. Sur quel pays souhaitez-vous en placer ?" << std::endl;
		//pays = Affichage::PaysClic() ; 
		//std::cout << "test pays clic" << pays << std::endl ; 
		getline(std::cin, pays);
		std::cout << "Combien d'armées souhaitez-vous placer sur ce territoire ?" << std::endl;
		std::cin >> nombre;
		if (armeesAPlacer < nombre){
			nombre = armeesAPlacer;
		}
		state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* e = 0;
    for(size_t i=0; i<listeArmee.size(); i++){
      e = listeArmee[i].get();
  		if(e->getPays()==pays){ //on cherche le pays choisi dans la liste
				if(e->getIdJoueur() == idJoueur){ //si l'ID du joueur correspond bien 
					e->setNombre(e->getNombre() + nombre); //on place dans le territoire le nombre d'armée précédent + le nouveau nombre. 
					armeesAPlacer -= nombre; //on décrémente le compteur du nombre d'armée
					break;
				}
				else{
					std::cout << "Problème : Ce pays ne vous appartient pas." << std::endl;
				}
  		}
  	}
	}
}

void PlacementArmees::deplacerArmees (int idJoueur, state::State state){
	std::string reponse;
	std::cout << "Voulez-vous déplacer des armées ? (o/n)" << std::endl;
	std::cin >> reponse;

	bool estPossible = false;
	std::string paysDepart;
	std::string paysArrivee;
	int nombre;

	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* eDepart = 0;
	state::Element* eArrivee = 0;

	while (reponse == "o"){
		std::string tmp;
		getline(std::cin,tmp);
		std::cout << "Depuis quel pays souhaitez-vous déplacer des armées ?" << std::endl;
		getline(std::cin, paysDepart);
		std::cout << "Vers quel pays souhaitez-vous déplacer des armées ?" << std::endl;
		getline(std::cin, paysArrivee);
		std::cout << "Combien d'armées souhaitez-vous déplacer ?" << std::endl;
		std::cin >> nombre;

    for(size_t i=0; i<listeArmee.size(); i++){
      eDepart = listeArmee[i].get();
  		if(eDepart->getPays() == paysDepart){
				if(eDepart->getIdJoueur() == idJoueur){
					if (eDepart->getNombre() > nombre){
						estPossible = ChoixPays::estFrontalier(paysDepart, paysArrivee, state);
						if (estPossible == false){
							std::cout << "Problème : Les deux pays ne sont pas frontaliers." << std::endl;
						}
					}
					else{
						std::cout << "Problème : Le pays de départ ne possède que " << eDepart->getNombre() << " armées. On ne peut dont pas en déplacer " << nombre << "." << std::endl;
					}
				}
				else{
					std::cout << "Problème : Le pays de départ ne vous appartient pas." << std::endl;
				}
  		}
			break;
  	}
		for(size_t i=0; i<listeArmee.size(); i++){
      eArrivee = listeArmee[i].get();
  		if(eArrivee->getPays() == paysArrivee){
				if (eArrivee->getIdJoueur() != idJoueur){
					estPossible = false;
					std::cout << "Problème : Le pays d'arrivée ne vous appartient pas." << std::endl;
				}
			}
			break;
		}

		if (estPossible == true){
			eDepart->setNombre(eDepart->getNombre() - nombre);
			eArrivee->setNombre(eArrivee->getNombre() + nombre);
		}
		else{
			std::cout << "Problème : Le déplacement n'est pas possible." << std::endl;
		}
		std::cout << "Voulez-vous déplacer des armées ? (o/n)" << std::endl;
		std::cin >> reponse;
	}
}

}
