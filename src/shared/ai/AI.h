// Generated by dia2code
#ifndef AI__AI__H
#define AI__AI__H

#include <string>
#include <vector>

namespace state {
  class State;
};
namespace engine {
  class GainCombat;
  class IssueDuCombat;
  class Combat;
  class AttributionTerritoires;
  class ChoixPays;
  class GestionCartes;
  class Commande;
}

#include "state/State.h"
#include "engine/GainCombat.h"
#include "engine/IssueDuCombat.h"
#include "engine/Combat.h"
#include "engine/AttributionTerritoires.h"
#include "engine/ChoixPays.h"
#include "engine/GestionCartes.h"
#include "engine/Commande.h"

namespace ai {

  /// class AI - 
  class AI {
    // Operations
  public:
    virtual void aiRepartitionArmees (int idJoueur, state::State state) = 0;
    virtual std::string aiChoixPaysAttaquant (int idJoueur, std::vector<std::string> blackList, state::State state) = 0;
    virtual std::string aiChoixPaysAttaque (int idJoueur, std::string paysAttaquant, state::State state) = 0;
    virtual void aiGainCartes (int idJoueur, int victoire, state::State state) = 0;
    virtual int aiEchange (int idJoueur, state::State state) = 0;
    virtual void aiPlacerNouvellesArmees (int idJoueur, int nouvellesArmees, state::State state) = 0;
    virtual void aiDeplacerArmees (int idJoueur, state::State state) = 0;
    virtual void aiJouer (int numeroTour, int idJoueur, state::State state) = 0;
    // Setters and Getters
  };

};

#endif
