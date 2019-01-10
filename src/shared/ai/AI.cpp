#include "AI.h"

namespace ai {

std::list<engine::Commande*> AI::commandes;
std::list<engine::Commande*> AI::undos;
std::list<state::StepId> AI::steps;

void AI::pushCommande(engine::Commande* commande){
  commandes.push_back(commande);
}

void AI::aiRemplirCommandes(state::State state){
  state::StepId etape = state.getStepId();
  switch (etape) {
    case state::DISTRIBUTION_s :
      this.pushCommande(new engine::Distribution());
      break;
    case state::REPARTITION_ARMEES_s :
      this.aiPlacementArmees(state);
      break;
    case state::CHOIX_PAYS_ATTAQUANT_s :
      this.aiChoixPaysAttaquant(state);
      break;
    case state::CHOIX_PAYS_ATTAQUE_s :
      this.aiChoixPaysAttaquant(state);
      break;
    case state::NB_DES_ATTAQUANT_s :
      this.aiDesAttaquant(state);
      break;
    case state::NB_DES_ATTAQUE_s :
      this.aiDesAttaque(state);
      break;
    case state::DEFAUSSER_s :
      this.aiDefausser(state);
      break;
    case state::PIOCHER_s :
      this.pushCommande(new Piocher());
      break;
    case state::ECHANGE_s :
      this.aiEchange(state);
      break;
    case state::PLACER_NOUVELLES_ARMEES_s :
      this.aiPlacementArmees(state);
      break;
    case state::DEPLACER_ARMEES_s :
      this.aiDeplacerArmees(state);
      break;
  }
}

}
