// Generated by dia2code
#ifndef AI__AI__H
#define AI__AI__H

#include <list>
#include <string>
#include <vector>

namespace engine {
  class Commande;
};
namespace state {
  class State;
};
namespace engine {
  class DeplacerArmees;
  class EchangeCartes;
  class Defausser;
  class IssueDuCombat;
  class DesAttaque;
  class DesAttaquant;
  class ChoixPaysAttaque;
  class ChoixPaysAttaquant;
  class PlacementArmees;
};
namespace state {
  class Carte;
};
namespace engine {
  class FinTour;
  class Undo;
  class Piocher;
  class Passer;
  class Distribution;
}

#include "state/State.h"
#include "engine/DeplacerArmees.h"
#include "engine/EchangeCartes.h"
#include "engine/Defausser.h"
#include "engine/IssueDuCombat.h"
#include "engine/DesAttaque.h"
#include "engine/DesAttaquant.h"
#include "engine/ChoixPaysAttaque.h"
#include "engine/ChoixPaysAttaquant.h"
#include "engine/PlacementArmees.h"
#include "state/Carte.h"
#include "engine/FinTour.h"
#include "engine/Undo.h"
#include "engine/Piocher.h"
#include "engine/Passer.h"
#include "engine/Distribution.h"
#include "engine/Commande.h"

namespace ai {

  /// class AI - 
  class AI {
    // Attributes
  private:
    int idJoueur;
    static std::list<engine::Commande*> commandes;
    static std::list<engine::Commande*> undos;
    static std::list<state::StepId> steps;
    // Operations
  public:
    int getIdJoueur ();
    static void pushCommande (engine::Commande* commande);
    virtual void aiPlacementArmees (state::State state) = 0;
    virtual void aiChoixPaysAttaquant (std::vector<std::string> blackList, state::State state) = 0;
    virtual void aiChoixPaysAttaque (state::State state) = 0;
    virtual void aiDesAttaquant (state::State state) = 0;
    virtual void aiDesAttaque (state::State state) = 0;
    virtual void aiDefausser (state::State state) = 0;
    virtual void aiEchange (state::State state) = 0;
    virtual void aiDeplacerArmees (state::State state) = 0;
    void aiRemplirCommandes (state::State state);
    // Setters and Getters
  };

};

#endif
