//etape 7
#include "IssueDuCombat.h"

#include <algorithm>    // std::max

namespace engine {

IssueDuCombat::~IssueDuCombat (){
}

IdCommande const IssueDuCombat::getIdCommande (){
  return ISSUECOMBAT;
}

//0 => pas de victoire/défaite
//10x => victoire
//11x => victoire avec -1 armée sur le territoire battu
//le dernier chiffre x représente le joueur qui a perdu son territoire
int IssueDuCombat::victoire (std::vector<int>& desRouges, std::vector<int>& desBleus, std::string paysAttaquant, std::string paysAttaque, state::State state){//etape 7
  int ite = std::min(desRouges.size(), desBleus.size());
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_Attaquant = 0;
  state::Element* ptr_Attaque = 0;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_Attaquant = listeArmee[i].get();
    if(ptr_Attaquant->getPays() == paysAttaquant){ //récupère le pays attaquant
      break;
    }
  }

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_Attaque = listeArmee[i].get();
    if(ptr_Attaque->getPays() == paysAttaque){ //récupère le pays attaqué
      break;
    }
  }

  for (int i = 0; i < ite; i++){
    if (desRouges[i] > desBleus[i]){
      std::cout << "Vous avez gagné le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
      ptr_Attaque->setNombre(ptr_Attaque->getNombre() - 1);
    }
    else{
      std::cout << "Vous avez perdu le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
      ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() - 1);
    }
  }

  int valeur;
  if (ptr_Attaque->getNombre() < 0){
    valeur = 110 + ptr_Attaque->getIdJoueur();
    std::cout << "Vous avez gagné le territoire." << std::endl;
    ptr_Attaque->setNombre(1);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() - 1);
    ptr_Attaque->setIdJoueur(ptr_Attaquant->getIdJoueur());
  }
  else if (ptr_Attaque->getNombre() == 0){
    valeur = 100 + ptr_Attaque->getIdJoueur();
    std::cout << "Vous avez gagné le territoire." << std::endl;
    ptr_Attaque->setNombre(1);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() - 1);
    ptr_Attaque->setIdJoueur(ptr_Attaquant->getIdJoueur());
  }
  else{
    return valeur = 0;
  }

  return valeur;
}

void IssueDuCombat::undoVictoire (int victoire, std::vector<int>& desRouges, std::vector<int>& desBleus, std::string paysAttaquant, std::string paysAttaque, state::State state){
  int ite = std::min(desRouges.size(), desBleus.size());
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_Attaquant = 0;
  state::Element* ptr_Attaque = 0;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_Attaquant = listeArmee[i].get();
    if(ptr_Attaquant->getPays() == paysAttaquant){ //récupère le pays attaquant
      break;
    }
  }

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_Attaque = listeArmee[i].get();
    if(ptr_Attaque->getPays() == paysAttaque){ //récupère le pays attaqué
      break;
    }
  }

  if (victoire == 101){
    ptr_Attaque->setIdJoueur(victoire % 10);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    ptr_Attaque->setNombre(0);
  }
  else if (victoire == 102){
    ptr_Attaque->setIdJoueur(victoire % 10);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    ptr_Attaque->setNombre(0);
  }
  else if (victoire == 103){
    ptr_Attaque->setIdJoueur(victoire % 10);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    ptr_Attaque->setNombre(0);
  }
  else if (victoire == 111){
    ptr_Attaque->setIdJoueur(victoire % 10);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    ptr_Attaque->setNombre(-1);
  }
  else if (victoire == 111){
    ptr_Attaque->setIdJoueur(victoire % 10);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    ptr_Attaque->setNombre(-1);
  }
  else if (victoire == 111){
    ptr_Attaque->setIdJoueur(victoire % 10);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    ptr_Attaque->setNombre(-1);
  }

  for (int i = 0; i < ite; i++){
    if (desRouges[i] > desBleus[i]){
      ptr_Attaque->setNombre(ptr_Attaque->getNombre() + 1);
    }
    else{
      ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    }
  }
}

}
