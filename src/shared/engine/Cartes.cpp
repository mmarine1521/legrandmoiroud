#include "Cartes.h"

namespace engine {

Cartes::Cartes (int numeroCarte) : numeroCarte(numeroCarte){
}

int Cartes::getNumeroCarte (){
  return this->numeroCarte;
}

}
