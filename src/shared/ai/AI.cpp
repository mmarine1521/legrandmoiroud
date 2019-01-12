
#include "AI.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>


using namespace ai ; 


AI::AI(int idJoueur) : idJoueur(idJoueur){
}

int AI::getIdJoueur(){
  return this->idJoueur;
}

void AI::aiRepartitionArmees(state::State& state) 
{
}

void AI::aiChoixPaysAttaquant(state::State& state)
{
}

void AI::aiChoixPaysAttaque(state::State& state) 
{
}

void AI::aiDesAttaquant(state::State& state)
{
}

void AI::aiDesAttaque(state::State& state) 
{
}

void AI::aiDefausser(state::State& state) 
{
}

void AI::aiEchange(state::State& state) 
{
}

void AI::aiPlacementArmees(state::State& state) 
{
}

void AI::aiDeplacerArmees(state::State& state) 
{
}

	

void AI::aiRemplirCommandes(state::State& state, sf::RenderWindow& window){
  state::StepId etape = state.getStepId();
  switch (etape) {
    case state::DISTRIBUTION_s :
      engine::TourDeJeu::pushCommande(new engine::Distribution(this->getIdJoueur()));
      break;
    case state::REPARTITION_ARMEES_s :
      this->aiRepartitionArmees(state);
      break;
    case state::CHOIX_PAYS_ATTAQUANT_s :
      this->aiChoixPaysAttaquant(state);
      break;
    case state::CHOIX_PAYS_ATTAQUE_s :
      this->aiChoixPaysAttaque(state);
      break;
    case state::NB_DES_ATTAQUANT_s :
      this->aiDesAttaquant(state);
      break;
    case state::NB_DES_ATTAQUE_s :
      this->aiDesAttaque(state);
      break;
    case state::DEFAUSSER_s :
      this->aiDefausser(state);
      break;
    case state::PIOCHER_s :
      engine::TourDeJeu::pushCommande(new engine::Piocher(this->getIdJoueur()));
      break;
    case state::ECHANGE_s :
      this->aiEchange(state);
      break;
    case state::PLACER_NOUVELLES_ARMEES_s :
      this->aiPlacementArmees(state);
      break;
    case state::DEPLACER_ARMEES_s :
      this->aiDeplacerArmees(state);
      break;
  }
}


