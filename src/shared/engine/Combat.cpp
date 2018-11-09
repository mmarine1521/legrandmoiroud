#include "Combat.h"

#include <iostream>
#include <cstdlib> // rand
#include <algorithm> // sort

namespace engine {

Combat::~Combat (){
}

IdCommande const Combat::getIdCommande (){
  return COMBAT;
}

int Combat::nbDesLances (){ // Appeler pour l'attaque et la défense
  std::cout << "Combien de dés souhaitez-vous lancer ?" << std::endl;
  int nbDes;
  std::cin >> nbDes;
  return nbDes;
}

bool Combat::verifNbAttaques (int nbDes, std::string paysAttaquant, state::State state){
  if (nbDes<1 || nbDes>3){
    std::cout << "Vous ne pouvez lancer que 1, 2 ou 3 dés." << std::endl;
    return false;
  }
  else{
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::unique_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* e;
    for(size_t i=0; i<listeArmee.size(); i++){
      e = listeArmee[i].get();
  		if(e->getPays()==paysAttaquant){
        if (e->getNombre() >= nbDes){
          return true;
        }
  		}
  	}
  }
  return false;
}

bool Combat::verifNbDefenses (int nbDes, std::string paysAttaque, state::State state){
  if (nbDes<1 || nbDes>2){
    std::cout << "Vous ne pouvez lancer que 1 ou 2 dés." << std::endl;
    return false;
  }
  else{
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::unique_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* e;
    for(size_t i=0; i<listeArmee.size(); i++){
      e = listeArmee[i].get();
  		if(e->getPays()==paysAttaque){
        if (e->getNombre() >= nbDes){
          return true;
        }
  		}
  	}
  }
  return false;
}

std::vector<int> Combat::lancerDes (int nbDes){
  std::vector<int> liste(nbDes);
  int nb;
  srand (time(NULL));
  for (int i=0; i<nbDes; i++){
    nb = rand() % 6 + 1; //nb aleatoire de 1 à 6
    liste[i] = nb;
  }
   std::sort (liste.begin(), liste.end());
   return liste;
}

}
