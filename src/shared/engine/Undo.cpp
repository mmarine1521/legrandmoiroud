#include "Undo.h"

namespace engine {

Undo::Undo(int idJoueur) : Commande(idJoueur){
}

Undo::~Undo (){
}

IdCommande const Undo::getIdCommande (){
  return UNDO_c;
}

}
