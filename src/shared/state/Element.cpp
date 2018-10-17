#include "Element.h"

namespace state {

Element::Element (){
}

Element::~Element (){
}

Position Element::getPosition (){
  return this->position;
}

void Element::setPosition (int x, int y){
  this->position.setX(x);
  this->position.setY(y);
}

}
