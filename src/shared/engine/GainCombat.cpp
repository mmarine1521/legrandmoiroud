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
  compt = compt / 3;
  return compt;
}

}
