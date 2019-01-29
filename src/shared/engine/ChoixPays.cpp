#include "ChoixPays.h"

namespace engine {

ChoixPays::ChoixPays (int idJoueurCommande, std::string pays) : Commande(idJoueurCommande), pays(pays){
}

ChoixPays::~ChoixPays (){
}

std::string ChoixPays::getPays(){
  return this->pays;
}

}
