#include "Passer.h"

namespace engine {

Passer::Passer(int idJoueurCommande, bool fin) : Commande(idJoueurCommande), fin(fin){
} // si fin = 0, passer normal. Si fin = 1, fin du tour de jeu.

Passer::~Passer (){
}

IdCommande const Passer::getIdCommande (){
  return PASSER_c;
}

bool Passer::getFin(){
  return this->fin;
}

}
