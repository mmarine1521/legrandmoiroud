#include "ElementTabLayer.h"
#include "Layer.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state.h"
#include "TileSet.h"
#include <memory>
#include "Surface.h"
#include "Tile.h"

using namespace std ;

namespace render {

ElementTabLayer::ElementTabLayer (const state::ElementTab& tab ) : tab(tab){
	std::vector<state::Element*> list = tab.getElementList();
//	if (list[0]->getTypeId()==3)//armee
//	{
//		tileset.reset(new ArmeeTileSet);
//	}
//	else if(list[0]->getTypeId()==4)//carte
//	{
//		tileset.reset(new CarteTileSet);
//	}
}

void ElementTabLayer::initSurface()
{
	std::vector<state::Element*> list = tab.getElementList() ;
	surface = std::unique_ptr<Surface>(new Surface());
	surface->initQuads(list.size());
	surface->loadTexture(tileset->getImageFile());

	//Boucle sur l'ensemble des éléments d'un ElementTab
	    for(int i=0; i<list.size(); i++)
	    {
	        state::Element& e=*list[i];
	        const Tile& t=tileset->getTile(e);
	        TileSet& tileSet2= *tileset;

	        //Cas d'une armee
	        if(e.getTypeId()==3)
	        {
	        	float abs=(e.getPosition().getX()/t.getWidth())*(149/1.25);
	        	float ord=(e.getPosition().getY()/t.getHeight())*(149/1.25);

	        	surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2,tab);
	        }
	        //Cas d'une carte
	        if(e.getTypeId()==4)
	        {
	        	float abs=(e.getPosition().getX()/t.getWidth())*(149/1.25);
	        	float ord=(e.getPosition().getY()/t.getHeight())*(149/1.25);
	        	surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2,tab);
	        }
	    }
}

}
