#include <iostream>
#include "Element.h"

namespace state {

Element::Element (){
}

Element::~Element (){
}

Position Element::getPosition (){
  return this->position;
}

void Element::setPosition (Position position){
  this->position = position;
}

}
