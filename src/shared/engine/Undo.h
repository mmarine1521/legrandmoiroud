// Generated by dia2code
#ifndef ENGINE__UNDO__H
#define ENGINE__UNDO__H


namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class Undo - 
  class Undo : public engine::Commande {
    // Operations
  public:
    Undo ();
    virtual ~Undo ();
    IdCommande const getIdCommande ();
    // Setters and Getters
  };

};

#endif
