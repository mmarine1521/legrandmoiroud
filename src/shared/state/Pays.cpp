#include "Pays.h"

#include <vector>

namespace state{

Pays::Pays (){
}

Pays::Pays (std::string nomPays, int paysId, ContinentId continentId): continentId(continentId), nomPays(nomPays), paysId(paysId){
}

Pays::~Pays (){
}

TypeId const Pays::getTypeId (){
	return PAYS;
}

std::string const Pays::getNomPays (){
	return this -> nomPays ;
}

int const Pays::getPaysId (){
	return this -> paysId ;
}

ContinentId const Pays::getContinentId (){
	return this -> continentId ;
}

std::vector<std::string> const Pays::getPaysFrontaliers (){
	return this -> paysFrontaliers ;
}

void Pays::setPaysFrontaliers (std::vector<std::string> paysFrontaliers){
	this -> paysFrontaliers = paysFrontaliers ;
}

std::ostream& operator<< (std::ostream& flux, Pays const& pays){
	flux << pays.nomPays << " : " << pays.paysId << std::endl;
	return flux;
}

std::unique_ptr<Element> Pays::clone (){
  return std::unique_ptr<Element>(new Pays(*this));
}

}
