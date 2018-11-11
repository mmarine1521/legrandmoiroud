//etapes 1-2
#include "ChoixPays.h"

#include <iostream>

namespace engine {

ChoixPays::~ChoixPays (){
}

IdCommande const ChoixPays::getIdCommande (){
  return CHOIXPAYS;
}

std::string ChoixPays::choixPaysAttaquant (){//etape 1
  std::cout << "Avec quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  return pays;
}

bool ChoixPays::verifPaysAttaquant (int idJoueur, std::string paysAttaquant, state::State state){//etape 1
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* e = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    e = listeArmee[i].get();
    if(e->getPays() == paysAttaquant){
      if (e->getIdJoueur() == idJoueur){
        return true;
      }
      else {
        std::cout << "Ce pays ne vous appartient pas." << std::endl;
      }
    }
  }
  return false;
}

std::string ChoixPays::choixPaysAttaque (){//etape 2
  std::cout << "Quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  return pays;
}

bool ChoixPays::verifPaysAttaque (int idJoueur, std::string paysAttaque, std::string paysAttaquant, state::State state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* eAttaque = 0;
  state::Element* eAttaquant = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    eAttaque = listeArmee[i].get();
    if(eAttaque->getPays() == paysAttaque){
      break;
    }
  }
  for(size_t i=0; i<listeArmee.size(); i++){
    eAttaquant = listeArmee[i].get();
    if(eAttaquant->getPays() == paysAttaquant){
      break;
    }
  }
  if (eAttaque->getIdJoueur() != idJoueur){
    state::ElementTab& tabPays = state.getPaysTab();
    std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
    state::Element* ePaysAttaquant = 0;
    for(size_t i=0; i<listePays.size(); i++){
      ePaysAttaquant = listeArmee[i].get();
      if(ePaysAttaquant->getPays() == paysAttaquant){
        std::vector<std::string> listePaysFontaliers = ePaysAttaquant->getPaysFrontaliers();
        for(size_t i=0; i<listePaysFontaliers.size(); i++){
          if(listePaysFontaliers[i] == paysAttaque){
            return true;
          }
        }
      }
    }
  }
  else{
    std::cout << "Ce territoire vous appartient." << std::endl;
  }
  return false;
}// message si pas frontalier ?

}
