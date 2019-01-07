#include "RandomAI.h"

namespace ai {

void RandomAI::aiPlacementArmees (state::State state){
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
	int nombreArmees = rand() % state.getArmeesPlacer() + 1;
	ptr_armee = listeArmeeJoueur[numeroPays];

  pushCommande(new state::PlacementArmees(ptr_armee->getPays(), nombreArmees));
}

void RandomAI::aiChoixPaysAttaquant (std::vector<std::string> blackList, state::State state){
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
		pays = "PROBLEME";
	}
	else{
		int armeeAleatoire = rand() % listeArmeeJoueur.size();
		ptr_armee = listeArmeeJoueur[armeeAleatoire]; // on choisit un pays aléatoirement
		pays = ptr_armee->getPays();
	}
  pushCommande(new state::ChoixPaysAttaquant(pays));
}

void RandomAI::aiChoixPaysAttaque (state::State state){
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

	pushCommande(new state::ChoixPaysAttaque(ptr_armee->getPays()));
}

void RandomAI::aiDesAttaquant (state::State state){
  pushCommande(new state::DesAttaquant(rand() % 3 + 1));
}

void RandomAI::aiDesAttaque (state::State state){
  pushCommande(new state::DesAttaque(rand() % 2 + 1));
}

void RandomAI::aiDefausser (state::State state){
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
  pushCommande(new state::Defausser(ptr_carte->getNumero()));
}
/*
void RandomAI::aiEchange (state::State state){
  int decision = rand() % 2;
  if (decision == 0){
    commandes.push_back(new state::Passer());
  }
  if (decision == 1){
    state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
    std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
    state::Element* ptr_carte = 0;

    int comptTANK = 0;
    int comptCANON = 0;
    int comptSOLDAT = 0;
    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if (ptr_carte->getIdJoueur() == state.getIdJoueur()){
        switch (ptr_carte->getCarteForce()) {
          case 0 : break; //NONIDENTIFIE
          case 1 : comptTANK +=1; break; //TANK
          case 2 : comptCANON +=1; break; //CANON
          case 3 : comptSOLDAT +=1; break; //SOLDAT
        }
      }
    }

    if (comptTANK < 3 && comptCANON < 3 && comptSOLDAT < 3){
      commandes.push_back(new state::Passer());
    }
    else{
      int comptDefausse = 0;
      if (comptTANK >= 3){
        for(size_t i=0; i<listeEnjeu.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getIdJoueur() == idJoueur){
            if (ptr_carte->getCarteForce() == 1){
              engine::GestionCartes::defausser(ptr_carte->getNumero(), state);
              comptDefausse += 1;
            }
          }
          if (comptDefausse == 3){
            break;
          }
        }
        return 5;
      }

      else if (comptCANON >= 3){
        for(size_t i=0; i<listeEnjeu.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getIdJoueur() == idJoueur){
            if (ptr_carte->getCarteForce() == 2){
              engine::GestionCartes::defausser(ptr_carte->getNumero(), state);
              comptDefausse += 1;
            }
          }
          if (comptDefausse == 3){
            break;
          }
        }
        return 8;
      }

      else if (comptSOLDAT >= 3){
        for(size_t i=0; i<listeEnjeu.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getIdJoueur() == idJoueur){
            if (ptr_carte->getCarteForce() == 3){
              engine::GestionCartes::defausser(ptr_carte->getNumero(), state);
              comptDefausse += 1;
            }
          }
          if (comptDefausse == 3){
            break;
          }
        }
        return 3;
      }
    }
  }
  else{
    return 0;
  }
	return -1;
}*/
//void RandomAI::aiDeplacerArmees (state::State state);
//void RandomAI::aiTourDeJeu (state::State state);

}
