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
  state::Element* e;
  for(size_t i=0; i<listeArmee.size(); i++){
    e = listeArmee[i].get();

}*/

}
