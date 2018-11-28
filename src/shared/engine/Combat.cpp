//etapes 3-4-5-6
#include "Combat.h"

#include <iostream>
#include <cstdlib> // rand
#include <algorithm> // sort

namespace engine {

Combat::~Combat (){
}

IdCommande const Combat::getIdCommande (){
  return COMBAT;
}

int Combat::nbDesLances (){ // Appeler pour l'attaque et la défense : etapes 3-4
  std::cout << "Combien de dés souhaitez-vous lancer ?" << std::endl;
  int nbDes;
  std::cin >> nbDes;
  return nbDes;
}

bool Combat::verifNbAttaques (int nbDes, std::string paysAttaquant, state::State state){ //etape 3
  if (nbDes<1 || nbDes>3){
    std::cout << "Problème : Vous ne pouvez lancer que 1, 2 ou 3 dés." << std::endl;
    return false;
  }
  else
  {
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* e = 0;
    for(size_t i=0; i<listeArmee.size(); i++)
    {
    	e = listeArmee[i].get();
  		if(e->getPays()==paysAttaquant)
  		{
  			if (e->getNombre() >= nbDes + 1) //on vérifie si le nombre d'armées du pays est supérieur au nombre de dés choisi pour l'attaque
  			{
  				return true;
  			}
  			else
  			{
  				std::cout << "Problème : Vous n'avez pas assez d'armées sur votre territoire pouvant attaquer." << std::endl;
  				//nbDes -= 1;  //si ce n'est pas le cas, on diminue le nombre de dés lancés de 1 ;
  				break ; 
  			}
        break;
  		}
  	}
  }
  return false;
}

bool Combat::verifNbDefenses (int nbDes, std::string paysAttaque, state::State state){ //etape 4
  if (nbDes<1 || nbDes>2){
    std::cout << "Problème : Vous ne pouvez lancer que 1 ou 2 dés." << std::endl;
    return false;
  }
  else{
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* e = 0;
    for(size_t i=0; i<listeArmee.size(); i++)
    {
    	e = listeArmee[i].get();
  		if(e->getPays()==paysAttaque)
  		{
  			if (e->getNombre() >= nbDes)
  			{
  				return true;
  			}
  			else
  			{
  				std::cout << "Problème : Vous n'avez pas assez d'armées sur votre territoire pouvant défendre." << std::endl;
  			}
        break;
  		}
  	}
  }
  return false;
}

std::vector<int> Combat::lancerDes (int nbDes){ //etapes 5-6
	//srand(TIME(NULL)) appelé une unique fois dans le main
  std::vector<int> liste(nbDes);
  int nb = 0 ;
 
  for (int i=0; i<nbDes; i++)
  {
    nb = (rand() % 6) + 1; //nb aleatoire de 1 à 6
    liste[i] = nb;
  }
   //std::sort(liste.begin(), liste.end());
   return liste;
}

}
