#include "RandomAI.h"

#include <algorithm>    // std::find

namespace ai{

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

  pushCommande(new engine::PlacementArmees(ptr_armee->getPays(), nombreArmees));
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
		pushCommande(new engine::Passer());
	}
	else{
		int armeeAleatoire = rand() % listeArmeeJoueur.size();
		ptr_armee = listeArmeeJoueur[armeeAleatoire]; // on choisit un pays aléatoirement
    pushCommande(new engine::ChoixPaysAttaquant(ptr_armee->getPays()));
	}
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

	pushCommande(new engine::ChoixPaysAttaque(ptr_armee->getPays()));
}

void RandomAI::aiDesAttaquant (state::State state){
  pushCommande(new engine::DesAttaquant(rand() % 3 + 1));
}

void RandomAI::aiDesAttaque (state::State state){
  pushCommande(new engine::DesAttaque(rand() % 2 + 1));
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
  pushCommande(new engine::Defausser(ptr_carte->getNumero()));
}

void RandomAI::aiEchange (state::State state){
  int decision = rand() % 2;
  if (decision == 0){
    pushCommande(new engine::Passer());
  }
  if (decision == 1){
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
    pushCommande(new engine::EchangeCartes(ptr_carte->getNumero()));
  }
}

void RandomAI::aiDeplacerArmees (state::State state){
  int decision = rand() % 2;
  if (decision == 0){
    pushCommande(new engine::Passer());
  }
  if (decision == 1){
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
    pushCommande(new engine::DeplacerArmees(listePays1[numeroPays], listePays2[numeroPays], nombreArmees));
  }
}

