#include "Position.h"

namespace state {

Position::Position (){
}

Position::Position (int x, int y) : x(x), y(y){
}

int Position::getX (){
  return this->x;
}

void Position::setX (int x){
  this->x = x;
}

int Position::getY (){
  return this->y;
}

void Position::setY (int y){
  this->y = y;
}

bool operator==(Position a, Position b){
  if (a.getX() == b.getX() && a.getY() == b.getY()){
    return true;
  }
  else{
    return false;
  }
}

}
