#include "ChoixPays.h"

namespace engine {

ChoixPays::ChoixPays()
{
}
ChoixPays::ChoixPays (std::string pays) : pays(pays){
}

ChoixPays::~ChoixPays (){
}


IdCommande const ChoixPays::getIdCommande (){
  return CHOIX_PAYS_c;
}

std::string ChoixPays::getPays(){
  return this->pays;
}
}

