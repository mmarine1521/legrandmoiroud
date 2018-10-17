// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


namespace state {
  class Fenetre;
  class Position;
}

#include "TypeId.h"
#include "Fenetre.h"
#include "Position.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    state::Fenetre element;
    state::TypeId typeId;
    state::Position position;
    // Operations
  public:
    Element ();
    ~Element ();
    TypeId getTypeId ();
    void setPosition (int x, int y);
    // Setters and Getters
    const Fenetre& getElement() const;
    void setElement(const Fenetre& element);
    void setTypeId(TypeId typeId);
    const Position& getPosition() const;
  };

};

#endif
