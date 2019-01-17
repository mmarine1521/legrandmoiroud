#include "TourDeJeu.h"

#include <memory>
#include <iostream>
#include <map>
#include <algorithm>    // std::find
#include <fstream>
#include <stdio.h>
#include <string.h>

namespace engine {

std::list<Commande*> TourDeJeu::commandes;
std::list<Commande*> TourDeJeu::undos;
std::list<state::StepId> TourDeJeu::steps;

TourDeJeu::TourDeJeu(){
}

TourDeJeu::~TourDeJeu (){
}

int TourDeJeu::getSizeUndos(){
  return undos.size();
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

  PlacementArmees* placer = new PlacementArmees(3, paysMini, 1);
  while(state.getArmeesRepartition(3) != 0){
    nbFrontaliers[paysMini] += 1;
    state.setArmeesRepartition(3, state.getArmeesRepartition(3) - 1);
    placer->exec(state);
    mini = 100;
    for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
      if (it->second < mini){
        mini = it->second;
        paysMini = it->first;
      }
    }
    placer->setPays(paysMini);
  }
  delete(placer);
}

void TourDeJeu::run (state::State& state){
  while(!commandes.empty()){
    Commande* c = commandes.front();
    commandes.pop_front();
    state::StepId etape = state.getStepId();
    int joueur = state.getIdJoueur();

    if(c->getIdCommande() == UNDO_c){
      if(c->getIdJoueurCommande() == joueur){
        Commande* commande_undo = undos.back();
        undos.pop_back();
        commande_undo->undo(state);
        delete(commande_undo);
        steps.pop_back();
        state.setStepId(steps.back());
        c->writeToJson();
        delete(c);
      }
    }
    else{
      switch (etape) {
        case state::DISTRIBUTION_s :
          if(c->getIdCommande() == DISTRIBUTION_c){
            c->exec(state);
            c->writeToJson();
            steps.push_back(state::DISTRIBUTION_s);
            undos.push_back(c);
            placementJoueur3(state);
            state.setStepId(state::REPARTITION_ARMEES_s);
            steps.push_back(state::REPARTITION_ARMEES_s);
            std::cout << "Vous pouvez maintenant positionner vos armées." << std::endl;
          }
          break;

        case state::REPARTITION_ARMEES_s :
          if(c->getIdCommande() == PLACER_ARMEES_c){
            if(c->getIdJoueurCommande() == 1){
              if (state.getArmeesRepartition(1) != 0){
                if(c->verif(state)){
                  c->exec(state);
                  c->writeToJson();
                  std::cout << "Le joueur " << c->getIdJoueurCommande() << " a placé " << c->getNbArmees() << " armée sur le pays " << c->getPays() << std::endl;
                  undos.push_back(c);
                }
              }
            }
            else if(c->getIdJoueurCommande() == 2){
              if (state.getArmeesRepartition(2) != 0){
                if(c->verif(state)){
                  c->exec(state);
                  c->writeToJson();
                  undos.push_back(c);
                }
              }
            }
          }
          else if(c->getIdCommande() == COMMANDE_COMPOSITE_c){
            if(c->getIdJoueurCommande() == 1){
              c->exec(state);
              c->writeToJson();
              undos.push_back(c);
              state.setArmeesRepartition(1, 0);
            }
            else if(c->getIdJoueurCommande() == 2){
              c->exec(state);
              c->writeToJson();
              undos.push_back(c);
              state.setArmeesRepartition(2, 0);
            }
          }
          if (state.getArmeesRepartition(1) == 0 && state.getArmeesRepartition(2) == 0){
            state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
            steps.push_back(state::CHOIX_PAYS_ATTAQUANT_s);
            std::cout << "Veuillez choisir votre pays attaquant." << std::endl;
          }
          break;

        case state::CHOIX_PAYS_ATTAQUANT_s :
          if(c->getIdCommande() == CHOIX_PAYS_ATTAQUANT_c){
            if(c->getIdJoueurCommande() == joueur){
              if(c->verif(state)){
                Commande* c_avant = new ChoixPaysAttaquant(c->getIdJoueurCommande(), state.getPaysAttaquant());
                undos.push_back(c_avant);
                c->exec(state);
                c->writeToJson();
                delete(c);
                state.clearBlackList();
                std::cout << "Le pays attaquant est " << state.getPaysAttaquant() << std::endl;
                state.setStepId(state::CHOIX_PAYS_ATTAQUE_s);
                steps.push_back(state::CHOIX_PAYS_ATTAQUE_s);
                std::cout << "Veuillez choisir le pays que vous souhaitez attaquer." << std::endl;
              }
              else{
                state.setBlackList(c->getPays());
              }
            }
          }
          else if(c->getIdCommande() == PASSER_c){
            if(c->getIdJoueurCommande() == joueur){
              if (c->getFin() == 0){
                state.clearBlackList();
                std::cout << "Vous passez votre tour." << std::endl;
                state.setStepId(state::DEPLACER_ARMEES_s);
                steps.push_back(state::DEPLACER_ARMEES_s);
                delete(c);
                std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
              }
            }
          }
          break;

        case state::CHOIX_PAYS_ATTAQUE_s :
          if(c->getIdCommande() == CHOIX_PAYS_ATTAQUE_c){
            if(c->getIdJoueurCommande() == joueur){
              if(c->verif(state)){
                Commande* c_avant = new ChoixPaysAttaque(c->getIdJoueurCommande(), state.getPaysAttaque());
                undos.push_back(c_avant);
                c->exec(state);
                c->writeToJson();
                delete(c);
                std::cout << "Le pays attaqué est " << state.getPaysAttaque() << std::endl;
                state.setStepId(state::NB_DES_ATTAQUANT_s);
                steps.push_back(state::NB_DES_ATTAQUANT_s);
                std::cout << "Avec combien d'armées souhaitez vous attaquer ?" << std::endl;
              }
            }
          }
          break;

        case state::NB_DES_ATTAQUANT_s :
          if(c->getIdCommande() == NB_DES_ATTAQUANT_c){
            if(c->getIdJoueurCommande() == joueur){
              if(c->verif(state)){
                Commande* c_avant = new DesAttaquant(c->getIdJoueurCommande(), state.getNbDesAttaquant(), state.getDesRouges());
                undos.push_back(c_avant);
                c->exec(state);
                c->writeToJson();
                delete(c);
                std::cout << "Vous lancez " << state.getNbDesAttaquant() << " dé(s)" << std::endl;
                state.setStepId(state::NB_DES_ATTAQUE_s);
                steps.push_back(state::NB_DES_ATTAQUE_s);
                std::cout << "Avec combien d'armées souhaitez vous défendre ?" << std::endl;
              }
            }
          }
          break;

        case state::NB_DES_ATTAQUE_s :
          if(c->getIdCommande() == NB_DES_ATTAQUE_c){
            if(c->getIdJoueurCommande() != joueur){
              if(c->verif(state)){
                Commande* c_avant = new DesAttaque(c->getIdJoueurCommande(), state.getNbDesAttaque(), state.getDesBleus());
                undos.push_back(c_avant);
                c->exec(state);
                c->writeToJson();
                delete(c);
                std::cout << "La défense lance " << state.getNbDesAttaque() << " dé(s)" << std::endl;
                //Issue du combat
                Commande* c_suivant = new IssueDuCombat(c->getIdJoueurCommande(), state.getVictoire());
                undos.push_back(c_suivant);
                c_suivant->exec(state);
                c_suivant->writeToJson();
                if (state.getVictoire() == 0){
                  if(IssueDuCombat::nbCartesJoueur(state) >= 3){
                    std::cout << "Vous possédez " << IssueDuCombat::nbCartesJoueur(state) << " cartes." << std::endl;
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
            if(c->getIdJoueurCommande() == joueur){
              c->exec(state);
              c->writeToJson();
              undos.push_back(c);
              state.setStepId(state::PIOCHER_s);
              steps.push_back(state::PIOCHER_s);
              std::cout << "Veuillez piocher une carte." << std::endl;
            }
          }
          break;

        case state::PIOCHER_s :
          if(c->getIdCommande() == PIOCHER_c){
            if(c->getIdJoueurCommande() == joueur){
              c->exec(state);
              c->writeToJson();
              undos.push_back(c);

              if(IssueDuCombat::nbCartesJoueur(state) >= 3){
                std::cout << "Vous possédez " << IssueDuCombat::nbCartesJoueur(state) << " cartes." << std::endl;
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
            if(c->getIdJoueurCommande() == joueur){
              if (c->getFin() == 0){
                state.setStepId(state::DEPLACER_ARMEES_s);
                steps.push_back(state::DEPLACER_ARMEES_s);
                delete(c);
                std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
              }
            }
          }
          else if(c->getIdCommande() == ECHANGE_c){
            if(c->getIdJoueurCommande() == joueur){
              if(c->verif(state)){
                c->exec(state);
                c->writeToJson();
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
            if(c->getIdJoueurCommande() == joueur){
              if(c->verif(state)){
                c->exec(state);
                c->writeToJson();
                undos.push_back(c);
                if (state.getArmeesRepartition(joueur) == 0){
                  state.setStepId(state::DEPLACER_ARMEES_s);
                  steps.push_back(state::DEPLACER_ARMEES_s);
                  std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
                }
              }
            }
          }
          else if(c->getIdCommande() == COMMANDE_COMPOSITE_c){
            if(c->getIdJoueurCommande() == joueur){
              c->exec(state);
              c->writeToJson();
              undos.push_back(c);
              state.setArmeesRepartition(joueur, 0);
              state.setStepId(state::DEPLACER_ARMEES_s);
              steps.push_back(state::DEPLACER_ARMEES_s);
              std::cout << "Vous pouvez maintenant déplacer des armées." << std::endl;
            }
          }
          break;

        case state::DEPLACER_ARMEES_s :
          if(c->getIdCommande() == DEPLACER_ARMEES_c){
            if(c->getIdJoueurCommande() == joueur){
              if(c->verif(state)){
                c->exec(state);
                c->writeToJson();
                undos.push_back(c);
              }
            }
          }
          else if(c->getIdCommande() == COMMANDE_COMPOSITE_c){
            if(c->getIdJoueurCommande() == joueur){
              c->exec(state);
              c->writeToJson();
              undos.push_back(c);
              Commande* fin = new FinTour(c->getIdJoueurCommande());
              fin->exec(state);
              fin->writeToJson();
              undos.push_back(fin);
              delete(c);
              state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
              steps.push_back(state::CHOIX_PAYS_ATTAQUANT_s);
              std::cout << "Fin du tour. Début du tour " << state.getTourId() << "." << std::endl;
              std::cout << std::endl;
              std::cout << "C'est au joueur " << state.getIdJoueur() << " de jouer." << std::endl;
            }
          }
          else if(c->getIdCommande() == PASSER_c){
            if(c->getIdJoueurCommande() == joueur){
              if (c->getFin() == 1){
                Commande* fin = new FinTour(c->getIdJoueurCommande());
                fin->exec(state);
                fin->writeToJson();
                undos.push_back(fin);
                delete(c);
                state.setStepId(state::CHOIX_PAYS_ATTAQUANT_s);
                steps.push_back(state::CHOIX_PAYS_ATTAQUANT_s);
                std::cout << "Fin du tour. Début du tour " << state.getTourId() << "." << std::endl;
                std::cout << std::endl;
                std::cout << "C'est au joueur " << state.getIdJoueur() << " de jouer." << std::endl;
              }
            }
          }
          break;
      }
    }
  }
}

void TourDeJeu::pushCommandeFichier(std::string fichier){
  std::string line;
  std::ifstream myfile (fichier, std::ios::in);
  if (myfile.is_open()){
    while(getline (myfile,line)) {
      char* ligne = (char*) line.c_str();
      strcpy(ligne, ligne + 12);
      std::string nomCommande;
      size_t i = 0;
      while(ligne[i] != '('){
        nomCommande.push_back(ligne[i]);
        i++;
      }
      i++;
      std::list<char*> parametres;
      char* parametre = " ";
      while (ligne[i] != '\0'){
        if (ligne[i] != ',' && ligne[i != ')']){
          parametre += ligne[i];
          i ++;
        }
        else{
          parametres.push_back(parametre);
          parametre = " ";
          i += 2;
        }
      }

      if (nomCommande == "Commande"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);//prend en compte l'espace au debut
        int para1 = (int) parametre1[0];
        pushCommande(new Commande(para1));
      }
      else if (nomCommande == "CommandeComposite"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        pushCommande(new CommandeComposite(para1));
      }
      else if (nomCommande == "Undo"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        pushCommande(new Undo(para1));
      }
      else if (nomCommande == "Distribution"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        pushCommande(new Distribution(para1));
      }
      else if (nomCommande == "PlacementArmees"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//std::string pays
        strcpy(parametre2, parametre2 + 12);
        std::string para2(parametre2);
        parametres.pop_front();
        char* parametre3 = parametres.front();//int nbArmees
        strcpy(parametre3, parametre3 + 3);
        int para3 = (int) parametre3[0];
        pushCommande(new PlacementArmees(para1, para2, para3));
      }
      else if (nomCommande == "ChoixPaysAttaquant"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//std::string pays
        strcpy(parametre2, parametre2 + 12);
        std::string para2(parametre2);
        pushCommande(new ChoixPaysAttaquant(para1, para2));
      }
      else if (nomCommande == "ChoixPaysAttaque"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//std::string pays
        strcpy(parametre2, parametre2 + 12);
        std::string para2(parametre2);
        pushCommande(new ChoixPaysAttaque(para1, para2));
      }
      else if (nomCommande == "DesAttaquant"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//int nbDes
        strcpy(parametre2, parametre2 + 5);
        int para2 = (int) parametre2[0];
        pushCommande(new DesAttaquant(para1, para2));
      }
      else if (nomCommande == "DesAttaque"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//int nbDes
        strcpy(parametre2, parametre2 + 5);
        int para2 = (int) parametre2[0];
        pushCommande(new DesAttaque(para1, para2));
      }
      else if (nomCommande == "IssueDuCombat"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//int victoire
        strcpy(parametre2, parametre2 + 5);
        std::string param2(parametre2);
        pushCommande(new IssueDuCombat(para1, std::stoi(param2)));
      }
      else if (nomCommande == "Defausser"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//int numeroCarte
        strcpy(parametre2, parametre2 + 5);
        int para2 = (int) parametre2[0];
        pushCommande(new Defausser(para1, para2));
      }
      else if (nomCommande == "Piocher"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        pushCommande(new Piocher(para1));
      }
      else if (nomCommande == "EchangeCartes"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//int numeroCarte
        strcpy(parametre2, parametre2 + 5);
        int para2 = (int) parametre2[0];
        pushCommande(new EchangeCartes(para1, para2));
      }
      else if (nomCommande == "DeplacerArmees"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//std::string paysDepart
        strcpy(parametre2, parametre2 + 12);
        std::string para2(parametre2);
        parametres.pop_front();
        char* parametre3 = parametres.front();//std::string paysArrivee
        strcpy(parametre3, parametre3 + 12);
        std::string para3(parametre3);
        parametres.pop_front();
        char* parametre4 = parametres.front();//int nbArmees
        strcpy(parametre4, parametre4 + 3);
        int para4 = (int) parametre4[0];
        pushCommande(new DeplacerArmees(para1, para2, para3, para4));
      }
      else if (nomCommande == "FinTour"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        pushCommande(new FinTour(para1));
      }
      else if (nomCommande == "Passer"){
        char* parametre1 = parametres.front();//int idJoueurCommande
        strcpy(parametre1, parametre1 + 5);
        int para1 = (int) parametre1[0];
        parametres.pop_front();
        char* parametre2 = parametres.front();//bool fin
        strcpy(parametre2, parametre2 + 6);
        bool para2 = (bool) parametre2[0];
        pushCommande(new Piocher(para1));
      }
    }
    myfile.close();
  }
}

}
