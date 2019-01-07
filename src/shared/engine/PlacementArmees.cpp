#include "PlacementArmees.h"

namespace engine {

PlacementArmees::PlacementArmees (std::string pays, int nbArmees) : pays(pays), nbArmees(nbArmees){
}

PlacementArmees::~PlacementArmees (){
}

IdCommande const PlacementArmees::getIdCommande (){
	return PLACER_ARMEES_c;
}

int PlacementArmees::getNbArmees (){
	return this->nbArmees;
}

void PlacementArmees::setNbArmees (int nbArmees){
	this->nbArmees = nbArmees;
}

bool PlacementArmees::verif(state::State state){
	int idJoueur = state.getIdJoueur();
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	if (state.getArmeesPlacer() < this->nbArmees){
		std::cout << "Vous ne pouvez placer que " << state.getArmeesPlacer() << " armees sur le territoires." << std::endl;
		this->nbArmees = state.getArmeesPlacer();
	}

	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getPays() == this->pays){ //on cherche le pays choisi dans la liste
			if(ptr_armee->getIdJoueur() == idJoueur){ //si l'ID du joueur correspond bien
				return true; //on place dans le territoire le nombre d'armée précédent + le nouveau nombre.
			}
			else{
				std::cout << "Problème : Ce pays ne vous appartient pas." << std::endl;
				return false;
			}
			break;
		}
	}
	return false;
}

void PlacementArmees::exec (state::State state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getPays() == this->pays){ //on cherche le pays choisi dans la liste
			ptr_armee->setNombre(ptr_armee->getNombre() + this->nbArmees); //on place dans le territoire le nombre d'armée précédent + le nouveau nombre.
			state.setArmeesPlacer(state.getArmeesPlacer() - this->nbArmees);
			break;
		}
	}
}

void PlacementArmees::undo (state::State state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getPays() == this->pays){ //on cherche le pays choisi dans la liste
			ptr_armee->setNombre(ptr_armee->getNombre() - this->nbArmees); //on place dans le territoire le nombre d'armée précédent + le nouveau nombre.
			state.setArmeesPlacer(state.getArmeesPlacer() + this->nbArmees);
			break;
		}
	}
}

}
