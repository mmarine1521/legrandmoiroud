#include "DeepAI.h"

#include <algorithm>    // std::find
#include <map>

namespace ai{

DeepAI::DeepAI(int idJoueurAI) : AI(idJoueurAI){
}

int DeepAI::evalState (state::State& state, int profondeur, int minMax){ // copie de state
  // copie de state
  state::State stateFictif = state::State();
  stateFictif.setCartePiocheTab(state.getCartePiocheTab());
  stateFictif.setCarteEnjeuTab(state.getCarteEnjeuTab());
  stateFictif.setCarteDefausseTab(state.getCarteDefausseTab());
  stateFictif.setPaysTab(state.getPaysTab());
  stateFictif.setContinentTab(state.getContinentTab());
  stateFictif.setTourId(state.getTourId());
  stateFictif.setIdJoueur(state.getIdJoueur());
  stateFictif.setStepId(state.getStepId());
  stateFictif.setArmeesRepartition(1, state.getArmeesRepartition(1));
  stateFictif.setArmeesRepartition(2, state.getArmeesRepartition(2));

  if (profondeur == 0){
    state::ElementTab& tabArmee = stateFictif.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* ptr_armee = 0;

    int nbPaysJoueur = 0;
    int nbArmeesJoueur = 0;
    for(size_t i=0; i<listeArmee.size(); i++){
      ptr_armee = listeArmee[i].get();
      if (ptr_armee->getIdJoueur() == this->idJoueurAI){
        nbPaysJoueur += 1;
        nbArmeesJoueur += ptr_armee->getNombre();
      }
    }
    return (3 * nbPaysJoueur + nbArmeesJoueur);
  }

  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  int value = - minMax * 99999;
  if (paysAttaquants[0] == "NOPAYS"){
    value = 0;
    commandesAExecuter.clear();
    commandesAExecuter.push_back(new engine::Passer(this->idJoueurAI, 0));
    commandesAExecuter.push_back(intelligence.aiDeplacerArmees(state));
  }
  else{
    for (size_t i=0; i<2; i++){
      if(paysAttaquants[i] != "NOPAYS"){
        for (size_t j=0; j<2; j++){
          if (paysAttaques[j + 2*i] != "NOPAYS"){
            //mini tour de jeu => executes
            commandes.push_back(new engine::ChoixPaysAttaquant(this->idJoueurAI, paysAttaquants[i]));
            undos.push_back(new engine::ChoixPaysAttaquant(this->idJoueurAI, stateFictif.getPaysAttaquant()));
            commandes.push_back(new engine::ChoixPaysAttaque(this->idJoueurAI, paysAttaques[j + 2*i]));
            undos.push_back(new engine::ChoixPaysAttaque(this->idJoueurAI, stateFictif.getPaysAttaque()));
            commandes.push_back(intelligence.aiDesAttaquant(stateFictif));
            undos.push_back(new engine::DesAttaquant(this->idJoueurAI, stateFictif.getNbDesAttaquant(), stateFictif.getDesRouges()));
            commandes.push_back(intelligence.aiDesAttaque(stateFictif));
            undos.push_back(new engine::DesAttaque(this->idJoueurAI, stateFictif.getNbDesAttaque(), stateFictif.getDesBleus()));
            engine::IssueDuCombat* issue = new engine::IssueDuCombat(this->idJoueurAI, stateFictif.getVictoire());
            commandes.push_back(issue);
            undos.push_back(issue);
            if(engine::IssueDuCombat::nbCartesJoueur(stateFictif) == 5){
              engine::Commande* defausse = intelligence.aiDefausser(stateFictif);
              commandes.push_back(defausse);
              undos.push_back(defausse);
            }
            engine::Piocher* pioche = new engine::Piocher(this->idJoueurAI);
            commandes.push_back(pioche);
            undos.push_back(pioche);
            if(engine::IssueDuCombat::nbCartesJoueur(stateFictif) >= 3){
              engine::Commande* echange = intelligence.aiEchange(stateFictif);
              commandes.push_back(echange);
              undos.push_back(echange);
            }
            engine::Commande* placement = intelligence.aiPlacementArmees(stateFictif);
            commandes.push_back(placement);
            undos.push_back(placement);
            engine::Commande* deplacement = intelligence.aiDeplacerArmees(stateFictif);
            commandes.push_back(deplacement);
            undos.push_back(deplacement);
            engine::Passer* passe = new engine::Passer(this->idJoueurAI, 1);
            commandes.push_back(passe);

            //joueur

            while(!commandes.empty()){//faire for
              engine::Commande* c = commandes.front();
              commandes.pop_front();
              c->exec(stateFictif);
              if (c->getIdCommande() == engine::CHOIX_PAYS_ATTAQUANT_c || c->getIdCommande() == engine::CHOIX_PAYS_ATTAQUE_c || c->getIdCommande() == engine::NB_DES_ATTAQUANT_c || c->getIdCommande() == engine::NB_DES_ATTAQUE_c){
                delete(c);
              }
            }

            int eval = evalState(stateFictif, profondeur - 1, - minMax);
            if (minMax == 1){
              if(eval > value){
                value = eval;
                commandesAExecuter = commandes;
              }
            }
            else{
              if(eval < value){
                value = eval;
                commandesAExecuter = commandes;
              }
            }

            while(!undos.empty()){
              engine::Commande* commande_undo = undos.back();
              undos.pop_back();
              commande_undo->undo(stateFictif);
              delete(commande_undo);
            }
          }
        }
      }
    }
  }
  return value;
}

void DeepAI::selectPaysAttaquants (state::State& state){
  std::vector<std::string> blackList = state.getBlackList();
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  std::map<std::string, int> nbArmee;
  std::vector<std::string> listePaysJoueur;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if(ptr_armee->getIdJoueur() == this->idJoueurAI){ //le choix ne se fait que sur les pays du joueur "idJoueur"
      listePaysJoueur.push_back(ptr_armee->getPays());
      std::vector<std::string>::iterator result = find(blackList.begin(), blackList.end(), ptr_armee->getPays()); // renvoie le dernier element si faux
			if (result == blackList.end()){
				if(ptr_armee->getNombre() > 1){ //nombre d'armées > 1 sinon impossible d'attaquer
					nbArmee[ptr_armee->getPays()] = ptr_armee->getNombre(); // remplit map armeePays / nbArmee
				}
			}
		}
  }

