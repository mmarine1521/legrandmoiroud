#include "MapTileSet.h"

namespace render{

MapTileSet::MapTileSet(){
}

int const MapTileSet::getCellWidth(){
	return 768 ; //changer nombre
}

int const MapTileSet::getCellHeight(){
	return 864 ; //changer nombre
}

const std::string MapTileSet::getImageFile() const{
	return "res/tank384px.png"; //changer image
}

}
