#include "Des.h"

#include <iostream>
#include <cstdlib> // rand
#include <algorithm> // sort

namespace engine {

Des::Des()
{
}
Des::Des (int nbDes) : nbDes(nbDes){
}

Des::~Des (){
}

IdCommande const Des::getIdCommande (){
  return NB_DES_c;
}

int Des::getNbDes(){
  return this->nbDes;
}

std::vector<int> Des::lancerDes (int nbDes){
  std::vector<int> liste(nbDes);
  int nb = 0;

  for (int i=0; i<nbDes; i++){
    nb = (rand() % 6) + 1; //nb aleatoire de 1 à 6
    liste[i] = nb;
  }
  std::sort(liste.begin(), liste.end());
  return liste;
}

}