  if (nbArmee.size() == 0){
    std::cout << "Problème : Vous ne pouvez engagé aucun de vos territoires dans un combat." << std::endl;
		paysAttaquants[0] = "NOPAYS";
  }
  else{
    int maxi = 0;
    std::list<std::string> armeeMaxi;
    for (std::map<std::string, int>::iterator it = nbArmee.begin(); it != nbArmee.end(); ++it){
      if (it->second > maxi){
        armeeMaxi.clear();
        maxi = it->second;
        armeeMaxi.push_back(it->first);
      }
      else if (it->second == maxi){
        armeeMaxi.push_back(it->first);
      }
    }

    if (armeeMaxi.size() == 1){
      paysAttaquants[0] = armeeMaxi.front();
      if(nbArmee.size() == 1){
        paysAttaquants[1] = "NOPAYS";
      }
      else{
        maxi = 0;
        for (std::map<std::string, int>::iterator it = nbArmee.begin(); it != nbArmee.end(); ++it){
          if (it->first != paysAttaquants[0]){
            if (it->second > maxi){
              armeeMaxi.clear();
              maxi = it->second;
              armeeMaxi.push_back(it->first);
            }
            else if (it->second == maxi){
              armeeMaxi.push_back(it->first);
            }
          }
        }
        if (armeeMaxi.size() == 1){
          paysAttaquants[1] = armeeMaxi.front();
        }
        else{
          state::ElementTab& tabPays = state.getPaysTab();
          std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
          state::Element* ptr_pays = 0;
          std::vector<state::Element*> listePaysArmeeMaxi;

          for (std::string armee : armeeMaxi) {
            for(size_t i=0; i<listePays.size(); i++){
              ptr_pays = listePays[i].get();
              if (ptr_pays->getPays() == armee){
                listePaysArmeeMaxi.push_back(ptr_pays); // remplit la liste des pays ayant le plus d'armees
              }
            }
          }

          std::map<std::string, int> nbFrontaliers;
          int compt;
          for(size_t i=0; i<listePaysArmeeMaxi.size(); i++){
            ptr_pays = listePaysArmeeMaxi[i];
            compt = 0;
            for(size_t j=0; j<listePaysJoueur.size(); j++){
              if (ptr_pays->getPays() != listePaysJoueur[j]){
                if (engine::ChoixPaysAttaque::estFrontalier(ptr_pays->getPays(), listePaysJoueur[j], state)){
                  compt ++;
                }
              }
            }
            nbFrontaliers[ptr_pays->getPays()] = compt;
          }

          maxi = 0;
          std::string paysOpti;
          for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
            if (it->second > maxi){
              maxi = it->second;
              paysOpti = it->first;
            }
          }
          paysAttaquants[1] = paysOpti;
        }
      }
    }
    else{
      state::ElementTab& tabPays = state.getPaysTab();
      std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
      state::Element* ptr_pays = 0;
      std::vector<state::Element*> listePaysArmeeMaxi;

      for (std::string armee : armeeMaxi) {
        for(size_t i=0; i<listePays.size(); i++){
          ptr_pays = listePays[i].get();
          if (ptr_pays->getPays() == armee){
            listePaysArmeeMaxi.push_back(ptr_pays); // remplit la liste des pays ayant le plus d'armees
          }
        }
      }

      std::map<std::string, int> nbFrontaliers;
      int compt;
      for(size_t i=0; i<listePaysArmeeMaxi.size(); i++){
        ptr_pays = listePaysArmeeMaxi[i];
        compt = 0;
        for(size_t j=0; j<listePaysJoueur.size(); j++){
          if (ptr_pays->getPays() != listePaysJoueur[j]){
            if (engine::ChoixPaysAttaque::estFrontalier(ptr_pays->getPays(), listePaysJoueur[j], state)){
              compt ++;
            }
          }
        }
        nbFrontaliers[ptr_pays->getPays()] = compt;
      }

      maxi = 0;
      std::string paysOpti;
      for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
        if (it->second > maxi){
          maxi = it->second;
          paysOpti = it->first;
        }
      }
      paysAttaquants[0] = paysOpti;

