// Initialisation 4
#include "Piocher.h"

namespace engine {

Piocher::Piocher (int numeroCarte) : Cartes(numeroCarte){
}

Piocher::~Piocher (){
}

IdCommande const Piocher::getIdCommande (){
  return PIOCHER_c;
}

void Piocher::exec (state::State state){
  int idJoueur = state.getIdJoueur();
  state::ElementTab& tabPioche = state.getCartePiocheTab();
  std::vector<std::shared_ptr<state::Element>> listePioche = tabPioche.getElementList();
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();

  if (listePioche.size() == 0){
    state::ElementTab& tabDefausse = state.getCarteDefausseTab();
    std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
    listePioche = tabDefausse.getElementList();
    listeDefausse.clear();
    tabPioche.melange();
  }

  state::Element* ptr_Pioche = 0;
  ptr_Pioche = listePioche[0].get();
  this->numeroCarte = ptr_Pioche->getNumero();
  ptr_Pioche->setIdJoueur(idJoueur);
  listeEnjeu.push_back(ptr_Pioche->clone());
  listePioche.erase(listePioche.begin());
  std::cout << "Vous avez tiré la carte numéro " << this->numeroCarte << "." << std::endl;
}

void Piocher::undo (state::State state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::ElementTab& tabPioche = state.getCartePiocheTab();
  std::vector<std::shared_ptr<state::Element>> listePioche = tabPioche.getElementList();
  state::Element* ptr_carte;

  for(size_t i=0; i<listeEnjeu.size(); i++){
    ptr_carte = listeEnjeu[i].get();
    if (ptr_carte->getNumero() == this->numeroCarte){
      ptr_carte->setIdJoueur(0);
      listePioche.push_back(ptr_carte->clone());
      listeEnjeu.erase(listeEnjeu.begin() + i);
    }
    break;
  }
  tabPioche.melange();
}

}
