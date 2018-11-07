#include "Surface.h"

#include <iostream>

namespace render {

Surface::Surface(){
}

void Surface::loadTexture (const std::string& image_file){
	if (!this->texture.loadFromFile("./res/"+image_file)){
	    std::cout << "Erreur de chargement texture surface"<< std::endl ;
	}
}

void Surface::initQuads (int count){
	//création d'un nombre de quads/sprites égal au nombre de cellule dans la grille
	quads.setPrimitiveType(sf::Quads);
	quads.resize(4*count); //count = nombre de sprites.
}

void  Surface::setSpriteLocation (int i, int x, int y){
	//fixe les coordonnées des 4 coins du carré où la tuile est dessinée
	//tuile 16*16

	sf::Vertex* quad = &quads[4*1];
	quad[0].position = sf::Vector2f(x*96, y*96);
	quad[0].position = sf::Vector2f((x+1)*96, y*96);
	quad[0].position = sf::Vector2f((x+1)*96, (y+1)*96);
	quad[0].position = sf::Vector2f(x*96, (y+1)*96);
}

void Surface::setSpriteTexture (int i, const Tile& tex){
	sf::Vertex* quad = &quads[4*i];

	quad[0].texCoords = sf::Vector2f(tex.getX(), tex.getY());
	quad[1].texCoords = sf::Vector2f(tex.getX()+tex.getWidth(), tex.getY());
	quad[2].texCoords = sf::Vector2f(tex.getX()+tex.getWidth(), tex.getY()+ tex.getHeight());
	quad[3].texCoords = sf::Vector2f(tex.getX(), tex.getY()+tex.getHeight());
}

void Surface::draw (sf::RenderTarget& target, sf::RenderStates states) const {
	states.texture = &this->texture;
	target.draw(this->quads, states);
}

}
