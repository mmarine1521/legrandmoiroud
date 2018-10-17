#include "Pays.h"
<<<<<<< HEAD

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
=======
#include <vector>

namespace state
{


Pays::Pays ()
{

}

Pays::Pays (int idPays, ContinentId continent): idPays(idPays), idContinent(continent)
{

}

int Pays::getIdPays ()
{
	return this -> idPays ;
}


std::vector<Pays> Pays::getPaysFrontaliers ()
{
	return this -> paysFrontaliers ;
}


ContinentId Pays::getContinent ()
{
>>>>>>> 397de04f24511ac8135e15c529aad9d51c62eff9
	return this -> idContinent ;

}

<<<<<<< HEAD
void Pays::setPaysFrontaliers (std::vector<Pays> paysFrontaliers){
=======
void Pays::setPaysFrontaliers (std::vector<Pays> paysFrontaliers)
{
>>>>>>> 397de04f24511ac8135e15c529aad9d51c62eff9
	this -> paysFrontaliers = paysFrontaliers ;
}


}
