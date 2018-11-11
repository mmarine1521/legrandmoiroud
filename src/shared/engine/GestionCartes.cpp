// Initialisation 4
#include "GestionCartes.h"

namespace engine {

GestionCartes::~GestionCartes (){
}

IdCommande const GestionCartes::getIdCommande (){
  return GESTCARTES;
}
/*
std::shared_ptr<state::Carte> GestionCartes::piocher (state::State state){
  state::ElementTab& tabPioche = state.getCartePiocheTab();
  std::vector<std::shared_ptr<state::Element>> listePioche = tabPioche.getElementList();
  if (listePioche.size() == 0){
    state::ElementTab& tabDefausse = state.getCarteDefausseTab();
    std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
    listePioche = listeDefausse;
    listeDefausse.clear();
    tabPioche.melange();
  }
  return listePioche[0];
}*/
/*
void GestionCartes::defausser (std::shared_ptr<state::Carte> carteDefausse, state::State state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::ElementTab& tabDefausse = state.getCarteDefausseTab();
  std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
  for(size_t i=0; i<listeEnjeu.size(); i++){
    if (listeEnjeu[i] == carteDefausse){
      listeEnjeu.erase(i);
      listeDefausse.push_back(listeEnjeu[i]);
    }
  }
}*/

}
