#include "ChoixPaysAttaquant.h"

#include <iostream>

namespace engine {

ChoixPaysAttaquant::ChoixPaysAttaquant (int idJoueur, std::string pays) : ChoixPays(idJoueur, pays){
}

ChoixPaysAttaquant::~ChoixPaysAttaquant (){
}

IdCommande const ChoixPaysAttaquant::getIdCommande (){
  return CHOIX_PAYS_ATTAQUANT_c;
}

bool ChoixPaysAttaquant::verif (state::State& state){
  std::string paysAttaquant = state.getPaysAttaquant();
  int idJoueur = state.getIdJoueur();
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if(ptr_armee->getPays() == paysAttaquant){
      break; // on a la bonne Armee
    }
  }

  //On vérifie que le pays possède suffisamment d'armées pour attaquer.
  if(ptr_armee->getNombre() < 2){
    std::cout << "Problème : votre pays ne possède pas suffisamment d'armées pour attaquer." << std::endl;
    return false;
  }

  //On verifie que le pays appartient bien au joueur.
  if(ptr_armee->getIdJoueur() == idJoueur){
    state::ElementTab& tabPays = state.getPaysTab();
    std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
    state::Element* ptr_pays = 0;
    for(size_t i=0; i<listePays.size(); i++){
      ptr_pays = listePays[i].get();
      if(ptr_pays->getPays() == paysAttaquant){
        break; // on a le bon Pays
      }
    }

    std::vector<std::string> listePaysFontaliers = ptr_pays->getPaysFrontaliers();
    state::Element* ptr_frontalier = 0;

    //On vérifie dans les pays frontaliers qu'il n'y ait pas que des pays du joueur qui attaque.
    for(size_t i=0; i<listePaysFontaliers.size(); i++){
      std::string paysFrontalier = listePaysFontaliers[i];
      for(size_t j=0; j<listeArmee.size(); j++){
        ptr_frontalier = listeArmee[j].get();
        if(ptr_frontalier->getPays() == paysFrontalier){
        	if(ptr_frontalier->getIdJoueur() != idJoueur){
					  return true;
				  }
        	break;
        }
      }
    }
    std::cout << "Problème : Ce pays est entouré de pays vous appartenant et ne peut donc pas attaquer." << std::endl;
    return false;
  }
  else {
    std::cout << "Problème : Ce pays ne vous appartient pas." << std::endl;
    return false;
  }
}

void ChoixPaysAttaquant::exec (state::State& state){
  state.setPaysAttaquant(this->pays);
}

void ChoixPaysAttaquant::undo (state::State& state){
  state.setPaysAttaquant(this->pays);
}

}