      maxi = 0;
      for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
        if (it->first != paysOpti){
          if (it->second > maxi){
            maxi = it->second;
            paysOpti = it->first;
          }
        }
      }
      paysAttaquants[1] = paysOpti;
    }
  }
}

void DeepAI::selectPaysAttaques (state::State& state){
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ptr_pays = 0;

  for (size_t p=0; p<2; p++){
    for(size_t i=0; i<listePays.size(); i++){
      ptr_pays = listePays[i].get();
      if (ptr_pays->getPays() == paysAttaquants[p]){
        break;
      }
    }
    std::vector<std::string> paysFrontaliers = ptr_pays->getPaysFrontaliers(); // pays frontaliers du paysAttaquant

    state::ElementTab& tabArmee = state.getArmeeTab();
    std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
    state::Element* ptr_armee = 0;
    std::map<std::string, int> nbArmee;
    std::vector<std::string> listePaysJoueurAdversaire;

    for(size_t i=0; i<listeArmee.size(); i++){
      ptr_armee = listeArmee[i].get();
      std::vector<std::string>::iterator result = find(paysFrontaliers.begin(), paysFrontaliers.end(), ptr_armee->getPays()); // renvoie le dernier element si faux
      if (result != paysFrontaliers.end()){
        if (ptr_armee->getIdJoueur() != this->idJoueurAI){
          nbArmee[ptr_armee->getPays()] = ptr_armee->getNombre(); // remplit map armeePaysFrontaliersPasALui / nbArmee
          listePaysJoueurAdversaire.push_back(ptr_armee->getPays());
        }
      }
    }

    int mini = 100;
    std::list<std::string> armeeMini; //liste des pays ayant le moins d'armées
    for (std::map<std::string, int>::iterator it = nbArmee.begin(); it != nbArmee.end(); ++it){
      if (it->second < mini){
        armeeMini.clear();
        mini = it->second;
        armeeMini.push_back(it->first);
      }
      else if (it->second == mini){
        armeeMini.push_back(it->first);
      }
    }

    if (armeeMini.size() == 1){
      paysAttaques[0 + 2*p] = armeeMini.front();
      if(nbArmee.size() == 1){
        paysAttaques[1 + 2*p] = "NOPAYS";
      }
      else{
        int mini = 100;
        std::list<std::string> armeeMini; //liste des pays ayant le moins d'armées
        for (std::map<std::string, int>::iterator it = nbArmee.begin(); it != nbArmee.end(); ++it){
          if (it->first != paysAttaques[0]){
            if (it->second < mini){
              armeeMini.clear();
              mini = it->second;
              armeeMini.push_back(it->first);
            }
            else if (it->second == mini){
              armeeMini.push_back(it->first);
            }
          }
        }
        if (armeeMini.size() == 1){
          paysAttaques[1 + 2*p] = armeeMini.front();
        }
        else{
          std::map<std::string, int> nbFrontaliers;
          int compt;
          for(std::string armee : armeeMini){
            compt = 0;
            for(size_t j=0; j<listePaysJoueurAdversaire.size(); j++){
              if (armee != listePaysJoueurAdversaire[j]){
                if (engine::ChoixPaysAttaque::estFrontalier(armee, listePaysJoueurAdversaire[j], state)){
                  compt ++; // On compte combien de pays frontaliers adversaires compte le pays qu'on veut attaquer
                }
              }
            }
            nbFrontaliers[armee] = compt;
          }

          int maxi = 0;
          std::string paysOpti;
          for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
            if (it->second > maxi){
              maxi = it->second;
              paysOpti = it->first; // on choisit le pays avec le plus de frontaliers ennemis
            }
          }
          paysAttaques[1 + 2*p] = paysOpti;
        }
      }
    }
    else{//armeeMini.size() > 1
      std::map<std::string, int> nbFrontaliers;
      int compt;
      for(std::string armee : armeeMini){
        compt = 0;
        for(size_t j=0; j<listePaysJoueurAdversaire.size(); j++){
          if (armee != listePaysJoueurAdversaire[j]){
            if (engine::ChoixPaysAttaque::estFrontalier(armee, listePaysJoueurAdversaire[j], state)){
              compt ++; // On compte combien de pays frontaliers adversaires compte le pays qu'on veut attaquer
            }
          }
        }
        nbFrontaliers[armee] = compt;
      }

      int maxi = 0;
      std::string paysOpti;
      for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
        if (it->second > maxi){
          maxi = it->second;
          paysOpti = it->first; // on choisit le pays avec le plus de frontaliers ennemis
        }
      }
      paysAttaques[0 + 2*p] = paysOpti;

      maxi = 0;
      for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
        if (it->first != paysAttaques[0 + 2*p]){
          if (it->second > maxi){
            maxi = it->second;
            paysOpti = it->first; // on choisit le pays avec le plus de frontaliers ennemis
          }
        }
      }
      paysAttaques[1 + 2*p] = paysOpti;
    }
  }
}

