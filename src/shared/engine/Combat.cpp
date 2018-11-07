#include "Combat.h"

#include <cstdlib> // rand
#include <algorithm> // sort

namespace engine {

Combat::~Combat (){
}

//IdCommande const Combat::getIdCommande (){}

//int Combat::nbAttaques (){}

//bool Combat::verifNbAttaques (){}

//int Combat::nbDefenses (){}

//bool Combat::verifNbDefenses (){}

std::vector<int> Combat::lancerDes (int nbDes){
  std::vector<int> liste(nbDes);
  int nb;
  srand (time(NULL));
  for (int i=0; i<nbDes; i++){
    nb = rand() % 6 + 1; //nb aleatoire de 1 à 6
    liste[i] = nb;
  }
   std::sort (liste.begin(), liste.end());
   return liste;
}

}
