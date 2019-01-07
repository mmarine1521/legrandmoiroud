#include "Commande.h"

namespace engine {

Commande::~Commande (){
}

IdCommande const Commande::getIdCommande (){
  return COMMANDE_c;
}

bool Commande::verif (state::State state){
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

}
