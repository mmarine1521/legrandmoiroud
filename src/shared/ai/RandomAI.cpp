#include "RandomAI.h"
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>    // std::find

namespace ai{

RandomAI::RandomAI(int idJoueurAI) : AI(idJoueurAI){
}

engine::Commande* RandomAI::aiRepartitionArmees (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur() == this->idJoueurAI){
      listeArmeeJoueur.push_back(ptr_armee);
		}
	}
	int numeroPays = rand() % listeArmeeJoueur.size();
	int nombreArmees = rand() % 4 + 1;
	ptr_armee = listeArmeeJoueur[numeroPays];

  return (new engine::PlacementArmees(this->idJoueurAI, ptr_armee->getPays(), nombreArmees));
}

engine::Commande* RandomAI::aiChoixPaysAttaquant (state::State& state){
  std::vector<std::string> blackList = state.getBlackList();
  state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur() == this->idJoueurAI){ //le choix ne se fait que sur les pays du joueur "idJoueur"
			std::vector<std::string>::iterator result = find(blackList.begin(), blackList.end(), ptr_armee->getPays()); // renvoie le dernier element si faux
			if (result == blackList.end()){
				if(ptr_armee->getNombre() > 1){ //nombre d'armées > 1 sinon impossible d'attaquer
					listeArmeeJoueur.push_back(ptr_armee);
				}
			}
		}
	}

  std::string pays;
	if (listeArmeeJoueur.size() == 0){
		std::cout << "Problème : Le joueur ne peut engagé aucun de vos territoires dans un combat." << std::endl;
    return (new engine::Passer(this->idJoueurAI, 0));
	}
	else{
		int armeeAleatoire = rand() % listeArmeeJoueur.size();
		ptr_armee = listeArmeeJoueur[armeeAleatoire]; // on choisit un pays aléatoirement
    return (new engine::ChoixPaysAttaquant(this->idJoueurAI, ptr_armee->getPays()));
	}
}

engine::Commande* RandomAI::aiChoixPaysAttaque (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur() != this->idJoueurAI){
			if (engine::ChoixPaysAttaque::estFrontalier(ptr_armee->getPays(), state.getPaysAttaquant(), state)){
				listeArmeeJoueur.push_back(ptr_armee); //on vérifie que le pays est bien frontalier de pays attaquant.
			}
		}
	}

	int armeeAleatoire = rand() % listeArmeeJoueur.size();
	ptr_armee = listeArmeeJoueur[armeeAleatoire];
  return (new engine::ChoixPaysAttaque(this->idJoueurAI, ptr_armee->getPays()));
}

engine::Commande* RandomAI::aiDesAttaquant (state::State& state){
  return (new engine::DesAttaquant(this->idJoueurAI, rand() % 3 + 1));
}

engine::Commande* RandomAI::aiDesAttaque (state::State& state){
  return (new engine::DesAttaque(this->idJoueurAI, rand() % 2 + 1));
}

engine::Commande* RandomAI::aiDefausser (state::State& state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::Element* ptr_carte = 0;

  std::vector<state::Element*> listeCarteJoueur;
  for(size_t i=0; i<listeEnjeu.size(); i++){
    ptr_carte = listeEnjeu[i].get();
    if(ptr_carte->getIdJoueur() == this->idJoueurAI){
      listeCarteJoueur.push_back(ptr_carte);
    }
  }

  int positionCarte = rand() % listeCarteJoueur.size();
  ptr_carte = listeCarteJoueur[positionCarte];
  return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
}

engine::Commande* RandomAI::aiEchange (state::State& state){
  int decision = rand() % 2;
  if (decision == 0){
    return (new engine::Passer(this->idJoueurAI, 0));
  }
  else{
    state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
    std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
    state::Element* ptr_carte = 0;
    std::vector<state::Element*> listeCarteJoueur;

    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if (ptr_carte->getIdJoueur() == this->idJoueurAI){
        listeCarteJoueur.push_back(ptr_carte);
      }
    }

    int positionCarte = rand() % listeCarteJoueur.size();
    ptr_carte = listeCarteJoueur[positionCarte];
    return (new engine::EchangeCartes(this->idJoueurAI, ptr_carte->getNumero()));
  }
}

engine::Commande* RandomAI::aiPlacementArmees (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur() == this->idJoueurAI){
      listeArmeeJoueur.push_back(ptr_armee);
		}
	}
	int numeroPays = rand() % listeArmeeJoueur.size();
	int nombreArmees = rand() % (state.getArmeesRepartition(this->idJoueurAI)) + 1;
	ptr_armee = listeArmeeJoueur[numeroPays];

  return (new engine::PlacementArmees(this->idJoueurAI, ptr_armee->getPays(), nombreArmees));
}

engine::Commande* RandomAI::aiDeplacerArmees (state::State& state){
  int decision = rand() % 2;
  if (decision == 0){
    return (new engine::Passer(this->idJoueurAI, 1));
  }
  else{
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* ptr_armee = 0;

    std::vector<state::Element*> listeArmeeJoueur;
    for(size_t i=0; i<listeArmee.size(); i++){
      ptr_armee = listeArmee[i].get();
      if(ptr_armee->getIdJoueur() != this->idJoueurAI){
        listeArmeeJoueur.push_back(ptr_armee);
      }
    }

    state::ElementTab& tabPays = state.getPaysTab();
    std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
    state::Element* ptr_pays1 = 0;
    state::Element* ptr_pays2 = 0;
    std::vector<state::Element*> listePaysJoueur;

    for(size_t j=0; j<listeArmeeJoueur.size(); j++){//pour chaque armee du joueur
      for(size_t i=0; i<listePays.size(); i++){//on cherche dans tous les pays le bon
        ptr_pays1 = listePays[i].get();
        if(ptr_pays1->getPays() == listeArmeeJoueur[j]->getPays()){
          listePaysJoueur.push_back(ptr_pays1);
          break;
        }
      }
    }

    std::vector<std::string> listePays1;
    std::vector<std::string> listePays2;
    for(size_t i=0; i<listePaysJoueur.size(); i++){
      ptr_pays1 = listePaysJoueur[i];
      for(size_t j=0; j<listePaysJoueur.size(); j++){
        ptr_pays2 = listePaysJoueur[j];
        bool frontiere = engine::ChoixPaysAttaque::estFrontalier(ptr_pays1->getPays(), ptr_pays2->getPays(), state);
        if(frontiere){
          listePays1.push_back(ptr_pays1->getPays());
          listePays2.push_back(ptr_pays2->getPays());
        }
      }
    }

    int numeroPays = rand() % listePays1.size();
    for(size_t i=0; i<listeArmee.size(); i++){
      ptr_armee = listeArmee[i].get();
      if(ptr_armee->getPays() == listePays1[numeroPays]){
        break;
      }
    }

    int nombreArmees = rand() % ptr_armee->getNombre();
    return (new engine::DeplacerArmees(this->idJoueurAI, listePays1[numeroPays], listePays2[numeroPays], nombreArmees));
  }
}

}
