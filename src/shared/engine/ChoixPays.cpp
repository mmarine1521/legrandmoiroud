#include "ChoixPays.h"

#include <iostream>

namespace engine {

ChoixPays::~ChoixPays (){
}

IdCommande const ChoixPays::getIdCommande (){
  return CHOIXPAYS;
}

std::string ChoixPays::choixPaysAttaquant (){
  std::cout << "Avec quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  return pays;
}

bool ChoixPays::verifPaysAttaquant (int idJoueur, std::string paysAttaquant, state::State state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::unique_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* e;
  for(size_t i=0; i<listeArmee.size(); i++){
    e = listeArmee[i].get();
    if(e->getPays()==paysAttaquant){
      if (e->getIdJoueur() >= idJoueur){
        return true;
      }
    }
  }
  return false;
}

//std::string ChoixPays::choixPaysAttaque (){}

//bool ChoixPays::verifPaysAttaque (int idJoueur, std::string paysAttaque){}

}
