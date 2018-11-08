#include "ChoixPays.h"

#include <iostream>

namespace engine {

ChoixPays::~ChoixPays (){
}

IdCommande const ChoixPays::getIdCommande (){
  return CHOIXPAYS;
}

std::string ChoixPays::paysAttaquant (){
  std::cout << "Avec quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  return pays;
}

//bool ChoixPays::verifPaysAttaquant (){}

//std::string ChoixPays::paysAttaque (){}

//bool ChoixPays::verifPaysAttaque (){}

}
