//etape 8
#include "GainCombat.h"

namespace engine {

GainCombat::~GainCombat (){
}

IdCommande const GainCombat::getIdCommande (){
  return GAINCOMBAT;
}

void GainCombat::gainCartes (int idJoueur, bool victoire, state::State state){
  if(victoire){
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
    }

    GestionCartes::piocher(idJoueur, state);
  }
}

int GainCombat::gainArmees (int idJoueur, state::State state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* e = 0;
  int compt = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    e = listeArmee[i].get();
    if(e->getIdJoueur()==idJoueur){
      compt += 1;
    }
  }
  compt = compt / 3; //div
  return compt;
}

}
