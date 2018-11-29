// Initialisation 2-3
#include "AttributionTerritoires.h"

namespace engine {

IdCommande const AttributionTerritoires::getIdCommande (){
	return ATTRIBUTERR ;
}

void AttributionTerritoires::distribution (state::State state, int nbJoueurs){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* e = 0;

	std::vector<int> listeEntiers;
	for (int i=0; i<42; i++){
	  listeEntiers.push_back(i);
	}

	srand (time(NULL));
	int nbAleatoire;
	std::vector<int> listeMelangee;
	for (int i = 42; i > 0; i--){
	  nbAleatoire = rand() % i;
	  listeMelangee.push_back(listeEntiers[nbAleatoire]);
	  listeEntiers.erase(listeEntiers.begin() + nbAleatoire);
	}

	std::cout << "Le joueur 1 possède :" << std::endl;
	for(size_t i=0; i<14; i++){
	  e = listeArmee[listeMelangee[i]].get();
	  e->setIdJoueur(1);
		std::cout << e->getPays() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Le joueur 2 possède :" << std::endl;
	for(size_t i=14; i<28; i++){
	  e = listeArmee[listeMelangee[i]].get();
	  e->setIdJoueur(2);
		std::cout << e->getPays() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Le joueur 3 possède :" << std::endl;
	for(size_t i=28; i<42; i++){
	  e = listeArmee[listeMelangee[i]].get();
	  e->setIdJoueur(3);
		std::cout << e->getPays() << std::endl;
	}
	std::cout << std::endl;
}

bool AttributionTerritoires::repartitionArmees (int idJoueur, state::State state, sf::RenderWindow& window, sf::Event event){
	bool repartition = true;
	PlacementArmees::placerNouvellesArmees(idJoueur, 42, state, window, event);
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* e = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
		e = listeArmee[i].get();
		if(e->getIdJoueur()==idJoueur){
			if (e->getNombre() <= 0){
				repartition = false; //test si nombre d'armée inférieur ou égale à 0 = problèmes dans le placement des pions.
			}
			break;
		}
	}
	if (!repartition){
		std::cout << "Problème : Au moins un de vos territoires ne possède pas d'armée." << std::endl;
	}
	return repartition;
}

void AttributionTerritoires::undoRepartitionArmees (int idJoueur, state::State state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* e = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
		e = listeArmee[i].get();
		if(e->getIdJoueur()==idJoueur){
			e->setNombre(0);
		}
	}
}

}
