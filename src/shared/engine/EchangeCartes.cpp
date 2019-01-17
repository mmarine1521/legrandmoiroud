#include "EchangeCartes.h"

#include <fstream>

namespace engine {

EchangeCartes::EchangeCartes (int idJoueurCommande, int numeroCarte) : Commande(idJoueurCommande), numeroCarte(numeroCarte){
}

EchangeCartes::~EchangeCartes (){
}

IdCommande const EchangeCartes::getIdCommande (){
  return ECHANGE_c;
}

void EchangeCartes::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::out);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"EchangeCartes\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << "," << std::endl;
    fichier << "\"numeroCarte\" : " << this->numeroCarte << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
}

bool EchangeCartes::verif(state::State& state){// verifie que le joueur possède la carte
  int idJoueur = this->idJoueurCommande;
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::Element* ptr_carte = 0;

  for(size_t i=0; i<listeEnjeu.size(); i++){
    ptr_carte = listeEnjeu[i].get();
    if(ptr_carte->getNumero() == numeroCarte){
      if(ptr_carte->getIdJoueur() == idJoueur){
        return true;
      }
      else{
        std::cout << "Cette carte ne vous appartient pas." << std::endl;
        return false;
      }
      break;
    }
  }
  std::cout << "Cette carte n'est pas en jeu." << std::endl;
  return false;
}

int EchangeCartes::gain (state::State& state){
  std::vector<state::CarteForce> forceCartes = state.getTypeCartes();
  state::CarteForce forceCarte1 = forceCartes[0];
  state::CarteForce forceCarte2 = forceCartes[1];
  state::CarteForce forceCarte3 = forceCartes[2];

  if(forceCarte1 == 1 && forceCarte2 == 1 && forceCarte3 == 1){ //TANK
    return 5;
  }
  else if (forceCarte1 == 2 && forceCarte2 == 2 && forceCarte3 == 2) { //CANON
    return 8;
  }
  else if (forceCarte1 == 3 && forceCarte2 == 3 && forceCarte3 == 3) { //SOLDAT
    return 3;
  }
  else {
    std::cout << "Vos trois cartes n'ont pas la même force. Il faut que les trois cartes soient de type TANK, CANON ou SOLDAT." << std::endl;
    return 0;
  }
}

void EchangeCartes::exec (state::State& state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::Element* ptr_carte = 0;

  for(size_t i=0; i<listeEnjeu.size(); i++){
    ptr_carte = listeEnjeu[i].get();
    if(ptr_carte->getNumero() == numeroCarte){
      state.setTypeCarte(ptr_carte->getCarteForce());
      break;
    }
  }
  Commande* defausse = new Defausser(this->idJoueurCommande, numeroCarte);
  defausse->exec(state);
  state.setNbCartes(state.getNbCartes() - 1);
}

void EchangeCartes::undo (state::State& state){
  state.deleteTypeCarte();
  Commande* defausse = new Defausser(this->idJoueurCommande, numeroCarte);
  defausse->undo(state);
}

}
