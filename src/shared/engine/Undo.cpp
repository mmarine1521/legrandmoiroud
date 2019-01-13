#include "Undo.h"

namespace engine {

Undo::Undo(int idJoueurCommande) : Commande(idJoueurCommande){
}

Undo::~Undo (){
}

IdCommande const Undo::getIdCommande (){
  return UNDO_c;
}

}
