#include "FinTour.h"

#include <fstream>

namespace engine {

FinTour::FinTour(int idJoueurCommande) : Commande(idJoueurCommande){
}

FinTour::~FinTour (){
}

IdCommande const FinTour::getIdCommande(){
  return FIN_c;
}

void FinTour::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::app);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"FinTour\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
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
