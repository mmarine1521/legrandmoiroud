#include "DesAttaquant.h"

#include <iostream>
#include <fstream>

namespace engine {

DesAttaquant::DesAttaquant (int idJoueurCommande, int nbDes) :Des(idJoueurCommande, nbDes){
} //commandes

DesAttaquant::DesAttaquant (int idJoueurCommande, int nbDes, std::vector<int> desRouges) : Des(idJoueurCommande, nbDes), desRouges(desRouges){
} //undos

DesAttaquant::~DesAttaquant (){
}

IdCommande const DesAttaquant::getIdCommande (){
	return NB_DES_ATTAQUANT_c;
}

void DesAttaquant::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::app);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"DesAttaquant\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << "," << std::endl;
    fichier << "\"nbDes\" : " << this->nbDes << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
}

bool DesAttaquant::verif (state::State& state){
  if (nbDes < 1 || nbDes > 3){
    std::cout << "Problème : Vous ne pouvez lancer que 1, 2 ou 3 dés." << std::endl;
    return false;
  }
  else{
    std::string paysAttaquant = state.getPaysAttaquant();
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* ptr_armee = 0;

    for(size_t i=0; i<listeArmee.size(); i++){
    	ptr_armee = listeArmee[i].get();
  		if(ptr_armee->getPays() == paysAttaquant){
  			if (ptr_armee->getNombre() >= this->nbDes + 1){ //on vérifie si le nombre d'armées du pays est supérieur au nombre de dés choisi pour l'attaque
  				return true;
  			}
  			else{
  				std::cout << "Problème : Vous n'avez pas assez d'armées sur votre territoire pouvant attaquer." << std::endl;
  				return false;
  			}
        break;
  		}
  	}
  }
  return false;
}

void DesAttaquant::exec (state::State& state){
  state.setNbDesAttaquant(this->nbDes);
  this->desRouges = Des::lancerDes(this->nbDes);
  state.setDesRouges(this->desRouges);
}

void DesAttaquant::undo (state::State& state){
  state.setNbDesAttaquant(this->nbDes);
  state.setDesRouges(this->desRouges);
}

}
