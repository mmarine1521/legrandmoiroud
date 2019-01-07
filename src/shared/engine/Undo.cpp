#include "Undo.h"

namespace engine {

Undo::~Undo (){
}

IdCommande const Undo::getIdCommande (){
  return UNDO_c;
}

}
