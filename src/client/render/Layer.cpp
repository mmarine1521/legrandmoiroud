#include "Layer.h"
#include "state.h"
#include "render.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "GridTileSet.h"

using namespace std ;

namespace render{

Layer::Layer(){
	this -> surface = std::unique_ptr<Surface>(new Surface());
}

Layer::~Layer(){
}

std::unique_ptr<Surface> const& Layer::getSurface (){
	return surface ;
}

void Layer::setSurface(Surface* surface){
	if(surface)
		this->surface.reset(surface);
	else
		this->surface = std::unique_ptr<Surface>(surface);
}

//void Layer::printText (int x, int y, const std::string& msg, size_t tileMinIdx, size_t tileMaxIdx){}

}
