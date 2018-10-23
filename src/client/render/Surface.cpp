#include "Surface.h"

namespace render {

void loadTexture (const std::string& image_file)
{
	sf::Texture texture;
	if (!texture.loadFromFile("image.png"))
	{
	    std::cout << "Erreur de chargement"<< std::endl ; 
	}
}
void initQuads (int count);
void  setSpriteLocation (int i, int x, int y);
void setSpriteTexture (int i, const Tile& tex);
void const draw (sf::RenderTarget& target, sf::RenderStates states);

}