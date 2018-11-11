//etapes 1-2
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

std::string ChoixPays::choixPaysAttaque (){
  std::cout << "Quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  return pays;
}

bool ChoixPays::verifPays (int idJoueur, std::string pays, state::State state){
  //fonctionne pour le pays attaquant et le pays attaqué
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* e;
  for(size_t i=0; i<listeArmee.size(); i++){
    e = listeArmee[i].get();
    if(e->getPays() == pays){
      if (e->getIdJoueur() == idJoueur){
        return true;
      }
    }
  }
  return false;
}// frontalier pour paysAttaque, mettre des cout dans les bool

}
