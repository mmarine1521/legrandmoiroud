#include "Defausser.h"

#include <fstream>

namespace engine {

Defausser::Defausser (int idJoueurCommande, int numeroCarte) : Cartes(idJoueurCommande, numeroCarte){
}

Defausser::~Defausser (){
}

IdCommande const Defausser::getIdCommande (){
  return DEFAUSSER_c;
}

void Defausser::exec (state::State& state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::ElementTab& tabDefausse = state.getCarteDefausseTab();
  std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
  state::Element* ptr_Enjeu = 0;

  for(size_t i=0; i<listeEnjeu.size(); i++){
    ptr_Enjeu = listeEnjeu[i].get();
    if (ptr_Enjeu->getNumero() == this->numeroCarte){
      ptr_Enjeu->setIdJoueur(0);
      listeDefausse.push_back(ptr_Enjeu->clone());
      listeEnjeu.erase(listeEnjeu.begin() + i);
    }
    break;
  }
}

void Defausser::undo (state::State& state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::ElementTab& tabDefausse = state.getCarteDefausseTab();
  std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
  state::Element* ptr_carte;
  bool ok = false;

  for(size_t i=0; i<listeDefausse.size(); i++){
    ptr_carte = listeDefausse[i].get();
    if (ptr_carte->getNumero() == this->numeroCarte){
      ptr_carte->setIdJoueur(this->idJoueurCommande);
      listeEnjeu.push_back(ptr_carte->clone());
      listeDefausse.erase(listeDefausse.begin() + i);
      ok = true;
    }
    break;
  }

  if (!ok){
    state::ElementTab& tabPioche = state.getCartePiocheTab();
    std::vector<std::shared_ptr<state::Element>> listePioche = tabPioche.getElementList();
    for(size_t i=0; i<listePioche.size(); i++){
      ptr_carte = listePioche[i].get();
      if (ptr_carte->getNumero() == this->numeroCarte){
        ptr_carte->setIdJoueur(this->idJoueurCommande);
        listeEnjeu.push_back(ptr_carte->clone());
        listePioche.erase(listePioche.begin() + i);
      }
      break;
    }
  }
}

}
