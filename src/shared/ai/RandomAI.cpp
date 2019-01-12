#include "RandomAI.h"
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>    // std::find

namespace ai{

RandomAI::RandomAI(int idJoueur) : AI(idJoueur){
}

void RandomAI::aiRepartitionArmees (state::State& state){
  aiPlacementArmees(state);
}

void RandomAI::aiChoixPaysAttaquant (state::State& state){
  std::vector<std::string> blackList = state.getBlackList();
  state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur() == state.getIdJoueur()){ //le choix ne se fait que sur les pays du joueur "idJoueur"
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
		engine::TourDeJeu::pushCommande(new engine::Passer(this->getIdJoueur()));
	}
	else{
		int armeeAleatoire = rand() % listeArmeeJoueur.size();
		ptr_armee = listeArmeeJoueur[armeeAleatoire]; // on choisit un pays aléatoirement
    engine::TourDeJeu::pushCommande(new engine::ChoixPaysAttaquant(this->getIdJoueur(), ptr_armee->getPays()));
	}
}

void RandomAI::aiChoixPaysAttaque (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur() != state.getIdJoueur()){
			if (engine::ChoixPaysAttaque::estFrontalier(ptr_armee->getPays(), state.getPaysAttaquant(), state)){
				listeArmeeJoueur.push_back(ptr_armee); //on vérifie que le pays est bien frontalier de pays attaquant.
			}
		}
	}

	int armeeAleatoire = rand() % listeArmeeJoueur.size();
	ptr_armee = listeArmeeJoueur[armeeAleatoire];
	engine::TourDeJeu::pushCommande(new engine::ChoixPaysAttaque(this->getIdJoueur(), ptr_armee->getPays()));
}

void RandomAI::aiDesAttaquant (state::State& state){
  engine::TourDeJeu::pushCommande(new engine::DesAttaquant(this->getIdJoueur(), rand() % 3 + 1));
}

void RandomAI::aiDesAttaque (state::State& state){
  engine::TourDeJeu::pushCommande(new engine::DesAttaque(this->getIdJoueur(), rand() % 2 + 1));
}

void RandomAI::aiDefausser (state::State& state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::Element* ptr_carte = 0;

  std::vector<state::Element*> listeCarteJoueur;
  for(size_t i=0; i<listeEnjeu.size(); i++){
    ptr_carte = listeEnjeu[i].get();
    if(ptr_carte->getIdJoueur() == state.getIdJoueur()){
      listeCarteJoueur.push_back(ptr_carte);
    }
  }

  int positionCarte = rand() % listeCarteJoueur.size();
  ptr_carte = listeCarteJoueur[positionCarte];
  engine::TourDeJeu::pushCommande(new engine::Defausser(this->getIdJoueur(), ptr_carte->getNumero()));
}

void RandomAI::aiEchange (state::State& state){
  int decision = rand() % 2;
  if (decision == 0){
    engine::TourDeJeu::pushCommande(new engine::Passer(this->getIdJoueur()));
  }
  else{
    state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
    std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
    state::Element* ptr_carte = 0;
    std::vector<state::Element*> listeCarteJoueur;

    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if (ptr_carte->getIdJoueur() == state.getIdJoueur()){
        listeCarteJoueur.push_back(ptr_carte);
      }
    }

    int positionCarte = rand() % listeCarteJoueur.size();
    ptr_carte = listeCarteJoueur[positionCarte];
    engine::TourDeJeu::pushCommande(new engine::EchangeCartes(this->getIdJoueur(), ptr_carte->getNumero()));
  }
}

void RandomAI::aiPlacementArmees (state::State& state){
	
  state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;
	
	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur() == state.getIdJoueur()){
      listeArmeeJoueur.push_back(ptr_armee);
		}
	}
	int numeroPays = rand() % listeArmeeJoueur.size();	
	int nombreArmees = rand() % (state.getArmeesPlacer()) + 1;
	std::cout<< "nombreArmees rand" << nombreArmees << std::endl ; 	
	ptr_armee = listeArmeeJoueur[numeroPays];
	
  engine::TourDeJeu::pushCommande(new engine::PlacementArmees(this->getIdJoueur(), ptr_armee->getPays(), nombreArmees));
}

void RandomAI::aiDeplacerArmees (state::State& state){
  int decision = rand() % 2;
  if (decision == 0){
    engine::TourDeJeu::pushCommande(new engine::Passer(state.getIdJoueur()));
  }
  else{
    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* ptr_armee = 0;

    std::vector<state::Element*> listeArmeeJoueur;
    for(size_t i=0; i<listeArmee.size(); i++){
      ptr_armee = listeArmee[i].get();
      if(ptr_armee->getIdJoueur() != state.getIdJoueur()){
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
    engine::TourDeJeu::pushCommande(new engine::DeplacerArmees(this->getIdJoueur(), listePays1[numeroPays], listePays2[numeroPays], nombreArmees));
  }
}

}
