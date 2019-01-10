#include "ChoixPays.h"

namespace engine {

ChoixPays::ChoixPays (int idJoueur, std::string pays) : Commande(idJoueur), pays(pays){
}

ChoixPays::~ChoixPays (){
}

std::string ChoixPays::getPays(){
  return this->pays;
}

}
