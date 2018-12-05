//etape 8
#include "GainCombat.h"

namespace engine {

GainCombat::~GainCombat (){
}

IdCommande const GainCombat::getIdCommande (){
  return GAINCOMBAT;
}

bool GainCombat::gainCartes (int idJoueur, int victoire, state::State state){
  bool valeur = false;
  if(victoire != 0){
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

    if (compt > 4){
      int numeroCarte;
      std::cout << "Vous devez défausser une carte. Laquelle choisissez-vous ?" << std::endl;
      std::cin >> numeroCarte;
      GestionCartes::defausser (numeroCarte, state);
      valeur = true;
    }

    GestionCartes::piocher(idJoueur, state);
  }
  return valeur;
}

void GainCombat::undoGainCartes (int idJoueur, bool defausse, state::State state){
  GestionCartes::undoPiocher (state);

  if (defausse){
    GestionCartes::undoDefausser (idJoueur, state);
  }
}

}
