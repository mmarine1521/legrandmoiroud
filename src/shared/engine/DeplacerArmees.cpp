#include "DeplacerArmees.h"

namespace engine {

DeplacerArmees::DeplacerArmees (int idJoueurCommande, std::string paysDepart, std::string paysArrivee, int nbArmees) : Commande(idJoueurCommande), paysDepart(paysDepart), paysArrivee(paysArrivee), nbArmees(nbArmees){
}

DeplacerArmees::~DeplacerArmees (){
}

IdCommande const DeplacerArmees::getIdCommande (){
	return DEPLACER_ARMEES_c;
}

bool DeplacerArmees::verif (state::State& state){
	int idJoueur = this->idJoueurCommande;
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_depart = 0;
	state::Element* ptr_arrivee = 0;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_depart = listeArmee[i].get();
  	if(ptr_depart->getPays() == this->paysDepart){
			if(ptr_depart->getIdJoueur() == idJoueur){
				if (ptr_depart->getNombre() <= this->nbArmees){
					std::cout << "Problème : Le pays de départ ne possède que " << ptr_depart->getNombre() << " armées. On ne peut dont pas en déplacer " << this->nbArmees << "." << std::endl;
					return false;
				}
			}
			else{
				std::cout << "Problème : Le pays de départ ne vous appartient pas." << std::endl;
				return false;
			}
			break;
  	}
  }

	for(size_t i=0; i<listeArmee.size(); i++){
    ptr_arrivee = listeArmee[i].get();
  	if(ptr_arrivee->getPays() == this->paysArrivee){
			if (ptr_arrivee->getIdJoueur() != idJoueur){
				std::cout << "Problème : Le pays d'arrivée ne vous appartient pas." << std::endl;
				return false;
			}
			break;
		}
	}

	bool ok = ChoixPaysAttaque::estFrontalier(this->paysDepart, this->paysArrivee, state);
	if (!ok){
		std::cout << "Problème : Les deux pays ne sont pas frontaliers." << std::endl;
	}
	return ok;
}

void DeplacerArmees::exec (state::State& state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_depart = 0;
	state::Element* ptr_arrivee = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
    ptr_depart = listeArmee[i].get();
  	if(ptr_depart->getPays() == this->paysDepart){
			ptr_depart->setNombre(ptr_arrivee->getNombre() - nbArmees);
			break;
		}
	}

	for(size_t i=0; i<listeArmee.size(); i++){
    ptr_arrivee = listeArmee[i].get();
  	if(ptr_arrivee->getPays() == this->paysArrivee){
			ptr_arrivee->setNombre(ptr_arrivee->getNombre() + nbArmees);
			break;
		}
	}
}

void DeplacerArmees::undo (state::State& state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_depart = 0;
	state::Element* ptr_arrivee = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
    ptr_depart = listeArmee[i].get();
  	if(ptr_depart->getPays() == this->paysDepart){
			ptr_depart->setNombre(ptr_arrivee->getNombre() + nbArmees);
			break;
		}
	}

	for(size_t i=0; i<listeArmee.size(); i++){
    ptr_arrivee = listeArmee[i].get();
  	if(ptr_arrivee->getPays() == this->paysArrivee){
			ptr_arrivee->setNombre(ptr_arrivee->getNombre() - nbArmees);
			break;
		}
	}
}

}
