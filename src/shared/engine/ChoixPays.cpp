//etapes 1-2
#include "ChoixPays.h"

#include <iostream>

namespace engine {

ChoixPays::~ChoixPays (){
}

IdCommande const ChoixPays::getIdCommande (){
  return CHOIXPAYS;
}

bool ChoixPays::estFrontalier(std::string pays1, std::string pays2, state::State state){
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ePays = 0;
  for(size_t i=0; i<listePays.size(); i++){
    ePays = listePays[i].get();
    if(ePays->getPays() == pays1){
      std::vector<std::string> listePaysFontaliers = ePays->getPaysFrontaliers();
      for(size_t i=0; i<listePaysFontaliers.size(); i++){
        if(listePaysFontaliers[i] == pays2){
          return true;
        }
      }
    }
  }
  return false;
}

std::string ChoixPays::choixPaysAttaquant (){//etape 1
  std::cout << "Avec quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  std::cout << std::endl;
  return pays;
}

bool ChoixPays::verifPaysAttaquant (int idJoueur, std::string paysAttaquant, state::State state){//etape 1
  bool ok = false;  //return initial à false
  
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  
  for(size_t i=0; i<listeArmee.size(); i++)
  {
    ptr_armee = listeArmee[i].get();
    
    if(ptr_armee->getPays() == paysAttaquant)
    {
      break; // on a la bonne Armee
    } 
  }
  std::cout<<"début verifPaysAttaquant - armee" << ptr_armee->getPays()<< std::endl ;
  
  if(ptr_armee->getIdJoueur() == idJoueur)
  {
    state::ElementTab& tabPays = state.getPaysTab();
    std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
    state::Element* ptr_pays = 0;
    for(size_t i=0; i<listePays.size(); i++)
    {
      ptr_pays = listePays[i].get();
      if(ptr_pays->getPays() == paysAttaquant)
      {
        break; // on a le bon Pays
      }
    }
    std::cout<<"début verifPaysAttaquant - pays" << ptr_armee->getPays()<< std::endl ;
    

    std::vector<std::string> listePaysFontaliers = ptr_pays->getPaysFrontaliers(); //on vérifie dans les pays frontaliers qu'il n'y ait pas que des pays du joueur qui attaque
    state::Element* ptr_frontalier = 0;
    std::cout<<"suite verifPaysAttaquant"<< std::endl ;
    
    std::cout<<"recup pays Frontaliers"<< std::endl ;
    for(size_t i=0; i<listePaysFontaliers.size(); i++)
    {
      std::string paysFrontalier = listePaysFontaliers[i];
      
      std::cout<<"pays Frontaliers :" << paysFrontalier<<std::endl ;
      
      for(size_t j=0; j<listeArmee.size(); j++)
      {
        ptr_frontalier = listeArmee[j].get();
         
        if(ptr_frontalier->getPays() == paysFrontalier)
        {
        	std::cout<< "les pays frontaliers 2 sont " << ptr_frontalier->getPays()<<"ID joueur" <<ptr_frontalier->getIdJoueur() <<std::endl ;
        	if(ptr_frontalier->getIdJoueur() != idJoueur)
				  {
					ok = true;
					std::cout<< "les pays frontaliers 2 sont " << ptr_frontalier->getPays() <<"l'id du joueur de ce pays est " << ptr_frontalier->getIdJoueur()<<std::endl ;
					std::cout<<"début verifPaysAttaquant - frontalier d'autre joueur OK" << std::endl ;
					break ; 
					
				  }
        	else 
        	{
        		break ; 
        		std::cout<< "impossible d'attaquer dans l'état - faites des déplacements"<<std::endl ; 
        		
        	}
        	break;
        }
        
      }
     
    }
    

  }
  else {
    std::cout << "Problème : Ce pays ne vous appartient pas." << std::endl;
  
  }
  std::cout<<"resultat de la fonction" << ok<<std::endl ; 
  return ok;
}

std::string ChoixPays::choixPaysAttaque (){//etape 2
  std::cout << "Quel pays souhaitez-vous attaquer ?" << std::endl;
  std::string pays;
  std::cin >> pays;
  std::cout << std::endl;
  return pays;
}

bool ChoixPays::verifPaysAttaque (int idJoueur, std::string paysAttaque, std::string paysAttaquant, state::State state){
  bool ok = false;
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* eAttaque = 0;
  state::Element* eAttaquant = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    eAttaque = listeArmee[i].get();
    if(eAttaque->getPays() == paysAttaque){
      break;
    }
  }
  for(size_t i=0; i<listeArmee.size(); i++){
    eAttaquant = listeArmee[i].get();
    if(eAttaquant->getPays() == paysAttaquant){
      break;
    }
  }
  if (eAttaque->getIdJoueur() != idJoueur){
    ok = estFrontalier(paysAttaque, paysAttaquant, state);
    if (!ok){
      std::cout << "Problème : Ce pays n'est pas un frontalier." << std::endl;
    }
  }
  else{
    std::cout << "Problème : Ce territoire vous appartient." << std::endl;
  }
  return ok;
}

}
