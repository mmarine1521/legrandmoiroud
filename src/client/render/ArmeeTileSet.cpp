#include "ArmeeTileSet.h"

#include <stdio.h>
#include <SFML/Graphics.hpp>

namespace render {

ArmeeTileSet::ArmeeTileSet ()
{

}
// {
//	 for (int i=0; i<10; i++)
//	 {
//		 for(int i=0; i<10 ; i++)
//			 unit.push_back(Tile(j*96, i*96, 96,96));
//	 }}

ArmeeTileSet::~ArmeeTileSet ()
{

}
std::string ArmeeTileSet::getImageFile(const state::Armee& e) const
{

	return "res/pions.png" ;
}




int const ArmeeTileSet::getCellWidth ()
{
	return 60 ;
}

int const ArmeeTileSet::getCellHeight ()
{
	return 60 ;
}

const Tile& ArmeeTileSet::getTile (const state::Armee& e)
{
	Tile& s= armee[0];
	s= armee[0];
	return s;
}

}
