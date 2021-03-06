// Generated by dia2code
#ifndef ENGINE__ECHANGECARTES__H
#define ENGINE__ECHANGECARTES__H


namespace state {
  class State;
};
namespace engine {
  class Commande;
  class Defausser;
}

#include "Commande.h"
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
    EchangeCartes (int idJoueurCommande, int numeroCarte);
    virtual ~EchangeCartes ();
    IdCommande const getIdCommande ();
    void writeToJson ();
    bool verif (state::State& state);
    static int gain (state::State& state);
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
