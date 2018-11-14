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

std::string RandomAI::aiChoixPaysAttaque (int idJoueur, std::string paysAttaquant, state::State state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<state::Element*> listeArmeeJoueur;
	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		if(ptr_armee->getIdJoueur()!=idJoueur){
			if (engine::ChoixPays::estFrontalier(ptr_armee->getPays(), paysAttaquant, state)){
				listeArmeeJoueur.push_back(ptr_armee);
			}
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

void RandomAI::aiGainCartes (int idJoueur, bool victoire, state::State state){
	if(victoire){
    state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
    std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
    state::Element* ptr_carte = 0;

    int compt = 0;
    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if(ptr_carte->getIdJoueur() == idJoueur){
        compt += 1;
      }
    }

    if (compt > 4){
			std::vector<state::Element*> listeCarteJoueur;
			for(size_t i=0; i<listeEnjeu.size(); i++){
				ptr_carte = listeEnjeu[i].get();
				if(ptr_carte->getIdJoueur()==idJoueur){
		      listeCarteJoueur.push_back(ptr_carte);
				}
			}

			srand(time(NULL));
      int positionCarte = rand() % listeCarteJoueur.size();
			ptr_carte = listeCarteJoueur[positionCarte];
      engine::GestionCartes::defausser (ptr_carte->getNumero(), state);
    }

    engine::GestionCartes::piocher(idJoueur, state);
  }
}

int RandomAI::aiEchange (int idJoueur, state::State state){
	state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
	std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
	state::Element* ptr_carte = 0;

	int comptTANK = 0;
	int comptCANON = 0;
	int comptSOLDAT = 0;
	for(size_t i=0; i<listeEnjeu.size(); i++){
		ptr_carte = listeEnjeu[i].get();
		if (ptr_carte->getIdJoueur() == idJoueur){
			switch (ptr_carte->getCarteForce()) {
				case 0 : break; //NONIDENTIFIE
				case 1 : comptTANK +=1; break; //TANK
				case 2 : comptCANON +=1; break; //CANON
				case 3 : comptSOLDAT +=1; break; //SOLDAT
			}
		}
	}

	if (comptTANK <3 && comptCANON <3 && comptSOLDAT <3){
		return 0;
	}
	else{
		srand(time(NULL));
		int decision = rand() % 2;
		if (decision == 0){
			return 0;
		}
		else{
			//5 cartes max
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
			return -1;
		}
	}
}

void RandomAI::aiPlacerNouvellesArmees (int idJoueur, int nouvellesArmees, state::State state){
	int armeesAPlacer = nouvellesArmees;
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

	int numeroPays;
	int nombreArmees;
	while (armeesAPlacer != 0){
		srand(time(NULL));
		numeroPays = rand() % listeArmeeJoueur.size();
		nombreArmees = rand() % armeesAPlacer + 1;
		ptr_armee = listeArmeeJoueur[numeroPays];
		ptr_armee->setNombre(ptr_armee->getNombre() + nombreArmees);
	}

}

void RandomAI::aiDeplacerArmees (int idJoueur, state::State state){
	srand(time(NULL));
	int decision = rand() % 2;
	while (decision == 1){
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

		state::ElementTab& tabPays = state.getPaysTab();
		std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
		state::Element* ptr_pays = 0;
		std::vector<state::Element*> listePaysJoueur;
		for(size_t j=0; j<listeArmeeJoueur.size(); j++){//pour chaque armee du joueur
			for(size_t i=0; i<listePays.size(); i++){//on cherche dans tous les pays le bon
	      ptr_pays = listePays[i].get();
	      if(ptr_pays->getPays() == listeArmeeJoueur[j]->getPays()){
					listePaysJoueur.push_back(ptr_pays);
	      }
	    }
		}

		std::vector<std::string> listePays1;
		std::vector<std::string> listePays2;
		for(size_t i=0; i<listePays.size(); i++){
			ptr_pays = listePays[i].get();
			std::vector<std::string> listePaysFrontaliers = ptr_pays->getPaysFrontaliers();
			for(size_t j=0; j<listePaysFrontaliers.size(); j++){
				bool frontiere = engine::ChoixPays::estFrontalier(ptr_pays->getPays(), listePaysFrontaliers[j], state);
				if(frontiere == true){
					listePays1.push_back(ptr_pays->getPays());
					listePays2.push_back(listePaysFrontaliers[j]);
				}
			}
		}

		srand(time(NULL));
		int numeroPays = rand() % listePays1.size();

		state::Element* ptr_armee1 = 0;
		state::Element* ptr_armee2 = 0;
		for(size_t i=0; i<listeArmee.size(); i++){
	    ptr_armee1 = listeArmee[i].get();
			if(ptr_armee1->getPays()==listePays1[numeroPays]){
	      break;
			}
		}
		for(size_t i=0; i<listeArmee.size(); i++){
	    ptr_armee2 = listeArmee[i].get();
			if(ptr_armee2->getPays()==listePays2[numeroPays]){
	      break;
			}
		}

		int nombreArmees = rand() % ptr_armee1->getNombre();
		ptr_armee1->setNombre(ptr_armee1->getNombre() - nombreArmees);
		ptr_armee2->setNombre(ptr_armee2->getNombre() + nombreArmees);

		decision = rand() % 2;
	}
}

void RandomAI::aiJouer (int numeroTour, int idJoueur, state::State state){
	std::cout << "Début du tour " << numeroTour << std::endl;
	std::cout << std::endl;

  //initialisation du jeu
  if (numeroTour == 0){
    //etape 2 de l'initialisation
    engine::AttributionTerritoires::distribution(state, 3);

		//etape 3 de l'initialisation
    std::cout << "Le joueur 1 place ses armées." << std::endl;
    bool distributionOk = aiRepartitionArmees(1, state);

    std::cout << "Le joueur 2 place ses armées." << std::endl;
    distributionOk = aiRepartitionArmees(2, state);

    std::cout << "Le joueur fictif 3 place ses armées." << std::endl;
    distributionOk = aiRepartitionArmees(3, state);
	}

		//etape 1 du jeu
	  std::string paysAttaquant = aiChoixPaysAttaquant(idJoueur, state);
	  bool verifPaysAttaquantOk = engine::ChoixPays::verifPaysAttaquant(idJoueur, paysAttaquant, state);
	  while(!verifPaysAttaquantOk){
	    paysAttaquant = aiChoixPaysAttaquant(idJoueur, state);
	    verifPaysAttaquantOk = engine::ChoixPays::verifPaysAttaquant(idJoueur, paysAttaquant, state);
	  }
		std::cout << "Le pays attaquant est " << paysAttaquant << "." << std::endl;

		//etape 2 du jeu
	  std::string paysAttaque = aiChoixPaysAttaque(idJoueur, paysAttaquant, state);
	  bool verifPaysAttaqueOk = engine::ChoixPays::verifPaysAttaque(idJoueur, paysAttaque, paysAttaquant, state);
	  while(!verifPaysAttaqueOk){
	    paysAttaque = aiChoixPaysAttaque(idJoueur, paysAttaquant, state);
	    verifPaysAttaqueOk = engine::ChoixPays::verifPaysAttaque(idJoueur, paysAttaque, paysAttaquant, state);
	  }
		std::cout << "Le pays attaqué est " << paysAttaque << "." << std::endl;

		//etape 3 du jeu
	  std::cout << "C'est l'heure de l'attaque !" << std::endl;
	  int nbAttaques = aiNbDesLancersAttaques();
	  bool nbAttaquesOk = engine::Combat::verifNbAttaques (nbAttaques, paysAttaquant, state);
	  while(!nbAttaquesOk){
	    nbAttaques = aiNbDesLancersAttaques();
	    nbAttaquesOk = engine::Combat::verifNbAttaques (nbAttaques, paysAttaquant, state);
	  }
		std::cout << "L'attaque lance " << nbAttaques << " dés." << std::endl;

		//etape 5 du jeu
	  std::vector<int> desRouges = engine::Combat::lancerDes(nbAttaques);

		//etape 4 du jeu
	  std::cout << "L'adversaire se défend." << std::endl;
	  int nbDefenses = aiNbDesLancersDefenses();
	  bool nbDefensesOk = engine::Combat::verifNbDefenses (nbDefenses, paysAttaque, state);
	  while(!nbDefensesOk){
	    nbDefenses = aiNbDesLancersDefenses();
	    nbDefensesOk = engine::Combat::verifNbDefenses (nbDefenses, paysAttaque, state);
	  }
		std::cout << "La défense lance " << nbDefenses << " dés." << std::endl;

		//etape 6 du jeu
	  std::vector<int> desBleus = engine::Combat::lancerDes(nbDefenses);

	  //etape 7 du jeu
	  bool victoire = engine::IssueDuCombat::victoire (desRouges, desBleus, paysAttaquant,paysAttaque, state);

		//etape 8 du jeu
	  aiGainCartes (idJoueur, victoire, state);
	  int nouvellesArmees = engine::GainCombat::gainArmees (idJoueur, state);

		//etape 9 du jeu
	  int echange = aiEchange (idJoueur, state);
	  while (echange == -1){
	    echange = aiEchange (idJoueur, state);
	  }
	  nouvellesArmees += echange;
		std::cout << "L'échange des cartes rapporte " << echange << " armées." << std::endl;

	  //etape 10 du jeu
	  aiPlacerNouvellesArmees (idJoueur, nouvellesArmees, state);
		std::cout << "Les " << nouvellesArmees << " nouvelles armées ont été placées." << std::endl;
	  aiDeplacerArmees (idJoueur, state);
		std::cout << "Le joueur a réalisé les déplacements qu'il souhaitait." << std::endl << std::endl;

	  std::cout << "Fin du tour " << numeroTour << std::endl;
		std::cout << std::endl;
}

}
