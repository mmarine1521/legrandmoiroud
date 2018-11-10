#include "AttributionTerritoires.h"
#include "engine.h"

using namespace engine ; 
using namespace state ; 

IdCommande const AttributionTerritoires::getIdCommande ()
{
	
	return ATTRIBUTERR ;
}

void AttributionTerritoires::distribution (state::State state, int nbJoueurs)
{
	int joueur = 0 ; 
	int joueur1=0 ; 
	int joueur2 =0 ; 
	int joueur3=0 ;  
	std::string pays ; 
	int ID ; 
	
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* e;
	
	
		for(size_t i=0; i<listeArmee.size(); i++)
		{
			//if(joueur1<=14 && joueur2<=14 && joueur3<=14)
			//{
				e = listeArmee[i].get();
				int joueur = rand() % nbJoueurs + 1; //nb aleatoire de 1 à nbJoueurs ;
				if (joueur == 1)
				{
					joueur1+=1 ; 
				}
				if (joueur == 2)
				{
					joueur2+=1 ;					
				}
				if (joueur == 3)
				{
					joueur3+=1 ;					
				}
				e->setIdJoueur(joueur) ; 
							
				pays = e -> getPays() ; 
				ID = e -> getIdJoueur() ;
			//}
//			if(joueur2 ==14)
//			{
//				if(joueur1 <=14 && joueur3 <=14)
//				{
//					int joueur = rand() % 2 + 1; //nb aleatoire de 1 à nbJoueurs ;
//					if(joueur == 1){joueur = 1; } else if(joueur ==2){joueur =3;}
//					if (joueur == 1)
//					{
//						joueur1+=1 ; 
//					}
//					if (joueur == 3)
//					{
//						joueur3+=1 ;					
//					}					
//				}
//				e->setIdJoueur(joueur) ; 
//				pays = e -> getPays() ; 
//				ID = e -> getIdJoueur() ;
//			}
//			if(joueur1 ==14)
//			{
//				if(joueur2 <=14 && joueur3 <=14)
//				{
//					int joueur = rand() % 3 + 2; //nb aleatoire de 1 à nbJoueurs ;
//					if (joueur == 2)
//					{
//						joueur2+=1 ; 
//					}
//					if (joueur == 3)
//					{
//						joueur3+=1 ;					
//					}	
//				}
//				e->setIdJoueur(joueur) ; 
//				pays = e -> getPays() ; 
//				ID = e -> getIdJoueur() ;
//			}
//			if(joueur3 ==14)
//			{
//				if(joueur1 <=14 && joueur2 <=14)
//				{
//					int joueur = rand() % 2 + 1; //nb aleatoire de 1 à nbJoueurs ;
//					if (joueur == 1)
//					{
//						joueur1+=1 ; 
//					}
//					if (joueur == 2)
//					{
//						joueur2+=1 ;					
//					}	
//				}
//				e->setIdJoueur(joueur) ; 
//				pays = e -> getPays() ; 
//				ID = e -> getIdJoueur() ;
//			}
//			if(joueur1 ==14 && joueur2 ==14)
//			{
//				if(joueur3 <=14)
//				{
//					joueur = 3 ; 
//					if (joueur == 3)
//					{
//						joueur3+=1 ; 
//					}	
//				}
//				e->setIdJoueur(joueur) ; 
//				pays = e -> getPays() ; 
//				ID = e -> getIdJoueur() ;
//			}
//			if(joueur1 ==14 && joueur3 ==14)
//			{
//				if(joueur2 <=14)
//				{
//					joueur = 2 ; 
//					if (joueur == 2)
//					{
//						joueur2+=1 ; 
//					}
//				}
//				e->setIdJoueur(joueur) ; 
//				pays = e -> getPays() ; 
//				ID = e -> getIdJoueur() ;
//			}
//			if(joueur2 ==14 && joueur3 ==14)
//			{
//				if(joueur1 <=14)
//				{
//					joueur = 1 ; 
//					if (joueur == 1)
//					{
//						joueur1+=1 ; 
//					}	
//				}
//				e->setIdJoueur(joueur) ; 
//				pays = e -> getPays() ; 
//				ID = e -> getIdJoueur() ;
//			}
	}
		std::cout << "L'armée est celle du pays "<< pays << std::endl ; 
		std::cout << "Le pays appartient au joueur" << ID << std::endl ;
	}
	
//}

bool AttributionTerritoires::repartitionArmees (int idJoueur)
{

}