// Generated by dia2code
#ifndef ENGINE__COMBAT__H
#define ENGINE__COMBAT__H

#include <vector>

namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class Combat - 
  class Combat : public engine::Commande {
    // Operations
  public:
    virtual ~Combat ();
    IdCommande const getIdCommande ();
    static int nbAttaques ();
    static bool verifNbAttaques ();
    static int nbDefenses ();
    static bool verifNbDefenses ();
    static std::vector<int> lancerDes (int nbDes);
    // Setters and Getters
  };

};

#endif
