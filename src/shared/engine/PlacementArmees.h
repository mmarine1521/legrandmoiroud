// Generated by dia2code
#ifndef ENGINE__PLACEMENTARMEES__H
#define ENGINE__PLACEMENTARMEES__H

#include <string>

namespace state {
  class State;
};
namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class PlacementArmees - 
  class PlacementArmees : public engine::Commande {
    // Attributes
  private:
    std::string pays;
    int nbArmees;
    // Operations
  public:
    PlacementArmees ();
    PlacementArmees (std::string pays, int nbArmees);
    virtual ~PlacementArmees ();
    IdCommande const getIdCommande ();
    int getNbArmees ();
    void setNbArmees (int nbArmees);
    bool verif (state::State& state);
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
