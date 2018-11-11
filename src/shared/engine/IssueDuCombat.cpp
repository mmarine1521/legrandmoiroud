#include "IssueDuCombat.h"

#include <algorithm>    // std::max

namespace engine {

IssueDuCombat::~IssueDuCombat (){
}

IdCommande const IssueDuCombat::getIdCommande (){
  return ISSUECOMBAT;
}

void IssueDuCombat::comparaison (std::vector<int> desRouges, std::vector<int> desBleus, std::string paysAttaquant, std::string paysAttaque, state::State state){
  int ite = std::max(desRouges.size(), desBleus.size());
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* eAttaquant = 0;
  state::Element* eAttaque = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    eAttaquant = listeArmee[i].get();
    if(eAttaquant->getPays()==paysAttaquant){
      break;
    }
  }
  for(size_t i=0; i<listeArmee.size(); i++){
    eAttaque = listeArmee[i].get();
    if(eAttaque->getPays()==paysAttaque){
      break;
    }
  }
  for (int i = 0; i < ite; i++){
    if (desRouges[i] > desBleus[i]){
      std::cout << "Vous avez gagné le tour " << i << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
      eAttaque->setNombre(eAttaque->getNombre() - 1);
    }
    else{
      std::cout << "Vous avez perdu le tour " << i << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
      eAttaquant->setNombre(eAttaquant->getNombre() - 1);
    }
  }
  if (eAttaquant->getNombre() <= 0){
    std::cout << "Vous avez perdu votre territoire." << std::endl;
    eAttaquant->setNombre(1);
    if (eAttaquant->getIdJoueur() == 1){
      eAttaquant->setIdJoueur(2);
    }
    else{
      eAttaquant->setIdJoueur(1);
    }
  }
  if (eAttaque->getNombre() <= 0){
    std::cout << "Vous avez gagné le territoire." << std::endl;
    eAttaque->setNombre(1);
    if (eAttaque->getIdJoueur() == 1){
      eAttaque->setIdJoueur(2);
    }
    else{
      eAttaque->setIdJoueur(1);
    }
  }
}

}
