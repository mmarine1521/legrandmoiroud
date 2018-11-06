// Generated by dia2code
#ifndef ENGINE__ATTRIBUTIONTERRITOIRES__H
#define ENGINE__ATTRIBUTIONTERRITOIRES__H

#include <string>
#include <map>

namespace engine {
  class Commande;
};
namespace state {
  class Pays;
}

#include "Commande.h"
#include "state/Pays.h"

namespace engine {

  /// class AttributionTerritoires - 
  class AttributionTerritoires : public engine::Commande {
    // Operations
  public:
    virtual ~AttributionTerritoires ();
    IdCommande const getIdCommande ();
    static void distribution (int nbJoueurs = 3, std::map<std::string, state::Pays> mapPays);
    static bool repartitionArmees (int idJoueur);
    // Setters and Getters
  };

};

#endif
