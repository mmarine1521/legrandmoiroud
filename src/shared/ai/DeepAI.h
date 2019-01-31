// Generated by dia2code
#ifndef AI__DEEPAI__H
#define AI__DEEPAI__H

#include <list>
#include <string>
#include <vector>

namespace engine {
  class Commande;
};
namespace state {
  class State;
};
namespace ai {
  class AI;
  class HeuristicAI;
}

#include "AI.h"
#include "HeuristicAI.h"

namespace ai {

  /// class DeepAI - 
  class DeepAI : public ai::AI {
    // Associations
    // Attributes
  public:
    std::list<engine::Commande*> commandes;
    std::list<engine::Commande*> commandesAExecuter;
    std::list<engine::Commande*> undos;
  private:
    std::vector<std::string> paysAttaquants;
    std::vector<std::string> paysAttaques;
    // Operations
  public:
    DeepAI (int idJoueur);
    int evalState (state::State& state, int profondeur, int minMax);
    void selectPaysAttaquants (state::State& state);
    void selectPaysAttaques (state::State& state);
    engine::Commande* aiRepartitionArmees (state::State& state);
    engine::Commande* aiChoixPaysAttaquant (state::State& state);
    engine::Commande* aiChoixPaysAttaque (state::State& state);
    engine::Commande* aiDesAttaquant (state::State& state);
    engine::Commande* aiDesAttaque (state::State& state);
    engine::Commande* aiDefausser (state::State& state);
    engine::Commande* aiEchange (state::State& state);
    engine::Commande* aiPlacementArmees (state::State& state);
    engine::Commande* aiDeplacerArmees (state::State& state);
    void initializePays ();
    // Setters and Getters
  };

};

#endif