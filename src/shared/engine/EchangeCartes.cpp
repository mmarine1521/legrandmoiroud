//etape 9
#include "EchangeCartes.h"

namespace engine {

EchangeCartes::~EchangeCartes (){
}

IdCommande const EchangeCartes::getIdCommande (){
  return ECHANGECARTES;
}
// si ok faut mettre dans defausse
int EchangeCartes::echange (int idJoueur, state::State state){
  int valeur = 0;
  std::string reponse;
  std::cout << "Souhaitez-vous échanger des cartes contre des armées ? (o/n)" << std::endl;

  if (reponse == "o"){
    int numeroCarte1;
    int numeroCarte2;
    int numeroCarte3;
    std::cout << "Quel est le numéro de la première carte que vous souhaitez échanger ?" << std::endl;
    std::cin >> numeroCarte1;
    std::cout << "Quel est le numéro de la deuxième carte que vous souhaitez échanger ?" << std::endl;
    std::cin >> numeroCarte2;
    std::cout << "Quel est le numéro de la troisième carte que vous souhaitez échanger ?" << std::endl;
    std::cin >> numeroCarte3;

    state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
    std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
    state::Element* ptr_carte1 = 0;
    state::Element* ptr_carte2 = 0;
    state::Element* ptr_carte3 = 0;
    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte1 = listeEnjeu[i].get();
      if(ptr_carte1->getNumero() == numeroCarte1){
        if(ptr_carte1->getIdJoueur() != idJoueur){
          std::cout << "La première carte ne vous appartient pas." << std::endl;
          return -1;
        }
        break;
      }
    }
    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte2 = listeEnjeu[i].get();
      if(ptr_carte2->getNumero() == numeroCarte2){
        if(ptr_carte2->getIdJoueur() != idJoueur){
          std::cout << "La deuxième carte ne vous appartient pas." << std::endl;
          return -1;
        }
        break;
      }
    }
    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte3 = listeEnjeu[i].get();
      if(ptr_carte3->getNumero() == numeroCarte3){
        if(ptr_carte3->getIdJoueur() != idJoueur){
          std::cout << "La troisième carte ne vous appartient pas." << std::endl;
          return -1;
        }
        break;
      }
    }

    state::CarteForce typeCarte = ptr_carte1->getCarteForce();
    if (ptr_carte2->getCarteForce() == typeCarte){
      if (ptr_carte3->getCarteForce() == typeCarte){
        switch (typeCarte) {
          case 0 : valeur = -1; break;
          case 1 : valeur = 5; break;
          case 2 : valeur = 8; break;
          case 3 : valeur = 3; break;
        }
      }
    }
    if (valeur == -1){
      std::cout << "Vos trois cartes n'ont pas la même force. Il faut que les trois cartes soient de type TANK, CANON ou SOLDAT." << std::endl;
    }
    else{
      GestionCartes::defausser(numeroCarte1, state);
      GestionCartes::defausser(numeroCarte2, state);
      GestionCartes::defausser(numeroCarte3, state);
    }
  }
  return valeur;
}

}
