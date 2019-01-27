#include "Pays.h"

#include <vector>

namespace state{

Pays::Pays (std::string nomPays, std::vector<std::string> paysFrontaliers): nomPays(nomPays), paysFrontaliers(paysFrontaliers){
}

Pays::~Pays (){
}

TypeId const Pays::getTypeId (){
	return PAYS;
}

std::string Pays::getPays (){
	return this -> nomPays ;
}

std::vector<std::string> const Pays::getPaysFrontaliers (){
	return this -> paysFrontaliers ;
}

void Pays::setPaysFrontaliers (std::vector<std::string> paysFrontaliers){
	this -> paysFrontaliers = paysFrontaliers ;
}

std::ostream& operator<< (std::ostream& flux, Pays const& pays){
	flux << pays.nomPays << std::endl;
	return flux;
}

std::shared_ptr<Element> Pays::clone (){
  return std::shared_ptr<Element>(new Pays(*this));
}

}
