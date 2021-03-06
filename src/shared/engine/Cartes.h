// Generated by dia2code
#ifndef ENGINE__CARTES__H
#define ENGINE__CARTES__H


namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class Cartes - 
  class Cartes : public engine::Commande {
    // Attributes
  protected:
    int numeroCarte;
    // Operations
  public:
    Cartes (int idJoueurCommande);
    Cartes (int idJoueurCommande, int numeroCarte);
    int getNumeroCarte ();
    // Setters and Getters
    void setNumeroCarte(int numeroCarte);
  };

};

#endif
