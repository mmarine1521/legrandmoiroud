// Generated by dia2code
#ifndef STATE__PAYS__H
#define STATE__PAYS__H

#include <string>
#include <vector>
#include <iostream>

namespace state {
  class Pays;
  class StaticElement;
}

#include "ContinentId.h"
#include "StaticElement.h"

namespace state {

  /// class Pays - 
  class Pays : public state::StaticElement {
    // Attributes
  public:
    ContinentId continentId;
  private:
    std::string nomPays;
    int paysId;
    std::vector<Pays> paysFrontaliers;
    // Operations
  public:
    Pays ();
    Pays (std::string nomPays, int paysId, ContinentId continentId);
    virtual ~Pays ();
    TypeId const getTypeId ();
    std::string const getNomPays ();
    int const getPaysId ();
    ContinentId const getContinentId ();
    std::vector<Pays> const getPaysFrontaliers ();
    void setPaysFrontaliers (std::vector<Pays> paysFrontaliers);
    friend std::ostream& operator<< (std::ostream& flux, Pays const& pays);
    // Setters and Getters
  };

};

#endif
