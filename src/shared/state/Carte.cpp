#include "Carte.h"

namespace state {

Carte::Carte (int numero , Pays pays, CarteForce carteForce) : carteForce(carteForce), numero(numero), pays(pays){
}

Carte::~Carte (){
}

bool const Carte::isCarte (){
  return true;
}

//void Carte::carteRules (CarteId carteId){}

TypeId const Carte::getTypeId (){
  return CARTE;
}

CarteId Carte::getCarteId (){
  return this->carteId;
}

void Carte::setCarteId (CarteId carteId){
  this->carteId = carteId;
}

CarteForce Carte::getCarteForce (){
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

Pays Carte::getPays (){
  return this->pays;
}

}
