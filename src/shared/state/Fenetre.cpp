#include "Fenetre.h"

namespace state {

Fenetre::Fenetre (int width, int height) : width(width), height(height){
}

int  Fenetre::getWidth (){
  return this->width;
}

int Fenetre::getHeight (){
  return this->height;
}

void Fenetre::resize (int width, int height){
  this->width = width;
  this->height = height;
}

}
