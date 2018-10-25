#include "Layer.h"
//#include "GridTileSet.h"

namespace render{

Layer::Layer(){
	this-> surface = std::unique_ptr<Surface>(new Surface());;
	this-> tileset = nullptr;
}

Layer::~Layer(){
}

const Surface* Layer::getSurface() const{
	return &(*(this->surface));
}

void Layer::setSurface(Surface* surface){
	*(this->surface)= *surface ;
}

//void Layer::printText (int x, int y, const std::string& msg, size_t tileMinIdx, size_t tileMaxIdx){}

}
