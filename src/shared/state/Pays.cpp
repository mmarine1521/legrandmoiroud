#include "Pays.h"

#include <vector>

namespace state{

Pays::Pays (){
}

Pays::Pays (int idPays, ContinentId continent): idPays(idPays), idContinent(continent){
}

int Pays::getIdPays (){
	return this -> idPays ;
}

std::vector<Pays> Pays::getPaysFrontaliers (){
	return this -> paysFrontaliers ;
}

ContinentId Pays::getContinent (){
	return this -> idContinent ;

}

void Pays::setPaysFrontaliers (std::vector<Pays> paysFrontaliers){
	this -> paysFrontaliers = paysFrontaliers ;
}


}
