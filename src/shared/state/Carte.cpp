#include "Carte.h"

namespace state {

Carte::Carte (int numero , CarteForce carteForce) : carteForce(carteForce), numero(numero){
}

Carte::~Carte (){
}

TypeId const Carte::getTypeId (){
  return CARTE;
}

CarteForce Carte::getCarteForce () const{
  return this->carteForce;
}

int Carte::getIdJoueur (){
  return this->idJoueur;
}

void Carte::setIdJoueur (int idJoueur){
  this->idJoueur = idJoueur;
}

int Carte::getNumero (){
  return this->numero;
}

std::shared_ptr<Element> Carte::clone (){
  return std::shared_ptr<Element>(new Carte(*this));
}

}
