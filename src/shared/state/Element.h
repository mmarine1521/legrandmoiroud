// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include <memory>
#include <string>

namespace state {
  class Position;
}

#include "Position.h"
#include "TypeId.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    state::TypeId typeId;
    // Attributes
  private:
    Position position;
    // Operations
  public:
    Element ();
    virtual ~Element ();
    virtual TypeId const getTypeId () = 0;
    virtual bool const isStatic () = 0;
    Position getPosition ();
    void setPosition (Position position);
    virtual std::unique_ptr<Element> clone () = 0;
    virtual std::string getPays () = 0;
    virtual int getNombre () = 0;
    virtual int getIdJoueur () = 0;
    // Setters and Getters
    void setTypeId(TypeId typeId);
  };

};

#endif
