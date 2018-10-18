#include "Pays.h"

#include <vector>

namespace state{

Pays::Pays (){
}

Pays::Pays (int paysId, ContinentId continentId): paysId(paysId), continentId(continentId){
}

Pays::~Pays (){
}

TypeId const Pays::getTypeId (){
	return PAYS;
}

int Pays::getPaysId (){
	return this -> paysId ;
}

ContinentId Pays::getContinentId (){
	return continentId;
}

std::vector<Pays> Pays::getPaysFrontaliers (){
	return this -> paysFrontaliers ;
}

void Pays::setPaysFrontaliers (std::vector<Pays> paysFrontaliers){
	this -> paysFrontaliers = paysFrontaliers ;
}

}