engine::Commande* DeepAI::aiRepartitionArmees (state::State& state){
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiRepartitionArmees(state);
}

engine::Commande* DeepAI::aiChoixPaysAttaquant (state::State& state){
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiChoixPaysAttaquant(state);
}

engine::Commande* DeepAI::aiChoixPaysAttaque (state::State& state){
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiChoixPaysAttaque(state);
}

engine::Commande* DeepAI::aiDesAttaquant (state::State& state){
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiDesAttaquant(state);
}

engine::Commande* DeepAI::aiDesAttaque (state::State& state){
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiDesAttaque(state);
}

engine::Commande* DeepAI::aiDefausser (state::State& state){
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiDefausser(state);
}

engine::Commande* DeepAI::aiEchange (state::State& state){
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiEchange(state);
}

engine::Commande* DeepAI::aiPlacementArmees (state::State& state){// a coder
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiPlacementArmees(state);
}

engine::Commande* DeepAI::aiDeplacerArmees (state::State& state){ // a coder
  HeuristicAI intelligence = HeuristicAI(this->idJoueurAI);
  return intelligence.aiDeplacerArmees(state);
}

void DeepAI::initializePays(){
  paysAttaquants.push_back("#PAYS");
  paysAttaquants.push_back("#PAYS");
  paysAttaques.push_back("#PAYS");
  paysAttaques.push_back("#PAYS");
  paysAttaques.push_back("#PAYS");
  paysAttaques.push_back("#PAYS");
}

}
