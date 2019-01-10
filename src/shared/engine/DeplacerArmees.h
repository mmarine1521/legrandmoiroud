// Generated by dia2code
#ifndef ENGINE__DEPLACERARMEES__H
#define ENGINE__DEPLACERARMEES__H

#include <string>

namespace state {
  class State;
};
namespace engine {
  class Commande;
  class ChoixPaysAttaque;
}

#include "Commande.h"
#include "ChoixPaysAttaque.h"

namespace engine {

  /// class DeplacerArmees - 
  class DeplacerArmees : public engine::Commande {
    // Associations
    // Attributes
  private:
    std::string paysDepart;
    std::string paysArrivee;
    int nbArmees;
    // Operations
  public:
    DeplacerArmees (int idJoueur, std::string paysDepart, std::string paysArrivee, int nbArmees);
    virtual ~DeplacerArmees ();
    IdCommande const getIdCommande ();
    bool verif (state::State& state);
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
