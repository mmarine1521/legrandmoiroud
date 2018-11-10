// Generated by dia2code
#ifndef ENGINE__ATTRIBUTIONTERRITOIRES__H
#define ENGINE__ATTRIBUTIONTERRITOIRES__H


namespace state {
  class State;
};
namespace engine {
  class Commande;
}

#include "state/State.h"
#include "Commande.h"

namespace engine {

  /// class AttributionTerritoires - 
  class AttributionTerritoires : public engine::Commande {
    // Operations
  public:
    virtual ~AttributionTerritoires ();
    IdCommande const getIdCommande ();
    static void distribution (state::State state, int nbJoueurs = 3);
    static bool repartitionArmees (int idJoueur);
    // Setters and Getters
  };

};

#endif
