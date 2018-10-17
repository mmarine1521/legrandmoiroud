#include "Continent.h"
#include <vector>

namespace state
{

Continent::Continent(std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId) : listePays(listePays), continentId(continentId), couleurId(couleurId)
		{

		}
TypeId const getTypeId ()
{
	return CONTINENT;
}

ContinentId const Continent::getContinentId ()
{
	return this -> continentId ;
}

CouleurId const Continent::getCouleurId ()
{
	return this -> couleurId ;
}

std::vector<Pays> Continent::getListePays ()
	{
		return this -> listePays ;
	}

}
