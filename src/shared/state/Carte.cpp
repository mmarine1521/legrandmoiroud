#include "Carte.h"

namespace state {

Carte::Carte (int numero , CarteForce carteForce) : carteForce(carteForce), numero(numero){
  carteId = PIOCHE;
}

Carte::~Carte (){
}

bool const Carte::isCarte (){
  return true;
}

TypeId const Carte::getTypeId (){
  return CARTE;
}

CarteId Carte::getCarteId (){
  return this->carteId;
}

void Carte::setCarteId (CarteId carteId){
  this->carteId = carteId;
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

Carte Carte::clone (){
  Carte newCarte(numero, carteForce);
  newCarte.carteId = carteId;
  newCarte.idJoueur = idJoueur;
  return newCarte;
}

}
