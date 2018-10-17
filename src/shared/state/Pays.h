// Generated by dia2code
#ifndef STATE__PAYS__H
#define STATE__PAYS__H

#include <vector>

namespace state {
  class Pays;
  class Continent;
}

#include "ContinentId.h"
#include "Continent.h"

namespace state {

  /// class Pays - 
  class Pays {
    // Associations
    // Attributes
  private:
    int idPays;
    std::vector<Pays> paysFrontaliers;
    ContinentId idContinent;
    // Operations
  public:
    Pays ();
    Pays (int idPays, ContinentId continent);
    int getIdPays ();
    std::vector<Pays> getPaysFrontaliers ();
    ContinentId getContinent ();
    void setPaysFrontaliers (std::vector<Pays> paysFrontaliers);
    // Setters and Getters
  };

};

#endif
