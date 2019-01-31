#include "AI.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>


using namespace ai ;


AI::AI(int idJoueurAI) : idJoueurAI(idJoueurAI){
}

int AI::getIdJoueurAI(){
  return this->idJoueurAI;
}

void AI::aiRemplirCommandes(state::State* state) {
  state::StepId etape = state->getStepId();
  switch (etape) {
    case state::DISTRIBUTION_s :
      engine::TourDeJeu::pushCommande(new engine::Distribution(this->idJoueurAI));
      break;
    case state::REPARTITION_ARMEES_s :
      engine::TourDeJeu::pushCommande(this->aiRepartitionArmees(*state));
      break;
    case state::CHOIX_PAYS_ATTAQUANT_s :
      engine::TourDeJeu::pushCommande(this->aiChoixPaysAttaquant(*state));
      break;
    case state::CHOIX_PAYS_ATTAQUE_s :
      engine::TourDeJeu::pushCommande(this->aiChoixPaysAttaque(*state));
      break;
    case state::NB_DES_ATTAQUANT_s :
      engine::TourDeJeu::pushCommande(this->aiDesAttaquant(*state));
      break;
    case state::NB_DES_ATTAQUE_s :
      engine::TourDeJeu::pushCommande(this->aiDesAttaque(*state));
      break;
    case state::DEFAUSSER_s :
      engine::TourDeJeu::pushCommande(this->aiDefausser(*state));
      break;
    case state::PIOCHER_s :
      engine::TourDeJeu::pushCommande(new engine::Piocher(this->idJoueurAI));
      break;
    case state::ECHANGE_s :
      engine::TourDeJeu::pushCommande(this->aiEchange(*state));
      break;
    case state::PLACER_NOUVELLES_ARMEES_s :
      engine::TourDeJeu::pushCommande(this->aiPlacementArmees(*state));
      break;
    case state::DEPLACER_ARMEES_s :
      engine::TourDeJeu::pushCommande(this->aiDeplacerArmees(*state));
      break;
  }
}
