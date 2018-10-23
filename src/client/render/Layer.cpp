#include "Layer.h"
//#include "GridTileSet.h"

namespace render
{

Layer::Layer()
{
	this-> surface = std::unique_ptr<Surface>(new Surface());
	this-> tileset = nullptr; 
}

const Surface* Layer::getSurface() const
{
	return &(*(this->surface)); 
}
void Layer::setSurface(Surface* surface)
{
	*(this->surface)= *surface ;
}

Layer::~Layer(){
	
}



}
