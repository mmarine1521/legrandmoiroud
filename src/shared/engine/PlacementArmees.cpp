#include "PlacementArmees.h"

#include <fstream>

namespace engine {

PlacementArmees::PlacementArmees (int idJoueurCommande, std::string pays, int nbArmees) : Commande(idJoueurCommande), pays(pays), nbArmees(nbArmees){
}

PlacementArmees::~PlacementArmees (){
}

IdCommande const PlacementArmees::getIdCommande (){
	return PLACER_ARMEES_c;
}

void PlacementArmees::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::out);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"PlacementArmees\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << "," << std::endl;
    fichier << "\"pays\" : " << this->pays << "," << std::endl;
		fichier << "\"nbArmees\" : " << this->nbArmees << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
}

std::string PlacementArmees::getPays(){
	return this->pays;
}

void PlacementArmees::setPays(std::string pays){
	this->pays = pays;
}

int PlacementArmees::getNbArmees (){
	return this->nbArmees;
}

bool PlacementArmees::verif(state::State& state){
	int idJoueur = this->idJoueurCommande;
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	if (state.getArmeesRepartition(idJoueur) < this->nbArmees){
		std::cout << "Vous ne pouvez placer que " << state.getArmeesRepartition(idJoueur) << " armees sur le territoire. (< " << this->nbArmees << ")" << std::endl;
		this->nbArmees = state.getArmeesRepartition(idJoueur);
	}

	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getPays() == this->pays){ //on cherche le pays choisi dans la liste
			if(ptr_armee->getIdJoueur() == idJoueur){ //si l'ID du joueur correspond bien
				return true; //on place dans le territoire le nombre d'armée précédent + le nouveau nombre.
			}
			else{
				std::cout << "Problème : Ce pays ne vous appartient pas. " << ptr_armee->getIdJoueur() << " != " << idJoueur<< std::endl;
				return false;
			}
			break;
		}
	}
	return false;
}

void PlacementArmees::exec (state::State& state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getPays() == this->pays){ //on cherche le pays choisi dans la liste
			ptr_armee->setNombre(ptr_armee->getNombre() + this->nbArmees); //on place dans le territoire le nombre d'armée précédent + le nouveau nombre.
			state.setArmeesRepartition(this->idJoueurCommande, state.getArmeesRepartition(this->idJoueurCommande) - this->nbArmees);
			break;
		}
	}
}

void PlacementArmees::undo (state::State& state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getPays() == this->pays){ //on cherche le pays choisi dans la liste
			ptr_armee->setNombre(ptr_armee->getNombre() - this->nbArmees); //on place dans le territoire le nombre d'armée précédent + le nouveau nombre.
			state.setArmeesRepartition(this->idJoueurCommande, state.getArmeesRepartition(this->idJoueurCommande) + this->nbArmees);
			break;
		}
	}
}

}
