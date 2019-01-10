#include "Cartes.h"

namespace engine {

Cartes::Cartes(int idJoueur) : Commande(idJoueur){
}


Cartes::Cartes(int idJoueur, int numeroCarte) : Commande(idJoueur), numeroCarte(numeroCarte){
}

int Cartes::getNumeroCarte (){
  return this->numeroCarte;
}

}
