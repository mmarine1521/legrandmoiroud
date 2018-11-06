#include <stdio.h>
#include "CarteTileSet.h"
#include "state.h"
#include "render.h"
#include "state/Element.h"
#include <SFML/Graphics.hpp>

namespace render {

CarteTileSet::CarteTileSet ()
{
	for(int i=0; i<4 ; i++)
	{
		for(int j=0; j<3; j++)
		{
			Tile t(i*400, j*600, 370, 680);
			canon.push_back(t);
		}
	}
	for(int i=0; i<4 ; i++)
		{
			for(int j=0; j<3; j++)
			{
				Tile t_2(i*400, j*600, 370, 680);
				tank.push_back(t_2);
			}
		}
	for(int i=0; i<4 ; i++)
		{
			for(int j=0; j<3; j++)
			{
				Tile t_3(i*400, j*600, 370, 680);
				soldat.push_back(t_3);
			}
		}

}
// {
//	 for (int i=0; i<10; i++)
//	 {
//		 for(int i=0; i<10 ; i++)
//			 unit.push_back(Tile(j*96, i*96, 96,96));
//	 }}

CarteTileSet::~CarteTileSet ()
{

}
std::string CarteTileSet::getImageFile(const state::Element& e) const
{
	std::string a = "" ;

		if (e.getCarteForce() == 0) //tank
		{
			std::string a = "res/tank384px.png" ;
		}
		else if (e.getCarteForce() == 1 ) //canon
		{
			std::string a = "res/cannon384px.png" ;
		}
		else if (e.getCarteForce() == 2 ) //soldat
		{
			std::string a = "res/soldier384px.png" ;
		}
		else
		{
			throw "Erreur getCarteForce" ;
		}
	return a ;
}




int const CarteTileSet::getCellWidth ()
{
	return 60 ;
}

int const CarteTileSet::getCellHeight ()
{
	return 60 ;
}

const Tile& CarteTileSet::getTile(const state::Element& e)
{
	Tile& s = tank[0]; //initialisation
	if(e.getCarteForce()== 0) //tank
	{
		s=tank[0];
	}
	if(e.getCarteForce()==1) //canon
	{
		s=canon[0];
	}
	if(e.getCarteForce()==2) //soldat
	{
		s=soldat[0];
	}
	return s;
}

}
