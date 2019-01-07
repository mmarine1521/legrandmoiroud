#include "DesAttaque.h"

#include <iostream>
#include <cstdlib> // rand
#include <algorithm> // sort

namespace engine {


DesAttaque::DesAttaque (int nbDes) : Des(nbDes){
}

DesAttaque::DesAttaque (int nbDes, std::vector<int> desBleus) : Des(nbDes), desBleus(desBleus){
}

DesAttaque::~DesAttaque (){
}

bool DesAttaque::verif (state::State& state){
  if (nbDes < 1 || nbDes > 2){
    std::cout << "Problème : Vous ne pouvez lancer que 1 ou 2 dés." << std::endl;
    return false;
  }
  else{
    std::string paysAttaque = state.getPaysAttaque();
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* ptr_armee = 0;

    for(size_t i=0; i<listeArmee.size(); i++){
    	ptr_armee = listeArmee[i].get();
  		if(ptr_armee->getPays() == paysAttaque){
  			if (ptr_armee->getNombre() >= nbDes){
  				return true;
  			}
  			else{
  				std::cout << "Problème : Vous n'avez pas assez d'armées sur votre territoire pouvant défendre." << std::endl;
          return false;
        }
        break;
  		}
  	}
  }
  return false;
}

void DesAttaque::exec (state::State& state){
  state.setNbDesAttaque(this->nbDes);
  this->desBleus = Des::lancerDes(this->nbDes);
  state.setDesBleus(this->desBleus);
}

void DesAttaque::undo (state::State& state){
  state.setNbDesAttaquant(this->nbDes);
  state.setDesRouges(this->desBleus);
}

}
