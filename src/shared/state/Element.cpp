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

void Element::setIdJoueur (int idJoueur){
}

void Element::setNombre (int nombre){
}

std::vector<std::string> const Element::getPaysFrontaliers(){
  std::vector<std::string> liste;
  liste.push_back("#pays");
  return liste;
}

int Element::getNumero(){
  return -1;
}

CarteForce Element::getCarteForce() const{
  return NONIDENTIFIE;
}

}
