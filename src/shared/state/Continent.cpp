#include "Continent.h"

#include <vector>

namespace state{

Continent::Continent (std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId) : continentId(continentId), couleurId(couleurId), listePays(listePays){

}

Continent::~Continent (){
}

TypeId const Continent::getTypeId (){
	return CONTINENT;
}

ContinentId const Continent::getContinentId (){
	return this -> continentId ;
}

CouleurId const Continent::getCouleurId (){
	return this -> couleurId ;
}

std::vector<Pays> Continent::getListePays (){
	return this -> listePays ;
}

}
