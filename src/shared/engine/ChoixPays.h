// Generated by dia2code
#ifndef ENGINE__CHOIXPAYS__H
#define ENGINE__CHOIXPAYS__H

#include <string>

namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class ChoixPays - 
  class ChoixPays : public engine::Commande {
    // Operations
  public:
    virtual ~ChoixPays ();
    IdCommande const getIdCommande ();
    static std::string paysAttaquant ();
    static bool verifPaysAttaquant ();
    static std::string paysAttaque ();
    static bool verifPaysAttaquant ();
    // Setters and Getters
  };

};

#endif
