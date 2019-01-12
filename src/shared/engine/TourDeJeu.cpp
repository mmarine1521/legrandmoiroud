#include "TourDeJeu.h"

#include <memory>
#include <iostream>
#include <map>
#include <algorithm>    // std::find

namespace engine {

std::list<Commande*> TourDeJeu::commandes;
std::list<Commande*> TourDeJeu::undos;
std::list<state::StepId> TourDeJeu::steps;

TourDeJeu::TourDeJeu(){
}

TourDeJeu::~TourDeJeu (){
}

void TourDeJeu::pushCommande (Commande* commande){
  commandes.push_back(commande);
}

void TourDeJeu::placementJoueur3 (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  std::vector<state::Element*> listeArmeeJoueur;

  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ptr_pays = 0;
  state::Element* ptr_paysFrontalier = 0;
  std::vector<state::Element*> listePaysJoueur;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getIdJoueur() == 3){
      listeArmeeJoueur.push_back(ptr_armee); // remplit la liste des armees appartenant au joueur
    }
  }

  for(size_t j=0; j<listeArmeeJoueur.size(); j++){
    ptr_armee = listeArmeeJoueur[j];
    for(size_t i=0; i<listePays.size(); i++){
      ptr_pays = listePays[i].get();
      if (ptr_pays->getPays() == ptr_armee->getPays()){
        listePaysJoueur.push_back(ptr_pays); // remplit la liste des pays appartenant au joueur
        break;
      }
    }
  }

  std::map<std::string, int> nbFrontaliers;
  int compt;
  for(size_t i=0; i<listePaysJoueur.size(); i++){
    ptr_pays = listePaysJoueur[i];
    compt = 0;
    for(size_t j=0; j<listePaysJoueur.size(); j++){
      if (i != j){
        ptr_paysFrontalier = listePaysJoueur[j];
        if (ChoixPaysAttaque::estFrontalier(ptr_pays->getPays(), ptr_paysFrontalier->getPays(), state)){
          compt ++;
        }
      }
    }
    nbFrontaliers[ptr_pays->getPays()] = compt; // remplit la map nomPays / nbDeSesFrontaliers
  }

  int maxi = 0;
  for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
    if (it->second > maxi){
      maxi = it->second;
    }
  }

  int mini = 100;
  std::string paysMini;
  for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
    it->second = maxi - it->second + 1;
    if (it->second < mini){
      mini = it->second;
      paysMini = it->first;
    }
  }

  while(state.getArmeesRepartition(3) != 0){
    nbFrontaliers[paysMini] += 1;
    state.setArmeesRepartition(3, state.getArmeesRepartition(3) - 1);
    mini = 100;
    for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
      if (it->second < mini){
        mini = it->second;
        paysMini = it->first;
      }
    }
  }

  for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
    TourDeJeu::pushCommande(new PlacementArmees(3, it->first, it->second));
  }
}

