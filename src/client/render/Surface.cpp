#include "Surface.h"
#include <iostream>

namespace render {

void Surface::loadTexture (const std::string& image_file)
{
	sf::Texture texture;
	if (!texture.loadFromFile("image.png"))
	{
	    std::cout << "Erreur de chargement"<< std::endl ; 
	}
}
void Surface::initQuads (int count)
{
	//création d'un nombre de quads/sprites égal au nombre de cellule dans la grille
	quads.setPrimitiveType(sf::Quads);
	quads.resize(4*count); //count = nombre de sprites.
}
void  setSpriteLocation (int i, int x, int y);
void setSpriteTexture (int i, const Tile& tex);
void const draw (sf::RenderTarget& target, sf::RenderStates states);

}
