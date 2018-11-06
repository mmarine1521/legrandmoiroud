#include <iostream>
#include "Element.h"

namespace state {

Element::Element (){
	position=0;
	position = new Position() ;

}

Element::~Element (){
	delete position ;
	position = 0;
}

Position Element::getPosition (){
  return this-> *position;
}

void Element::setPosition (int x, int y){
  this->*position.setX(x);
  this->*position.setY(y);
}

}