void TourDeJeu::run (state::State& state){
  while(!commandes.empty()){
    Commande* c = commandes.front();
    commandes.pop_front();
    state::StepId etape = state.getStepId();
    int joueur = state.getIdJoueur();

    if(c->getIdCommande() == UNDO_c){
      if(c->getIdJoueur() == joueur){
        Commande* commande_undo = undos.back();
        undos.pop_back();
        commande_undo->undo(state);
        delete(commande_undo);
        steps.pop_back();
        state.setStepId(steps.back());
      }
    }
    else{
      switch (etape) {
        case state::DISTRIBUTION_s :
          if(c->getIdCommande() == DISTRIBUTION_c){
            c->exec(state);
            undos.push_back(c);
            state.setStepId(state::REPARTITION_ARMEES_s);
            steps.push_back(state::REPARTITION_ARMEES_s);
            //ai::HeuristicAI intelligence = ai::HeuristicAI(3);
            //intelligence.aiRepartitionArmees(state);
            placementJoueur3(state);
            std::cout << "Vous pouvez maintenant positionner vos armées." << std::endl;
          }
          break;

        case state::REPARTITION_ARMEES_s :
          if(c->getIdCommande() == PLACER_ARMEES_c){
            if(c->getIdJoueur() == 1){
              if (state.getArmeesRepartition(1) != 0){
                if(c->verif(state)){
                  c->exec(state);
                  undos.push_back(c);
                }
              }
            }
            if(c->getIdJoueur() == 2){
              if (state.getArmeesRepartition(2) != 0){
                if(c->verif(state)){
                  c->exec(state);
                  undos.push_back(c);
                }
              }
            }
            //joueur 3
            if (state.getArmeesRepartition(1) == 0 && state.getArmeesRepartition(2) == 0){
              state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
              steps.push_back(state::CHOIX_PAYS_ATTAQUANT_s);
              std::cout << "Veuillez choisir votre pays attaquant." << std::endl;
            }
          }
          break;

        case state::CHOIX_PAYS_ATTAQUANT_s :
          if(c->getIdCommande() == CHOIX_PAYS_ATTAQUANT_c){
            if(c->getIdJoueur() == joueur){
              if(c->verif(state)){
                Commande* c_avant = new ChoixPaysAttaquant(c->getIdJoueur(), state.getPaysAttaquant());
                undos.push_back(c_avant);
                c->exec(state);
                state.clearBlackList();
                state.setStepId(state::CHOIX_PAYS_ATTAQUE_s);
                steps.push_back(state::CHOIX_PAYS_ATTAQUE_s);
                std::cout << "Veuillez choisir le pays que vous souhaitez attaquer." << std::endl;
              }
              else{
                state.setBlackList(c->getPays());
              }
            }
          }
          if(c->getIdCommande() == PASSER_c){
            if(c->getIdJoueur() == joueur){
              state.clearBlackList();
              state.setStepId(state::DEPLACER_ARMEES_s);
              steps.push_back(state::DEPLACER_ARMEES_s);
              std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
            }
          }
          break;

        case state::CHOIX_PAYS_ATTAQUE_s :
          if(c->getIdCommande() == CHOIX_PAYS_ATTAQUE_c){
            if(c->getIdJoueur() == joueur){
              if(c->verif(state)){
                Commande* c_avant = new ChoixPaysAttaque(c->getIdJoueur(), state.getPaysAttaque());
                undos.push_back(c_avant);
                c->exec(state);
                state.setStepId(state::NB_DES_ATTAQUANT_s);
                steps.push_back(state::NB_DES_ATTAQUANT_s);
                std::cout << "Avec combien d'armées souhaitez vous attaquer ?" << std::endl;
              }
            }
          }
          break;

        case state::NB_DES_ATTAQUANT_s :
          if(c->getIdCommande() == NB_DES_ATTAQUANT_c){
            if(c->getIdJoueur() == joueur){
              if(c->verif(state)){
                Commande* c_avant = new DesAttaquant(c->getIdJoueur(), state.getNbDesAttaquant(), state.getDesRouges());
                undos.push_back(c_avant);
                c->exec(state);
                state.setStepId(state::NB_DES_ATTAQUE_s);
                steps.push_back(state::NB_DES_ATTAQUE_s);
                std::cout << "Avec combien d'armées souhaitez vous défendre ?" << std::endl;
              }
            }
          }
          break;

        case state::NB_DES_ATTAQUE_s :
          if(c->getIdCommande() == NB_DES_ATTAQUE_c){
            if(c->getIdJoueur() != joueur){
              if(c->verif(state)){
                Commande* c_avant = new DesAttaque(c->getIdJoueur(), state.getNbDesAttaque(), state.getDesBleus());
                undos.push_back(c_avant);
                c->exec(state);
                //Issue du combat
                Commande* c_suivant = new IssueDuCombat(c->getIdJoueur(), state.getVictoire());
                undos.push_back(c_suivant);
                c_suivant->exec(state);
                if (state.getVictoire() == 0){
                  state.setStepId(state::ECHANGE_s);
                  steps.push_back(state::ECHANGE_s);
                  state.setNbCartes(3);
                  state.clearTypeCarte();
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
          }
          break;

        case state::DEFAUSSER_s :
          if(c->getIdCommande() == DEFAUSSER_c){
            if(c->getIdJoueur() == joueur){
              c->exec(state);
              undos.push_back(c);
              state.setStepId(state::PIOCHER_s);
              steps.push_back(state::PIOCHER_s);
              std::cout << "Veuillez piocher une carte." << std::endl;
            }
          }
          break;

        case state::PIOCHER_s :
          if(c->getIdCommande() == PIOCHER_c){
            if(c->getIdJoueur() == joueur){
              c->exec(state);
              Commande* c_avant = new Piocher(c->getIdJoueur(), c->getNumeroCarte());
              undos.push_back(c_avant);

              if(IssueDuCombat::nbCartesJoueur(state) >= 3){
                state.setStepId(state::ECHANGE_s);
                steps.push_back(state::ECHANGE_s);
                state.setNbCartes(3);
                state.clearTypeCarte();
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
          }
          break;

        case state::ECHANGE_s :
          if(c->getIdCommande() == PASSER_c){
            if(c->getIdJoueur() == joueur){
              state.setStepId(state::DEPLACER_ARMEES_s);
              steps.push_back(state::DEPLACER_ARMEES_s);
              std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
            }
          }
          if(c->getIdCommande() == ECHANGE_c){
            if(c->getIdJoueur() == joueur){
              if(c->verif(state)){
                c->exec(state);
                undos.push_back(c);

                if (state.getNbCartes() == 0){
                  state.setArmeesRepartition(joueur, EchangeCartes::gain(state));
                  if (state.getArmeesRepartition(joueur) == 0){
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
            }
          }
          break;

        case state::PLACER_NOUVELLES_ARMEES_s :
          if(c->getIdCommande() == PLACER_ARMEES_c){
            if(c->getIdJoueur() == joueur){
              if(c->verif(state)){
                c->exec(state);
                undos.push_back(c);
                if (state.getArmeesRepartition(joueur) == 0){
                  state.setStepId(state::DEPLACER_ARMEES_s);
                  steps.push_back(state::DEPLACER_ARMEES_s);
                  std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
                }
              }
            }
          }
          break;

        case state::DEPLACER_ARMEES_s :
          if(c->getIdCommande() == DEPLACER_ARMEES_c){
            if(c->getIdJoueur() == joueur){
              if(c->verif(state)){
                c->exec(state);
                undos.push_back(c);
              }
            }
          }
          if(c->getIdCommande() == PASSER_c){
            if(c->getIdJoueur() == joueur){
              Commande* fin = new FinTour(c->getIdJoueur());
              fin->exec(state);
              undos.push_back(fin);
              state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
              steps.push_back(state::CHOIX_PAYS_ATTAQUANT_s);
              std::cout << "Fin du tour. Début du tour " << state.getTourId() << "." << std::endl;
              std::cout << "C'est au joueur " << state.getIdJoueur() << " de jouer." << std::endl;
            }
          }
          break;
      }
    }
    delete(c);
  }
}

}
