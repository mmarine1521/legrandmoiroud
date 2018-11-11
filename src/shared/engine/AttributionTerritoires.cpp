#include "AttributionTerritoires.h"

namespace engine {

AttributionTerritoires::~AttributionTerritoires (){
}

IdCommande const AttributionTerritoires::getIdCommande (){
  return ATTRIBUTERR;
}

void AttributionTerritoires::distribution (state::State state, int nbJoueurs){}

//bool AttributionTerritoires::repartitionArmees (int idJoueur){}

}
