// Initialisation 2-3
#include "AttributionTerritoires.h"

namespace engine {

IdCommande const AttributionTerritoires::getIdCommande (){
	return ATTRIBUTERR ;
}

void AttributionTerritoires::distribution (state::State state, int nbJoueurs)
{
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

	for(size_t i=0; i<14; i++){
	  e = listeArmee[listeMelangee[i]].get();
	  e->setIdJoueur(1);
	}

	for(size_t i=14; i<28; i++){
	  e = listeArmee[listeMelangee[i]].get();
	  e->setIdJoueur(2);
	}

	for(size_t i=28; i<42; i++){
	  e = listeArmee[listeMelangee[i]].get();
	  e->setIdJoueur(3);
	}
}

//bool AttributionTerritoires::repartitionArmees (int idJoueur, state::State state){}

}
