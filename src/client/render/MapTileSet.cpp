#include "MapTileSet.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace render{

MapTileSet::MapTileSet(){
	map = std::vector<Tile>();
	map.push_back(Tile(71,81,102,122));
	map.push_back(Tile(191,81,102,122));
}

MapTileSet::~MapTileSet(){
}

int const MapTileSet::getCellWidth(){
	if(map.size()!=0){
		return this->map[0].getWidth() ; //changer nombre
	}
	else{
		return -1 ;
	}
}

int const MapTileSet::getCellHeight(){
	if(map.size()!=0){
		return this->map[0].getHeight() ; //changer nombre
	}
	else{
		return -1 ;
	}
}

std::string MapTileSet::getImageFile (const state::Element& e) const{
	return "res/MapJeu2.png"; //changer image
}

const Tile& MapTileSet::getTile (char c) const{
  //arrangé pour compilation, ne signifie rien
  if (c=='c'){
    return *(new Tile(0,0,100,100));
	}
  else{
    return *(new Tile());
	}
}

}
