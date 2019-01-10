#include "ChoixPaysAttaque.h"

#include <iostream>

namespace engine {

ChoixPaysAttaque::ChoixPaysAttaque (int idJoueur, std::string pays) : ChoixPays(idJoueur, pays){
}

ChoixPaysAttaque::~ChoixPaysAttaque (){
}

IdCommande const ChoixPaysAttaque::getIdCommande (){
  return CHOIX_PAYS_ATTAQUE_c;
}

bool ChoixPaysAttaque::estFrontalier(std::string pays1, std::string pays2, state::State& state){
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ePays = 0;
  for(size_t i=0; i<listePays.size(); i++){
    ePays = listePays[i].get();
    if(ePays->getPays() == pays1){
      std::vector<std::string> listePaysFontaliers = ePays->getPaysFrontaliers();
      for(size_t i=0; i<listePaysFontaliers.size(); i++){
        if(listePaysFontaliers[i] == pays2){
          return true;
        }
      }
    }
  }
  return false;
}

bool ChoixPaysAttaque::verif (state::State& state){
  bool ok = false;

  std::string paysAttaquant = state.getPaysAttaquant();
  std::string paysAttaque = state.getPaysAttaque();
  int idJoueur = state.getIdJoueur();

  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_attaque = 0;
  state::Element* ptr_attaquant = 0;

  //On récupère le pays attaqué.
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_attaque = listeArmee[i].get();
    if(ptr_attaque->getPays() == paysAttaque){
      break;
    }
  }
  //On récupère le pays attaquant.
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_attaquant = listeArmee[i].get();
    if(ptr_attaquant->getPays() == paysAttaquant){
      break;
    }
  }

  if (ptr_attaque->getIdJoueur() != idJoueur){
    ok = estFrontalier(paysAttaque, paysAttaquant, state);
    if (!ok){
      std::cout << "Problème : Ce territoire n'est pas un frontalier." << std::endl;
    }
  }
  else{
    std::cout << "Problème : Ce territoire vous appartient." << std::endl;
  }
  return ok;
}

void ChoixPaysAttaque::exec (state::State& state){
  state.setPaysAttaque(this->pays);
}

void ChoixPaysAttaque::undo (state::State& state){
  state.setPaysAttaque(this->pays);
}

}
