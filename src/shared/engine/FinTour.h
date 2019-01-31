// Generated by dia2code
#ifndef ENGINE__FINTOUR__H
#define ENGINE__FINTOUR__H


namespace state {
  class State;
};
namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class FinTour - 
  class FinTour : public engine::Commande {
    // Operations
  public:
    FinTour (int idJoueurCommande);
    virtual ~FinTour ();
    IdCommande const getIdCommande ();
    void writeToJson ();
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
