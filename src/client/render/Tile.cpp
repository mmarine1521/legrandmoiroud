#include "Tile.h"

#include <stdio.h>
#include <SFML/Graphics.hpp>

namespace render {

Tile::Tile (){
	x=0 ;
	y=0;
	this->width=16 ;
	this->height=16;
}

Tile::Tile (int x, int y, int w, int h){
	this->x=x ;
	this-> y=y ;
	this-> width = w ;
	this -> height = h;
}

int Tile::getHeight  () const{
	return this->height ;
}

int Tile::getWidth () const{
	return this->width ;
}

int Tile::getX () const{
  return this->x ;
}

int Tile::getY () const{
  return this->y ;
}

void Tile::setHeight (int height){
  this -> height = height ;
}

void Tile::setWidth (int width){
  this -> height = height ;
}

void Tile::setX (int x){
  this -> x=x ;
}

void Tile::setY (int y){
  this -> y=y ;
}

}
