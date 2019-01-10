#include "Commande.h"

namespace engine {

Commande::Commande(int idJoueur) idJoueur(idJoueur){
}

Commande::~Commande (){
}

int Commande::getIdJoueur(){
  return this->idJoueur;
}

IdCommande const Commande::getIdCommande (){
  return COMMANDE_c;
}

bool Commande::verif (state::State& state){
  return 0;
}

int Commande::getNumeroCarte (){
  return -1;
}

int Commande::getNbArmees (){
  return -1;
}

void Commande::setNbArmees (int nbArmees){
  return;
}

std::string Commande::getPays(){
  return "#pays";
}

int Commande::getNbDes (){
  return -1;
}

void Commande::exec(state::State& state){
}

void Commande::undo(state::State& state){
}

}
