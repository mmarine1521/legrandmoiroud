// Generated by dia2code
#ifndef ENGINE__DISTRIBUTION__H
#define ENGINE__DISTRIBUTION__H


namespace state {
  class State;
};
namespace engine {
  class Commande;
}

#include "state/State.h"
#include "Commande.h"

namespace engine {

  /// class Distribution - 
  class Distribution : public engine::Commande {
    // Operations
  public:
    virtual ~Distribution ();
    IdCommande const getIdCommande ();
    void exec (state::State state);
    void undo (state::State state);
    // Setters and Getters
  };

};

#endif
