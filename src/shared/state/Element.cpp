#include "Element.h"

namespace state {

Element::Element (){
}

Element::~Element (){
}

TypeId const Element::getTypeId (){
  return NON_RENSEIGNE;
}

bool const Element::isStatic (){
  return false;
}

Position Element::getPosition (){
  return this->position;
}

void Element::setPosition (int x, int y){
  this->position.setX(x);
  this->position.setY(y);
}

}
