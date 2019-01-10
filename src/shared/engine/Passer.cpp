#include "Passer.h"

namespace engine {

Passer::Passer(int idJoueur) : Commande(idJoueur){
}

Passer::~Passer (){
}

IdCommande const Passer::getIdCommande (){
  return PASSER_c;
}

}
