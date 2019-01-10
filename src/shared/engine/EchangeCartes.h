// Generated by dia2code
#ifndef ENGINE__ECHANGECARTES__H
#define ENGINE__ECHANGECARTES__H


namespace state {
  class State;
};
namespace engine {
  class Commande;
};
namespace state {
  class Carte;
};
namespace engine {
  class Defausser;
}

#include "Commande.h"
#include "state/Carte.h"
#include "Defausser.h"

namespace engine {

  /// class EchangeCartes - 
  class EchangeCartes : public engine::Commande {
    // Associations
    // Attributes
  private:
    int numeroCarte;
    // Operations
  public:
    EchangeCartes (int idJoueur, int numeroCarte);
    virtual ~EchangeCartes ();
    IdCommande const getIdCommande ();
    bool verif (state::State& state);
    static int gain (state::State& state);
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
