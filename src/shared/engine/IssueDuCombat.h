// Generated by dia2code
#ifndef ENGINE__ISSUEDUCOMBAT__H
#define ENGINE__ISSUEDUCOMBAT__H


namespace state {
  class State;
};
namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class IssueDuCombat - 
  class IssueDuCombat : public engine::Commande {
    // Attributes
  private:
    int victoire;
    // Operations
  public:
    IssueDuCombat (int idJoueurCommande, int victoire);
    virtual ~IssueDuCombat ();
    static int nbCartesJoueur (state::State& state);
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
