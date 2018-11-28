//etape 7
#include "IssueDuCombat.h"

#include <algorithm>    // std::max

namespace engine {

IssueDuCombat::~IssueDuCombat (){
}

IdCommande const IssueDuCombat::getIdCommande (){
  return ISSUECOMBAT;
}

bool IssueDuCombat::victoire (std::vector<int>& desRouges, std::vector<int>& desBleus, std::string paysAttaquant, std::string paysAttaque, state::State state){//etape 7
  int ite = std::max(desRouges.size(), desBleus.size());
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* eAttaquant = 0;
  state::Element* eAttaque = 0;
  for(size_t i=0; i<listeArmee.size(); i++)
  {
    eAttaquant = listeArmee[i].get();
    if(eAttaquant->getPays()==paysAttaquant) //récupère le pays attaquant
    {
      break;
    }
  }
  for(size_t i=0; i<listeArmee.size(); i++)
  {
    eAttaque = listeArmee[i].get();
    if(eAttaque->getPays()==paysAttaque) //récupère le pays attaqué
    {
      break;
    }
  }
  for (int i = 0; i < ite; i++)
  {
	  if(desRouges.size()!=3) //cas normal où l'attaque n'a pas trois dés (on ne dépassera donc pas la liste du dé bleu dans l'itération
	  {
			if (desRouges[i] > desBleus[i])
			{
			  std::cout << "Vous avez gagné le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
			  eAttaque->setNombre(eAttaque->getNombre() - 1);
			}
			else
			{
			  std::cout << "Vous avez perdu le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
			  eAttaquant->setNombre(eAttaquant->getNombre() - 1);
			}
	  }
  }
  for (int i=0 ; i<desBleus.size() ; i++)
  {
	  if (desRouges.size()==3) //si l'attaque a 3 dés. 
			{
		  if (desRouges[0] > desBleus[i])
			{
			  std::cout << "Vous avez gagné le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
			  eAttaque->setNombre(eAttaque->getNombre() - 1);
			}  
		  if (desRouges[1] > desBleus[i])
			{
			  std::cout << "Vous avez gagné le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
			  eAttaque->setNombre(eAttaque->getNombre() - 1);
			}
		  if (desRouges[0] > desBleus[0])
			{
			  std::cout << "Vous avez gagné le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
			  eAttaque->setNombre(eAttaque->getNombre() - 1);
			}		 
		  else 
		  	  	  	{
		  			  std::cout << "Vous avez perdu le tour " << i+1 << ". Vous avez fait " << desRouges[i] << " et votre adversaire " << desBleus[i] << "." << std::endl;
		  			  eAttaquant->setNombre(eAttaquant->getNombre() - 1);
		  			}
		  
			}
  }
  
  if (eAttaquant->getNombre() <= 0)
  {
    std::cout << "Vous avez perdu votre territoire." << std::endl;
    eAttaquant->setNombre(1);
    eAttaque->setNombre(eAttaque->getNombre() - 1);
    eAttaquant->setIdJoueur(eAttaque->getIdJoueur());
  }
  if (eAttaque->getNombre() <= 0)
  {
    std::cout << "Vous avez gagné le territoire." << std::endl;
    eAttaque->setNombre(1);
    eAttaquant->setNombre(eAttaquant->getNombre() - 1);
    eAttaque->setIdJoueur(eAttaquant->getIdJoueur());
    return true;
  }
  return false;
}

}
