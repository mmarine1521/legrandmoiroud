#include "TourDeJeu.h"

#include <memory>
#include <iostream>
#include <list>

namespace engine {


std::list<Commande*> TourDeJeu::commandes;
std::list<Commande*> TourDeJeu::undos;

TourDeJeu::~TourDeJeu (){
}

void TourDeJeu::pushCommande (Commande* commande){
  commandes.push_back(commande);
}

void TourDeJeu::pushUndo (Commande* commande){
  undos.push_back(commande);
}

void TourDeJeu::run (state::State state){
  //creation state

  int armees_repartition = 28;
  int nbCartes = 3;
  int armees_placer = 0;

  while(!commandes.empty()){
    Commande* c = commandes.front();
    commandes.pop_front();
    state::StepId etape = state.getStepId();

    if(c->getIdCommande() == UNDO_c){
      Commande* commande_undo = undos.back();
      undos.pop_back();
      commande_undo->undo(state);
    } //finir le tour de boucle ici ?

    switch (etape) {
      case state::DISTRIBUTION_s :
        if(c->getIdCommande() == DISTRIBUTION_c){
          c->exec(state);
          pushUndo(c);
          state.setStepId(state::REPARTITION_ARMEES_s);
          std::cout << "Vous pouvez maintenant positionner vos armées." << std::endl;
        }
        break;

      case state::REPARTITION_ARMEES_s :
        if(c->getIdCommande() == PLACER_ARMEES_c){
          if(c->verif(state)){
            if (c->getNbArmees() > armees_repartition){
              c->setNbArmees(armees_repartition);
            }
            c->exec(state);
            pushUndo(c);
            armees_repartition -= c->getNbArmees();
            if (armees_repartition == 0){
              state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
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
            pushUndo(c_avant);
            pays_attaquant->exec(state);
            state.setStepId(state::CHOIX_PAYS_ATTAQUE_s);
            std::cout << "Veuillez choisir le pays que vous souhaitez attaquer." << std::endl;
          }
        }
        break;

      case state::CHOIX_PAYS_ATTAQUE_s :
        if(c->getIdCommande() == CHOIX_PAYS_c){
          Commande* pays_attaque = new ChoixPaysAttaque(c->getPays());
          if(pays_attaque->verif(state)){
            Commande* c_avant = new ChoixPaysAttaque(state.getPaysAttaque());
            pushUndo(c_avant);
            pays_attaque->exec(state);
            state.setStepId(state::NB_DES_ATTAQUANT_s);
            std::cout << "Avec combien d'armées souhaitez vous attaquer ?" << std::endl;
          }
        }
        break;

      case state::NB_DES_ATTAQUANT_s :
        if(c->getIdCommande() == NB_DES_c){
          Commande* des_attaquant = new DesAttaquant(c->getNbDes());
          if(des_attaquant->verif(state)){
            Commande* c_avant = new DesAttaquant(state.getNbDesAttaquant(), state.getDesRouges());
            pushUndo(c_avant);
            des_attaquant->exec(state);
            state.setStepId(state::NB_DES_ATTAQUE_s);
            std::cout << "Avec combien d'armées souhaitez vous défendre ?" << std::endl;
          }
        }
        break;

      case state::NB_DES_ATTAQUE_s :
        if(c->getIdCommande() == NB_DES_c){
          Commande* des_attaque = new DesAttaque(c->getNbDes());
          if(des_attaque->verif(state)){
            Commande* c_avant = new DesAttaque(state.getNbDesAttaque(), state.getDesBleus());
            pushUndo(c_avant);
            des_attaque->exec(state);
            //Issue du combat
            Commande* c_suivant = new IssueDuCombat(state.getVictoire());
            pushUndo(c_suivant);
            c_suivant->exec(state);
            if (state.getVictoire() == 0){
              state.setStepId(state::ECHANGE_s);
              std::cout << "Vous pouvez maintenant échanger des cartes contre des armées." << std::endl;
            }
            else{
              std::cout << "Votre victoire vous rapporte une nouvelle carte." << std::endl;
              if(IssueDuCombat::nbCartesJoueur(state) == 5){
                state.setStepId(state::DEFAUSSER_s);
                std::cout << "Veuillez d'abord défausser une carte." << std::endl;
              }
              else{
                state.setStepId(state::PIOCHER_s);
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
          pushUndo(c_avant);
          state.setStepId(state::PIOCHER_s);
          std::cout << "Veuillez piocher une carte." << std::endl;
        }
        break;

      case state::PIOCHER_s :
        if(c->getIdCommande() == PIOCHER_c){
          c->exec(state);
          Commande* c_avant = new Piocher(c->getNumeroCarte());
          pushUndo(c_avant);

          if(IssueDuCombat::nbCartesJoueur(state) >= 3){
            state.setStepId(state::ECHANGE_s);
            std::cout << "Vous pouvez maintenant échanger des cartes contre des armées." << std::endl;
            std::cout << "3 soldats = 3 armées" << std::endl;
            std::cout << "3 tanks = 5 armées" << std::endl;
            std::cout << "3 canons = 8 armées" << std::endl;
          }
          else{
            state.setStepId(state::DEPLACER_ARMEES_s);
            std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
          }
        }
        break;

      case state::ECHANGE_s :
        if(c->getIdCommande() == PASSER_c){
          armees_placer = 0;
          state.setStepId(state::DEPLACER_ARMEES_s);
          std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
        }
        if(c->getIdCommande() == ECHANGE_c){
          if(c->verif(state)){
            c->exec(state);
            pushUndo(c);
            nbCartes -= 1;

            if (nbCartes == 0){
              armees_placer = EchangeCartes::gain(state);
            }

            if (armees_placer == 0){
              state.setStepId(state::DEPLACER_ARMEES_s);
              std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
            }
            else{
              state.setStepId(state::PLACER_NOUVELLES_ARMEES_s);
              std::cout << "Vous pouvez maintenant placer vos nouvelles armées." << std::endl;
            }
          }
        }
        break;

      case state::PLACER_NOUVELLES_ARMEES_s :
        if(c->getIdCommande() == PLACER_ARMEES_c){
          if(c->verif(state)){
            if (c->getNbArmees() > armees_placer){
              c->setNbArmees(armees_placer);
            }
            c->exec(state);
            pushUndo(c);
            armees_placer -= c->getNbArmees();
            if (armees_placer == 0){
              state.setStepId(state::DEPLACER_ARMEES_s);
              std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
            }
          }
        }
        break;

      case state::DEPLACER_ARMEES_s :
        if(c->getIdCommande() == PASSER_c){
          armees_placer = 0;
          state.setStepId(state::DEPLACER_ARMEES_s);
          std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
        }
        if(c->getIdCommande() == DEPLACER_ARMEES_c){
          if(c->verif(state)){
            c->exec(state);
            pushUndo(c);
          }
        }
        if(c->getIdCommande() == FIN_c){
          c->exec(state);
          pushUndo(c);
          state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
          std::cout << "Fin du tour. Début du tour " << state.getTourId() << "." << std::endl;
          std::cout << "C'est au joueur " << state.getIdJoueur() << " de jouer." << std::endl;
          nbCartes = 3;
        }
        break;
    }
  }
}

/*
void TourDeJeu::jouer (int numeroTour, int idJoueur, state::State state, sf::RenderWindow& window, sf::Event event){
  std::cout << "Début du tour " << numeroTour << std::endl;
  std::cout << std::endl;

  //initialisation du jeu
  if (numeroTour == 0){
    //etape 2 de l'initialisation
    AttributionTerritoires::distribution(state, 3);

    //etape 3 de l'initialisation
    std::cout << "Le joueur 1 place ses armées." << std::endl;
    bool distributionOk = AttributionTerritoires::repartitionArmees(1, state, window,event);
    while (!distributionOk){
      std::cout << "Le joueur 1 doit replacer ses armées." << std::endl;
      AttributionTerritoires::undoRepartitionArmees(1, state);
      distributionOk = AttributionTerritoires::repartitionArmees(1, state, window,event);
    }

    std::cout << "Le joueur 2 place ses armées." << std::endl;
    distributionOk = AttributionTerritoires::repartitionArmees(2, state, window,event);
    while (!distributionOk){
      std::cout << "Le joueur 2 doit replacer ses armées." << std::endl;
      AttributionTerritoires::undoRepartitionArmees(2, state);
      distributionOk = AttributionTerritoires::repartitionArmees(2, state, window,event);
    }

    std::cout << "Le joueur fictif 3 place ses armées." << std::endl;
    distributionOk = AttributionTerritoires::repartitionArmees(3, state, window,event);
    while (!distributionOk){
      std::cout << "Le joueur fictif 3 doit replacer ses armées." << std::endl;
      AttributionTerritoires::undoRepartitionArmees(3, state);
      distributionOk = AttributionTerritoires::repartitionArmees(3, state, window,event);
    }
  }

    //etape 1 du jeu
    std::string paysAttaquant = ChoixPays::choixPaysAttaquant();
    bool verifPaysAttaquantOk = ChoixPays::verifPaysAttaquant(idJoueur, paysAttaquant, state);
    while(!verifPaysAttaquantOk){
      std::cout << "Veuillez choisir un autre pays." << std::endl;
      paysAttaquant = ChoixPays::choixPaysAttaquant();
      verifPaysAttaquantOk = ChoixPays::verifPaysAttaquant(idJoueur, paysAttaquant, state);
    }

    //etape 2 du jeu
    std::string paysAttaque = ChoixPays::choixPaysAttaque();
    bool verifPaysAttaqueOk = ChoixPays::verifPaysAttaque(idJoueur, paysAttaque, paysAttaquant, state);
    while(!verifPaysAttaqueOk){
      std::cout << "Veuillez choisir un autre pays." << std::endl;
      paysAttaque = ChoixPays::choixPaysAttaque();
      verifPaysAttaqueOk = ChoixPays::verifPaysAttaque(idJoueur, paysAttaque, paysAttaquant, state);
    }

    //etape 3 du jeu
    std::cout << "C'est l'heure de l'attaque !" << std::endl;
    int nbAttaques = Combat::nbDesLances();
    bool nbAttaquesOk = Combat::verifNbAttaques (nbAttaques, paysAttaquant, state);
    while(!nbAttaquesOk){
      std::cout << "Veuillez choisir un nombre de dés adéquat." << std::endl;
      nbAttaques = Combat::nbDesLances();
      nbAttaquesOk = Combat::verifNbAttaques (nbAttaques, paysAttaquant, state);
    }

    //etape 5 du jeu
    std::vector<int> desRouges = Combat::lancerDes(nbAttaques); //mis avant sinon pas une seconde d'écart pour le srand

    //etape 4 du jeu
    std::cout << "L'adversaire se défend." << std::endl;
    int nbDefenses = Combat::nbDesLances();
    bool nbDefensesOk = Combat::verifNbDefenses (nbDefenses, paysAttaque, state);
    while(!nbDefensesOk){
      std::cout << "Veuillez choisir un nombre de dés adéquat." << std::endl;
      nbDefenses = Combat::nbDesLances();
      nbDefensesOk = Combat::verifNbDefenses (nbDefenses, paysAttaque, state);
    }

    //etape 6 du jeu
    std::vector<int> desBleus = Combat::lancerDes(nbDefenses);

    //etape 7 du jeu
    int victoire = IssueDuCombat::victoire (desRouges, desBleus, paysAttaquant,paysAttaque, state);

    //etape 8 du jeu
    GainCombat::gainCartes (idJoueur, victoire, state);

    //etape 9 du jeu
    int nouvellesArmees = EchangeCartes::echange (idJoueur, state);
    while (nouvellesArmees == -1){
      std::cout << "L'échange n'a pas pu être réalisé." << std::endl;
      nouvellesArmees = EchangeCartes::echange (idJoueur, state);
    }

    //etape 10 du jeu
    PlacementArmees::placerNouvellesArmees (idJoueur, nouvellesArmees, state, window,event);
    PlacementArmees::deplacerArmees (idJoueur, state);

    std::cout << "Fin du tour " << numeroTour << std::endl;
    std::cout << std::endl;
}*/

}
