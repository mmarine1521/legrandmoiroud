#include "Layer.h"

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

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
	if(surface){
		this->surface.reset(surface);
	}
	else{
		this->surface = std::unique_ptr<Surface>(surface);
	}
}

}
