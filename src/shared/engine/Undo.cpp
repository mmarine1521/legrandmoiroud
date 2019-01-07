#include "Undo.h"

namespace engine {

Undo::Undo()
{
}

Undo::~Undo (){
}

IdCommande const Undo::getIdCommande (){
  return UNDO_c;
}

}