void RandomAI::aiTourDeJeu(state::State state){
  state.setStepId(state::DISTRIBUTION_s);
  steps.push_back(state::DISTRIBUTION_s);
  state.setArmeesPlacer(28);
  state.setNbCartes(3);

  while(!commandes.empty()){
    Commande* c = commandes.front();
    commandes.pop_front();
    state::StepId etape = state.getStepId();

    if(c->getIdCommande() == UNDO_c){
      Commande* commande_undo = undos.back();
      undos.pop_back();
      commande_undo->undo(state);
      delete(commande_undo);
      steps.pop_back();
      state.setStepId(steps.back());
    }
    else{
      switch (etape) {
        case state::DISTRIBUTION_s :
          if(c->getIdCommande() == DISTRIBUTION_c){
            c->exec(state);
            undos.push_back(c);
            state.setStepId(state::REPARTITION_ARMEES_s);
            steps.push_back(state::REPARTITION_ARMEES_s);
            std::cout << "Vous pouvez maintenant positionner vos armées." << std::endl;
          }
          break;

        case state::REPARTITION_ARMEES_s :
          if(c->getIdCommande() == PLACER_ARMEES_c){
            if(c->verif(state)){
              c->exec(state);
              undos.push_back(c);
              if (state.getArmeesPlacer() == 0){
                state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
                steps.push_back(state::CHOIX_PAYS_ATTAQUANT_s);
                std::cout << "Veuillez choisir votre pays attaquant." << std::endl;
              }
            }
          }
          break;

        case state::CHOIX_PAYS_ATTAQUANT_s :
          if(c->getIdCommande() == CHOIX_PAYS_c){
            Commande* pays_attaquant = new ChoixPaysAttaquant(c->getPays());
            if(pays_attaquant->verif(state)){
              Commande* c_avant = new ChoixPaysAttaquant(state.getPaysAttaquant());
              undos.push_back(c_avant);
              pays_attaquant->exec(state);
              state.setStepId(state::CHOIX_PAYS_ATTAQUE_s);
              steps.push_back(state::CHOIX_PAYS_ATTAQUE_s);
              std::cout << "Veuillez choisir le pays que vous souhaitez attaquer." << std::endl;
            }
          }
          if(c->getIdCommande() == PASSER_c){
            state.setStepId(state::DEPLACER_ARMEES_s);
            steps.push_back(state::DEPLACER_ARMEES_s);
            std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
          }
          break;

        case state::CHOIX_PAYS_ATTAQUE_s :
          if(c->getIdCommande() == CHOIX_PAYS_c){
            Commande* pays_attaque = new ChoixPaysAttaque(c->getPays());
            if(pays_attaque->verif(state)){
              Commande* c_avant = new ChoixPaysAttaque(state.getPaysAttaque());
              undos.push_back(c_avant);
              pays_attaque->exec(state);
              state.setStepId(state::NB_DES_ATTAQUANT_s);
              steps.push_back(state::NB_DES_ATTAQUANT_s);
              std::cout << "Avec combien d'armées souhaitez vous attaquer ?" << std::endl;
            }
          }
          break;

        case state::NB_DES_ATTAQUANT_s :
          if(c->getIdCommande() == NB_DES_c){
            Commande* des_attaquant = new DesAttaquant(c->getNbDes());
            if(des_attaquant->verif(state)){
              Commande* c_avant = new DesAttaquant(state.getNbDesAttaquant(), state.getDesRouges());
              undos.push_back(c_avant);
              des_attaquant->exec(state);
              state.setStepId(state::NB_DES_ATTAQUE_s);
              steps.push_back(state::NB_DES_ATTAQUE_s);
              std::cout << "Avec combien d'armées souhaitez vous défendre ?" << std::endl;
            }
          }
          break;

        case state::NB_DES_ATTAQUE_s :
          if(c->getIdCommande() == NB_DES_c){
            Commande* des_attaque = new DesAttaque(c->getNbDes());
            if(des_attaque->verif(state)){
              Commande* c_avant = new DesAttaque(state.getNbDesAttaque(), state.getDesBleus());
              undos.push_back(c_avant);
              des_attaque->exec(state);
              //Issue du combat
              Commande* c_suivant = new IssueDuCombat(state.getVictoire());
              undos.push_back(c_suivant);
              c_suivant->exec(state);
              if (state.getVictoire() == 0){
                state.setStepId(state::ECHANGE_s);
                steps.push_back(state::ECHANGE_s);
                state.setNbCartes(3);
                std::cout << "Vous pouvez maintenant échanger des cartes contre des armées." << std::endl;
              }
              else{
                std::cout << "Votre victoire vous rapporte une nouvelle carte." << std::endl;
                if(IssueDuCombat::nbCartesJoueur(state) == 5){
                  state.setStepId(state::DEFAUSSER_s);
                  steps.push_back(state::DEFAUSSER_s);
                  std::cout << "Veuillez d'abord défausser une carte." << std::endl;
                }
                else{
                  state.setStepId(state::PIOCHER_s);
                  steps.push_back(state::PIOCHER_s);
                  std::cout << "Veuillez piocher une carte." << std::endl;
                }
              }
            }
          }
          break;

        case state::DEFAUSSER_s :
          if(c->getIdCommande() == DEFAUSSER_c){
            c->exec(state);
            Commande* c_avant = new Defausser(c->getNumeroCarte());
            undos.push_back(c_avant);
            state.setStepId(state::PIOCHER_s);
            steps.push_back(state::PIOCHER_s);
            std::cout << "Veuillez piocher une carte." << std::endl;
          }
          break;

        case state::PIOCHER_s :
          if(c->getIdCommande() == PIOCHER_c){
            c->exec(state);
            Commande* c_avant = new Piocher(c->getNumeroCarte());
            undos.push_back(c_avant);

            if(IssueDuCombat::nbCartesJoueur(state) >= 3){
              state.setStepId(state::ECHANGE_s);
              steps.push_back(state::ECHANGE_s);
              state.setNbCartes(3);
              std::cout << "Vous pouvez maintenant échanger des cartes contre des armées." << std::endl;
              std::cout << "3 soldats = 3 armées" << std::endl;
              std::cout << "3 tanks = 5 armées" << std::endl;
              std::cout << "3 canons = 8 armées" << std::endl;
            }
            else{
              state.setStepId(state::DEPLACER_ARMEES_s);
              steps.push_back(state::DEPLACER_ARMEES_s);
              std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
            }
          }
          break;

        case state::ECHANGE_s :
          if(c->getIdCommande() == PASSER_c){
            state.setStepId(state::DEPLACER_ARMEES_s);
            steps.push_back(state::DEPLACER_ARMEES_s);
            std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
          }
          if(c->getIdCommande() == ECHANGE_c){
            if(c->verif(state)){
              c->exec(state);
              undos.push_back(c);

              if (state.getNbCartes() == 0){
                state.setArmeesPlacer(EchangeCartes::gain(state));
              }

              if (state.getArmeesPlacer() == 0){
                state.setStepId(state::DEPLACER_ARMEES_s);
                steps.push_back(state::DEPLACER_ARMEES_s);
                std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
              }
              else{
                state.setStepId(state::PLACER_NOUVELLES_ARMEES_s);
                steps.push_back(state::PLACER_NOUVELLES_ARMEES_s);
                std::cout << "Vous pouvez maintenant placer vos nouvelles armées." << std::endl;
              }
            }
          }
          break;

        case state::PLACER_NOUVELLES_ARMEES_s :
          if(c->getIdCommande() == PLACER_ARMEES_c){
            if(c->verif(state)){
              c->exec(state);
              undos.push_back(c);
              if (state.getArmeesPlacer() == 0){
                state.setStepId(state::DEPLACER_ARMEES_s);
                steps.push_back(state::DEPLACER_ARMEES_s);
                std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
              }
            }
          }
          break;

        case state::DEPLACER_ARMEES_s :
          if(c->getIdCommande() == DEPLACER_ARMEES_c){
            if(c->verif(state)){
              c->exec(state);
              undos.push_back(c);
            }
          }
          if(c->getIdCommande() == PASSER_c){
            Commande* fin = new FinTour();
            fin->exec(state);
            undos.push_back(fin);
            state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
            steps.push_back(state::CHOIX_PAYS_ATTAQUANT_s);
            std::cout << "Fin du tour. Début du tour " << state.getTourId() << "." << std::endl;
            std::cout << "C'est au joueur " << state.getIdJoueur() << " de jouer." << std::endl;
          }
          break;
      }
    }
    delete(c);
  }
}

}
