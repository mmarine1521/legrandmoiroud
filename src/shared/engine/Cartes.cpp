#include "Cartes.h"

namespace engine {

Cartes::Cartes(int idJoueurCommande) : Commande(idJoueurCommande){
}

Cartes::Cartes(int idJoueurCommande, int numeroCarte) : Commande(idJoueurCommande), numeroCarte(numeroCarte){
}

int Cartes::getNumeroCarte (){
  return this->numeroCarte;
}

}
