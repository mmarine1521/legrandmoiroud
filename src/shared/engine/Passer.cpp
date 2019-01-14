#include "Passer.h"

namespace engine {

Passer::Passer(int idJoueurCommande, bool fin) : Commande(idJoueurCommande), fin(fin){
}

Passer::~Passer (){
}

IdCommande const Passer::getIdCommande (){
  return PASSER_c;
}

bool Passer::getFin(){
  return this->fin;
}

}
