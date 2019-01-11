// Generated by dia2code
#ifndef AI__RANDOMAI__H
#define AI__RANDOMAI__H


namespace state {
  class State;
};
namespace ai {
  class AI;
}

#include "state/State.h"
#include "AI.h"

namespace ai {

  /// class RandomAI - 
  class RandomAI : public ai::AI {
    // Operations
  public:
    void aiRepartitionArmees (state::State state);
    void aiChoixPaysAttaquant (state::State state);
    void aiChoixPaysAttaque (state::State state);
    void aiDesAttaquant (state::State state);
    void aiDesAttaque (state::State state);
    void aiDefausser (state::State state);
    void aiEchange (state::State state);
    void aiPlacementArmees (state::State state);
    void aiDeplacerArmees (state::State state);
    // Setters and Getters
  };

};

#endif
