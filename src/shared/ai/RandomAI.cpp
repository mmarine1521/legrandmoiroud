#include "RandomAI.h"

namespace ai {

bool RandomAI::aiRepartitionArmees (int idJoueur, state::State state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

  std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur()==idJoueur){
      listeArmeeJoueur.push_back(ptr_armee);
			ptr_armee->setNombre(3);
		}
	}

	srand (time(NULL));
	int armeeAleatoire1 = rand() % listeArmeeJoueur.size();
	int armeeAleatoire2 = -1;
	while(armeeAleatoire2 == -1 || armeeAleatoire2 == armeeAleatoire1){
		armeeAleatoire2 = rand() % listeArmeeJoueur.size();
	}

	ptr_armee = listeArmeeJoueur[armeeAleatoire1];
	ptr_armee->setNombre(2);
	ptr_armee = listeArmeeJoueur[armeeAleatoire2];
	ptr_armee->setNombre(2);

  return true;
}

std::string RandomAI::aiChoixPaysAttaquant (int idJoueur, state::State state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur()==idJoueur){
      listeArmeeJoueur.push_back(ptr_armee);
		}
	}

	srand (time(NULL));
	int armeeAleatoire = rand() % listeArmeeJoueur.size();
	ptr_armee = listeArmeeJoueur[armeeAleatoire];
	return ptr_armee->getPays();
}

std::string RandomAI::aiChoixPaysAttaque (int idJoueur, state::State state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur()!=idJoueur){
      listeArmeeJoueur.push_back(ptr_armee);
		}
	}

	srand (time(NULL));
	int armeeAleatoire = rand() % listeArmeeJoueur.size();
	ptr_armee = listeArmeeJoueur[armeeAleatoire];
	return ptr_armee->getPays();
}

int RandomAI::aiNbDesLancersAttaques (){
	return rand() % 3 + 1;
}

int RandomAI::aiNbDesLancersDefenses (){
	return rand() % 2 + 1;
}

//int RandomAI::aiEchange (int idJoueur, state::State state){}

//void RandomAI::aiPlacerNouvellesArmees (int idJoueur, int nouvellesArmees, state::State state){}

//void RandomAI::aiDeplacerArmees (int idJoueur, state::State state){}

}
