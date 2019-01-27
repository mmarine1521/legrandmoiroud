#include "Continent.h"

#include <vector>

namespace state{

Continent::Continent (std::string nomContinent, std::vector<std::string> listePays) : nomContinent(nomContinent), listePays(listePays){
}

Continent::~Continent (){
}

TypeId const Continent::getTypeId (){
	return CONTINENT;
}

std::string const Continent::getNomContinent (){
	return this -> nomContinent ;
}

std::vector<std::string> const Continent::getListePays (){
	return this -> listePays ;
}

std::shared_ptr<Element> Continent::clone (){
  return std::shared_ptr<Element>(new Continent(*this));
}

}
