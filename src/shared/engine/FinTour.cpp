#include "FinTour.h"

namespace engine {

FinTour::FinTour(int idJoueurCommande) : Commande(idJoueurCommande){
}

FinTour::~FinTour (){
}

void FinTour::exec(state::State& state){
  if (state.getIdJoueur() == 1){
    state.setIdJoueur(2);
  }
  else{
    state.setIdJoueur(1);
  }
  state.setTourId(state.getTourId() + 1);
}

void FinTour::undo (state::State& state){
  if (state.getIdJoueur() == 1){
    state.setIdJoueur(2);
  }
  else{
    state.setIdJoueur(1);
  }
  state.setTourId(state.getTourId() - 1);
}

}
