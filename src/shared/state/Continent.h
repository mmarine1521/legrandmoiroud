// Generated by dia2code
#ifndef STATE__CONTINENT__H
#define STATE__CONTINENT__H

#include <vector>

namespace state {
  class Pays;
  class StaticElement;
}

#include "Pays.h"
#include "ContinentId.h"
#include "CouleurId.h"
#include "StaticElement.h"

namespace state {

  /// class Continent - 
  class Continent : public state::StaticElement {
    // Associations
    state::ContinentId continentId;
    state::CouleurId couleurId;
    // Attributes
  private:
    std::vector<Pays> const listePays;
    // Operations
  public:
    Continent (std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId);
    ~Continent ();
    TypeId const getTypeId ();
    ContinentId const getContinentId ();
    CouleurId const getCouleurId ();
    std::vector<Pays> getListePays ();
    // Setters and Getters
    void setContinentId(ContinentId continentId);
    void setCouleurId(CouleurId couleurId);
  };

};

#endif
