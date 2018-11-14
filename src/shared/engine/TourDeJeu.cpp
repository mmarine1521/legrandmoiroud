#include "TourDeJeu.h"

#include <memory>
#include <iostream>

namespace engine {

void TourDeJeu::jouer (int numeroTour, int idJoueur, state::State state){
  std::cout << "Début du tour " << numeroTour << std::endl;

  //initialisation du jeu
  if (numeroTour == 0){
    //etape 2 de l'initialisation
    AttributionTerritoires::distribution(state, 3);

    //etape 3 de l'initialisation
    /*
    std::cout << "Le joueur 1 place ses armées." << std::endl;
    bool distributionOk = AttributionTerritoires::repartitionArmees(1, state);
    while (!distributionOk){
      std::cout << "Le joueur 1 doit replacer ses armées." << std::endl;
      AttributionTerritoires::undoRepartitionArmees(1, state);
      distributionOk = AttributionTerritoires::repartitionArmees(1, state);
    }

    std::cout << "Le joueur 2 place ses armées." << std::endl;
    distributionOk = AttributionTerritoires::repartitionArmees(2, state);
    while (!distributionOk){
      std::cout << "Le joueur 2 doit replacer ses armées." << std::endl;
      AttributionTerritoires::undoRepartitionArmees(2, state);
      distributionOk = AttributionTerritoires::repartitionArmees(2, state);
    }

    std::cout << "Le joueur fictif 3 place ses armées." << std::endl;
    distributionOk = AttributionTerritoires::repartitionArmees(3, state);
    while (!distributionOk){
      std::cout << "Le joueur fictif 3 doit replacer ses armées." << std::endl;
      AttributionTerritoires::undoRepartitionArmees(3, state);
      distributionOk = AttributionTerritoires::repartitionArmees(3, state);
    }*/
    state::ElementTab& tabArmee = state.getArmeeTab();
  	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  	state::Element* ptr_armee = 0;

    std::vector<state::Element*> listeArmeeJoueur1;
    std::vector<state::Element*> listeArmeeJoueur2;
    std::vector<state::Element*> listeArmeeJoueur3;
  	for(size_t i=0; i<listeArmee.size(); i++){
  		ptr_armee = listeArmee[i].get();
  		if(ptr_armee->getIdJoueur()==1){
        listeArmeeJoueur1.push_back(ptr_armee);
  			ptr_armee->setNombre(3);
  		}
      else if (ptr_armee->getIdJoueur()==2){
        listeArmeeJoueur2.push_back(ptr_armee);
  			ptr_armee->setNombre(3);
      }
      else if (ptr_armee->getIdJoueur()==3){
        listeArmeeJoueur3.push_back(ptr_armee);
  			ptr_armee->setNombre(3);
      }
  	}

  	srand (time(NULL));
  	int armeeAleatoire1 = rand() % listeArmeeJoueur1.size();
  	int armeeAleatoire2 = -1;
  	while(armeeAleatoire2 == -1 || armeeAleatoire2 == armeeAleatoire1){
  		armeeAleatoire2 = rand() % listeArmeeJoueur1.size();
  	}

  	ptr_armee = listeArmeeJoueur1[armeeAleatoire1];
  	ptr_armee->setNombre(2);
  	ptr_armee = listeArmeeJoueur1[armeeAleatoire2];
  	ptr_armee->setNombre(2);

    ptr_armee = listeArmeeJoueur2[armeeAleatoire1];
  	ptr_armee->setNombre(2);
  	ptr_armee = listeArmeeJoueur2[armeeAleatoire2];
  	ptr_armee->setNombre(2);

    ptr_armee = listeArmeeJoueur3[armeeAleatoire1];
  	ptr_armee->setNombre(2);
  	ptr_armee = listeArmeeJoueur3[armeeAleatoire2];
  	ptr_armee->setNombre(2);
    std::cout << "Attribution des armées ok" << std::endl << std::endl;
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
  bool victoire = IssueDuCombat::victoire (desRouges, desBleus, paysAttaquant,paysAttaque, state);

  //etape 8 du jeu
  GainCombat::gainCartes (idJoueur, victoire, state);
  int nouvellesArmees = GainCombat::gainArmees (idJoueur, state);

  //etape 9 du jeu
  int echange = EchangeCartes::echange (idJoueur, state);
  while (echange == -1){
    std::cout << "L'échange n'a pas pu être réalisé." << std::endl;
    echange = EchangeCartes::echange (idJoueur, state);
  }
  nouvellesArmees += echange;

  //etape 10 du jeu
  PlacementArmees::placerNouvellesArmees (idJoueur, nouvellesArmees, state);
  PlacementArmees::deplacerArmees (idJoueur, state);

  std::cout << "Fin du tour " << numeroTour << std::endl;
}

}
