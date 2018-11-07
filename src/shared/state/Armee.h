// Generated by dia2code
#ifndef STATE__ARMEE__H
#define STATE__ARMEE__H

#include <string>

namespace state {
  class Armee;
  class MobileElement;
}

#include "MobileElement.h"

namespace state {

  /// class Armee - 
  class Armee : public state::MobileElement {
    // Attributes
  private:
    int idJoueur;
    int nombre;
    std::string pays;
    // Operations
  public:
    Armee (std::string pays);
    virtual ~Armee ();
    bool const isCarte ();
    TypeId const getTypeId ();
    int getIdJoueur ();
    void setIdJoueur (int idJoueur);
    int getNombre ();
    void setNombre (int nombre);
    std::string getPays ();
    Armee clone ();
    // Setters and Getters
  };

};

#endif
