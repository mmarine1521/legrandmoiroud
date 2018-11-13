#include "TourDeJeu.h"

#include <memory>
#include <iostream>

namespace engine {

void TourDeJeu::jouer (int numeroTour, int idJoueur, state::State currentState){
  std::cout << "Début du tour " << numeroTour << std::endl;

  //initialisation du jeu
  if (numeroTour == 0){
    //etape 2 de l'initialisation
    AttributionTerritoires::distribution(currentState, 3);

    //etape 3 de l'initialisation
    std::cout << "Le joueur 1 place ses armées." << std::endl;
    bool distributionOk = AttributionTerritoires::repartitionArmees(1, currentState);
    while (!distributionOk){
      std::cout << "Le joueur 1 doit replacer ses armées." << std::endl;
      distributionOk = AttributionTerritoires::repartitionArmees(1, currentState);
    }

    std::cout << "Le joueur 2 place ses armées." << std::endl;
    distributionOk = AttributionTerritoires::repartitionArmees(2, currentState);
    while (!distributionOk){
      std::cout << "Le joueur 2 doit replacer ses armées." << std::endl;
      distributionOk = AttributionTerritoires::repartitionArmees(2, currentState);
    }

    std::cout << "Le joueur fictif 3 place ses armées." << std::endl;
    distributionOk = AttributionTerritoires::repartitionArmees(3, currentState);
    while (!distributionOk){
      std::cout << "Le joueur fictif 3 doit replacer ses armées." << std::endl;
      distributionOk = AttributionTerritoires::repartitionArmees(1, currentState);
    }
  }

  //etape 1 du jeu
  std::string paysAttaquant = ChoixPays::choixPaysAttaquant();
  bool verifPaysAttaquantOk = ChoixPays::verifPaysAttaquant(idJoueur, paysAttaquant, currentState);
  while(!verifPaysAttaquantOk){
    std::cout << "Veuillez choisir un autre pays." << std::endl;
    paysAttaquant = ChoixPays::choixPaysAttaquant();
    verifPaysAttaquantOk = ChoixPays::verifPaysAttaquant(idJoueur, paysAttaquant, currentState);
  }

  //etape 2 du jeu
  std::string paysAttaque = ChoixPays::choixPaysAttaque();
  bool verifPaysAttaqueOk = ChoixPays::verifPaysAttaque(idJoueur, paysAttaque, paysAttaquant, currentState);
  while(!verifPaysAttaqueOk){
    std::cout << "Veuillez choisir un autre pays." << std::endl;
    paysAttaque = ChoixPays::choixPaysAttaque();
    verifPaysAttaqueOk = ChoixPays::verifPaysAttaque(idJoueur, paysAttaque, paysAttaquant, currentState);
  }

  //etape 3 du jeu
  std::cout << "C'est l'heure de l'attaque !" << std::endl;
  int nbAttaques = Combat::nbDesLances();
  bool nbAttaquesOk = Combat::verifNbAttaques (nbAttaques, paysAttaquant, currentState);
  while(!nbAttaquesOk){
    std::cout << "Veuillez choisir un nombre de dés adéquat." << std::endl;
    nbAttaques = Combat::nbDesLances();
    nbAttaquesOk = Combat::verifNbAttaques (nbAttaques, paysAttaquant, currentState);
  }

  //etape 4 du jeu
  std::cout << "L'adversaire se défend." << std::endl;
  int nbDefenses = Combat::nbDesLances();
  bool nbDefensesOk = Combat::verifNbAttaques (nbDefenses, paysAttaque, currentState);
  while(!nbDefensesOk){
    std::cout << "Veuillez choisir un nombre de dés adéquat." << std::endl;
    nbDefenses = Combat::nbDesLances();
    nbDefensesOk = Combat::verifNbAttaques (nbDefenses, paysAttaque, currentState);
  }

  //etape 5 du jeu
  std::vector<int> desRouges = Combat::lancerDes(nbAttaques);

  //etape 6 du jeu
  std::vector<int> desBleus = Combat::lancerDes(nbDefenses);

  //etape 7 du jeu
  bool victoire = IssueDuCombat::victoire (desRouges, desBleus, paysAttaquant,paysAttaque, currentState);

  //etape 8 du jeu
  GainCombat::gainCartes (idJoueur, victoire, currentState);
  int nouvellesArmees = GainCombat::gainArmees (idJoueur, currentState);

  //etape 9 du jeu
  int echange = EchangeCartes::echange (idJoueur, currentState);
  while (echange == -1){
    std::cout << "L'échange n'a pas pu être réalisé." << std::endl;
    echange = EchangeCartes::echange (idJoueur, currentState);
  }
  nouvellesArmees += echange;

  //etape 10 du jeu
  PlacementArmees::placerNouvellesArmees (idJoueur, nouvellesArmees, currentState);
  PlacementArmees::deplacerArmees (idJoueur, currentState);

  std::cout << "Fin du tour " << numeroTour << std::endl;
}

}
