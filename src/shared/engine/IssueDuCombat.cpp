#include "IssueDuCombat.h"

#include <algorithm>    // std::max
#include <fstream>

namespace engine {

IssueDuCombat::IssueDuCombat (int idJoueurCommande, int victoire) : Commande(idJoueurCommande), victoire(victoire){
} //undos

IssueDuCombat::~IssueDuCombat (){
}

IdCommande const IssueDuCombat::getIdCommande(){
  return ISSUE_COMBAT_c;
}

void IssueDuCombat::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::app);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"IssueDuCombat\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << "," << std::endl;
    fichier << "\"victoire\" : " << this->victoire << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
}

int IssueDuCombat::nbCartesJoueur (state::State& state){
  int idJoueur = state.getIdJoueur();
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::Element* ptr_carte = 0;

  int compt = 0;
  for(size_t i=0; i<listeEnjeu.size(); i++){
    ptr_carte = listeEnjeu[i].get();
    if(ptr_carte->getIdJoueur() == idJoueur){
      compt += 1;
    }
  }
  return compt;
}

//0 => pas de victoire/défaite
//10x => victoire
//11x => victoire avec -1 armée sur le territoire battu
//le dernier chiffre x représente le joueur qui a perdu son territoire
void IssueDuCombat::exec (state::State& state){
  std::vector<int> desRouges = state.getDesRouges();
  std::vector<int> desBleus = state.getDesBleus();
  std::string paysAttaquant = state.getPaysAttaquant();
  std::string paysAttaque = state.getPaysAttaque();

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
      std::cout << "Vous avez gagné le lancé " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
      ptr_Attaque->setNombre(ptr_Attaque->getNombre() - 1);
    }
    else{
      std::cout << "Vous avez perdu le lancé " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
      ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() - 1);
    }
  }

  if (ptr_Attaque->getNombre() < 0){
    this->victoire = 110 + ptr_Attaque->getIdJoueur();
    std::cout << "Vous avez gagné le territoire." << std::endl;
    ptr_Attaque->setNombre(1);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() - 1);
    ptr_Attaque->setIdJoueur(ptr_Attaquant->getIdJoueur());
  }
  else if (ptr_Attaque->getNombre() == 0){
    this->victoire = 100 + ptr_Attaque->getIdJoueur();
    std::cout << "Vous avez gagné le territoire." << std::endl;
    ptr_Attaque->setNombre(1);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() - 1);
    ptr_Attaque->setIdJoueur(ptr_Attaquant->getIdJoueur());
  }
  else{
    this->victoire = 0;
  }
  state.setVictoire(this->victoire);
}

void IssueDuCombat::undo (state::State& state){
  std::vector<int> desRouges = state.getDesRouges();
  std::vector<int> desBleus = state.getDesBleus();
  std::string paysAttaquant = state.getPaysAttaquant();
  std::string paysAttaque = state.getPaysAttaque();
  int victoire = state.getVictoire();

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

  if (victoire != 0){
    ptr_Attaque->setIdJoueur(victoire % 10);
    ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);

    if (victoire == 101 || victoire == 102 || victoire == 103){
      ptr_Attaque->setNombre(0);
    }
    else{
        ptr_Attaque->setNombre(-1);
    }
  }

  for (int i = 0; i < ite; i++){
    if (desRouges[i] > desBleus[i]){
      ptr_Attaque->setNombre(ptr_Attaque->getNombre() + 1);
    }
    else{
      ptr_Attaquant->setNombre(ptr_Attaquant->getNombre() + 1);
    }
  }

  state.setVictoire(this->victoire);
}

}
