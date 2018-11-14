//etapes 1-2
#include "ChoixPays.h"

#include <iostream>

namespace engine {

ChoixPays::~ChoixPays (){
}

IdCommande const ChoixPays::getIdCommande (){
  return CHOIXPAYS;
}

bool ChoixPays::estFrontalier(std::string pays1, std::string pays2, state::State state){
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

std::string ChoixPays::choixPaysAttaquant (){//etape 1
  std::cout << "Avec quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  std::cout << std::endl;
  return pays;
}

bool ChoixPays::verifPaysAttaquant (int idJoueur, std::string paysAttaquant, state::State state){//etape 1
  bool ok = false;
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if(ptr_armee->getPays() == paysAttaquant){
      break; // on a la bonne Armee
    }
  }
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
    for(size_t i=0; i<listePaysFontaliers.size(); i++){
      std::string paysFrontalier = listePaysFontaliers[i];
      for(size_t j=0; j<listeArmee.size(); j++){
        ptr_frontalier = listeArmee[j].get();
        if(ptr_frontalier->getPays() == paysFrontalier){
          if(ptr_frontalier->getIdJoueur() != idJoueur){
            ok = true;
          }
          break;
        }
      }
    }

  }
  else {
    std::cout << "Problème : Ce pays ne vous appartient pas." << std::endl;
  }

  return ok;
}

std::string ChoixPays::choixPaysAttaque (){//etape 2
  std::cout << "Quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  std::cout << std::endl;
  return pays;
}

bool ChoixPays::verifPaysAttaque (int idJoueur, std::string paysAttaque, std::string paysAttaquant, state::State state){
  bool ok = false;
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
    ok = estFrontalier(paysAttaque, paysAttaquant, state);
    if (!ok){
      std::cout << "Problème : Ce pays n'est pas un frontalier." << std::endl;
    }
  }
  else{
    std::cout << "Problème : Ce territoire vous appartient." << std::endl;
  }
  return ok;
}

}
