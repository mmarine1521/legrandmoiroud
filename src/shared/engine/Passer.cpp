#include "Passer.h"

namespace engine {

Passer::Passer(int idJoueurCommande) : Commande(idJoueurCommande){
}

Passer::~Passer (){
}

IdCommande const Passer::getIdCommande (){
  return PASSER_c;
}

}
