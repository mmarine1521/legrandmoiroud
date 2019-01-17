#include "DesAttaque.h"

#include <iostream>
#include <cstdlib> // rand
#include <algorithm> // sort
#include <fstream>

namespace engine {

DesAttaque::DesAttaque (int idJoueurCommande, int nbDes) : Des(idJoueurCommande, nbDes){
} //commandes

DesAttaque::DesAttaque (int idJoueurCommande, int nbDes, std::vector<int> desBleus) : Des(idJoueurCommande, nbDes), desBleus(desBleus){
} //undos

DesAttaque::~DesAttaque (){
}

IdCommande const DesAttaque::getIdCommande (){
	return NB_DES_ATTAQUE_c;
}

void DesAttaque::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::out);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"DesAttaque\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << "," << std::endl;
    fichier << "\"nbDes\" : " << this->nbDes << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
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
