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

int Element::getIdJoueur (){
  return -1;
}

int Element::getNombre (){
  return -1;
}

std::string Element::getPays (){
  return "#pays";
}

}
