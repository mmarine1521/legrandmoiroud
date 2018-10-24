#include "Surface.h"
#include <iostream>

namespace render {

void Surface::loadTexture (const std::string& image_file)
{
	if (!this->texture.loadFromFile(image_file))
	{
	    std::cout << "Erreur de chargement" << std::endl ;
	}
}
/*
void initQuads (int count);
void  setSpriteLocation (int i, int x, int y);
void setSpriteTexture (int i, const Tile& tex);
void const draw (sf::RenderTarget& target, sf::RenderStates states);
*/
}
