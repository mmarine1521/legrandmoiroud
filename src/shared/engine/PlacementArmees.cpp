//etape 10
#include "PlacementArmees.h"

namespace engine {


PlacementArmees::~PlacementArmees (){
}

IdCommande const PlacementArmees::getIdCommande (){
	return PLACEARMEES;
}

//verifier idJoueur
void PlacementArmees::placerNouvellesArmees (int idJoueur, int nouvellesArmees, state::State state){
	int armeesAPlacer = nouvellesArmees;
	std::string pays;
	int nombre;
	while(armeesAPlacer != 0){
		std::cout << "Il vous reste " << armeesAPlacer << " nouvelles armées à placer. Sur quel pays souhaitez-vous en placer ?" << std::endl;
		std::cin >> pays ; 
		//getline(std::cin, pays);
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
  		if(e->getPays()==pays){
        e->setNombre(e->getNombre() + nombre);
				break;
  		}
  	}
		armeesAPlacer -= nombre;
	}
}

void PlacementArmees::deplacerArmees (int idJoueur, state::State state){
	std::string reponse;
	std::cout << "Voulez-vous bouger des armées ? (o/n)" << std::endl;
	std::cin >> reponse;

	std::string paysDepart;
	std::string paysArrivee;
	int nombre;
	while (reponse == "o"){
		std::cout << "Depuis quel pays souhaitez-vous déplacer des armées ?" << std::endl;
		getline(std::cin, paysDepart);
		std::cout << "Vers quel pays souhaitez-vous déplacer des armées ?" << std::endl;
		getline(std::cin, paysArrivee);
		std::cout << "Combien d'armées souhaitez-vous déplacer ?" << std::endl;
		std::cin >> nombre;

		state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* eDepart = 0;
		state::Element* eArrivee = 0;
		bool estPossible = false;
    for(size_t i=0; i<listeArmee.size(); i++){
      eDepart = listeArmee[i].get();
  		if(eDepart->getPays()==paysDepart){
        if (eDepart->getNombre() > nombre){
					estPossible = ChoixPays::estFrontalier(paysDepart, paysArrivee, state);
				}
				else if (eDepart->getIdJoueur() != idJoueur){
					estPossible = false;
				}
  		}
			break;
  	}
		for(size_t i=0; i<listeArmee.size(); i++){
      eArrivee = listeArmee[i].get();
  		if(eArrivee->getPays()==paysArrivee){
				if (eArrivee->getIdJoueur() != idJoueur){
					estPossible = false;
				}
			}
			break;
		}

		if (estPossible){
			eDepart->setNombre(eDepart->getNombre() - nombre);
			eArrivee->setNombre(eArrivee->getNombre() + nombre);
		}
		else{
			std::cout << "Problème : le déplacement n'est pass possible." << std::endl;
		}
		std::cout << "Voulez-vous bouger des armées ? (o/n)" << std::endl;
		std::cin >> reponse;
	}
}

}
