#include "Armee.h"

namespace state {

Armee::Armee (int idJoueur) : idJoueur (idJoueur){
}

Armee::~Armee (){
}

bool Armee::isCarte (){
  return false;
}

//void armeeRules (ArmeeStatus armeeStatus){}

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

Pays Armee::getPays (){
  return this->pays;
}
void Armee::setPays (Pays pays){
  this->pays = pays;
}

ArmeeStatus Armee::getArmeeStatus(){
  return this->armeeStatus;
}
void Armee::setArmeeStatus(ArmeeStatus armeeStatus){
  this->armeeStatus = armeeStatus;
}

}
