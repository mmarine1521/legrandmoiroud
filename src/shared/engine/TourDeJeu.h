// Generated by dia2code
#ifndef ENGINE__TOURDEJEU__H
#define ENGINE__TOURDEJEU__H

#include <list>
#include <string>

namespace engine {
  class Commande;
};
namespace state {
  class State;
};
namespace engine {
  class Undo;
  class CommandeComposite;
  class Passer;
  class FinTour;
  class Defausser;
  class Piocher;
  class DesAttaquant;
  class DesAttaque;
  class Distribution;
  class DeplacerArmees;
  class ChoixPaysAttaquant;
  class PlacementArmees;
  class ChoixPaysAttaque;
  class EchangeCartes;
  class IssueDuCombat;
}

#include "Undo.h"
#include "CommandeComposite.h"
#include "Passer.h"
#include "FinTour.h"
#include "Defausser.h"
#include "Piocher.h"
#include "DesAttaquant.h"
#include "DesAttaque.h"
#include "Distribution.h"
#include "DeplacerArmees.h"
#include "ChoixPaysAttaquant.h"
#include "PlacementArmees.h"
#include "ChoixPaysAttaque.h"
#include "EchangeCartes.h"
#include "IssueDuCombat.h"

namespace engine {

  /// class TourDeJeu - 
  class TourDeJeu {
    // Associations
    // Attributes
  private:
    static std::list<Commande*> commandes;
    static std::list<Commande*> undos;
    static std::list<state::StepId> steps;
    // Operations
  public:
    TourDeJeu ();
    virtual ~TourDeJeu ();
    static int getSizeUndos ();
    static void pushCommande (Commande* commande);
    static void placementJoueur3 (state::State& state);
    static void run (state::State& state);
    static void pushCommandeFichier (std::string fichier);
    // Setters and Getters
  };

};

#endif
