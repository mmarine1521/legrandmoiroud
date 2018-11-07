#include "StateLayer.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std ;

namespace render {

StateLayer::StateLayer(const state::State& state) : state(state){
	this->tileset = std::unique_ptr<MapTileSet>(nullptr);
	this->surface = std::unique_ptr<Surface>(new Surface());
}

void StateLayer::initSurface(){
	cout << "Entrée dans StateLayer::initSurface"<<endl ;
	//affichage du fond d'écran
	this->surface->loadTexture("res/MapJeu2.png");
}

}
