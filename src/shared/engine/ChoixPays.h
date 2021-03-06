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
    // Attributes
  protected:
    /// 									
    std::string pays;
    // Operations
  public:
    ChoixPays (int idJoueurCommande, std::string pays);
    virtual ~ChoixPays ();
    std::string getPays ();
    // Setters and Getters
    void setPays(const std::string& pays);
  };

};

#endif
