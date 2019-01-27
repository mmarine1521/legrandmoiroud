#include "Armee.h"

namespace state {

Armee::Armee (std::string pays) : pays (pays){
  idJoueur = 0;
  nombre = 0;
}

Armee::~Armee (){
}

TypeId const Armee::getTypeId (){
  return ARMEE;
}

int Armee::getIdJoueur (){
  return this->idJoueur;
}

void Armee::setIdJoueur (int idJoueur){
  this->idJoueur = idJoueur;
}

int Armee::getNombre (){
  return this->nombre;
}

void Armee::setNombre (int nombre){
  this->nombre = nombre;
}

std::string Armee::getPays (){
  return this->pays;
}

std::shared_ptr<Element> Armee::clone (){
  return std::shared_ptr<Element>(new Armee(*this));
}

}
