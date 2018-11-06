#include "Continent.h"

#include <vector>

namespace state{

Continent::Continent (std::string nomContinent, ContinentId continentId, CouleurId couleurId, std::vector<std::string> listePays) : continentId(continentId), couleurId(couleurId), nomContinent(nomContinent), listePays(listePays){
}

Continent::~Continent (){
}

TypeId const Continent::getTypeId (){
	return CONTINENT;
}

std::string const Continent::getNomContinent (){
	return this -> nomContinent ;
}

ContinentId const Continent::getContinentId (){
	return this -> continentId ;
}

CouleurId const Continent::getCouleurId (){
	return this -> couleurId ;
}

std::vector<std::string> const Continent::getListePays (){
	return this -> listePays ;
}

}
