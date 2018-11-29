#include "HeuristicAI.h"

#include <map>
#include <string>
#include <algorithm>
#include <list>

namespace ai {

void HeuristicAI::heuristicRepartitionArmees (int idJoueur, state::State state){
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
    if (ptr_armee->getIdJoueur() == idJoueur){
      listeArmeeJoueur.push_back(ptr_armee); // remplit la liste des armees appartenant au joueur
    }
  }

  for(size_t j=0; j<listeArmeeJoueur.size(); j++){
    ptr_armee = listeArmeeJoueur[j];
    for(size_t i=0; i<listePays.size(); i++){
      ptr_pays = listePays[i].get();
      if (ptr_pays->getPays() == ptr_armee->getPays()){
        listePaysJoueur.push_back(ptr_pays); // remplit la liste des pays appartenant au joueur
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
        if (engine::ChoixPays::estFrontalier(ptr_pays->getPays(), ptr_paysFrontalier->getPays(), state)){
          compt ++;
        }
      }
    }
    nbFrontaliers[ptr_pays->getPays()] = compt; // remplit la map nomPays / nbDeSesFrontaliers
  }

  int nbArmee = 0;
  int maxi = 0;
  for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
    if (it->second > maxi){
      maxi = it->second;
    }
  }

  int mini = maxi;
  std::string paysMini;
  for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
    it->second = maxi - it->second + 1;
    nbArmee += it->second;
    if (it->second < mini){
      mini = it->second;
      paysMini = it->first;
    }
  }

  int APlacer = 42 % nbArmee;

  while(APlacer != 0){
    nbFrontaliers[paysMini] += 1;
    APlacer -=1;
    mini = maxi;
    for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
      if (it->second < mini){
        mini = it->second;
        paysMini = it->first;
      }
    }
  }

  for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
    for(size_t i=0; i<listeArmee.size(); i++){
      ptr_armee = listeArmee[i].get();
      if (ptr_armee->getPays() == it->first){
        ptr_armee->setNombre(it->second);
      }
    }
  }
}

std::string HeuristicAI::heuristicChoixPaysAttaquant (int idJoueur, state::State state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  std::map<std::string, int> nbArmee;
  std::vector<std::string> listePaysJoueur;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getIdJoueur() == idJoueur){
      nbArmee[ptr_armee->getPays()] = ptr_armee->getNombre(); // remplit map armeePays / nbArmee
      listePaysJoueur.push_back(ptr_armee->getPays());
    }
  }

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
    return armeeMaxi.front();
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
          if (engine::ChoixPays::estFrontalier(ptr_pays->getPays(), listePaysJoueur[j], state)){
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
    return paysOpti;
  }
} //si jamais le pays est entouré de frontaliers et ne va donc pas !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

std::string HeuristicAI::heuristicChoixPaysAttaque (int idJoueur, std::string paysAttaquant, state::State state){
///////////////////////////////////////////////////
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ptr_pays = 0;

  for(size_t i=0; i<listePays.size(); i++){
    ptr_pays = listePays[i].get();
    if (ptr_pays->getPays() == paysAttaquant){
      break;
    }
  }
  std::vector<std::string> paysFrontaliers = ptr_pays->getPaysFrontaliers();

  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  std::map<std::string, int> nbArmee;
  std::vector<std::string> listePaysJoueur;

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    std::vector<std::string>::iterator result = find(paysFrontaliers.begin(), paysFrontaliers.end(), ptr_armee->getPays()); // renvoie le dernier element si faux
    if (result != paysFrontaliers.end()){
      if (ptr_armee->getIdJoueur() != idJoueur){
        nbArmee[ptr_armee->getPays()] = ptr_armee->getNombre(); // remplit map armeePaysFrontaliersPasALui / nbArmee
        listePaysJoueur.push_back(ptr_armee->getPays());
      }
    }
  }

  int mini = 100;
  std::list<std::string> armeeMini;
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
    return armeeMini.front();
  }
  else{
    std::vector<state::Element*> listePaysFrontaliersMaxi;

    for (std::string armee : armeeMini) {
      for(size_t i=0; i<listePays.size(); i++){
        ptr_pays = listePays[i].get();
        if (ptr_pays->getPays() == armee){
          listePaysFrontaliersMaxi.push_back(ptr_pays); // remplit la liste des pays ayant le plus d'armees
        }
      }
    }

    std::map<std::string, int> nbFrontaliers;
    int compt;
    for(size_t i=0; i<listePaysFrontaliersMaxi.size(); i++){
      ptr_pays = listePaysFrontaliersMaxi[i];
      compt = 0;
      for(size_t j=0; j<listePaysJoueur.size(); j++){
        if (ptr_pays->getPays() != listePaysJoueur[j]){
          if (engine::ChoixPays::estFrontalier(ptr_pays->getPays(), listePaysJoueur[j], state)){
            compt ++;
          }
        }
      }
      nbFrontaliers[ptr_pays->getPays()] = compt;
    }

    int maxi = 0;
    std::string paysOpti;
    for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
      if (it->second > maxi){
        maxi = it->second;
        paysOpti = it->first;
      }
    }
    return paysOpti;
  }

}

//int HeuristicAI::heuristicNbDesLancersAttaques (){}

//int HeuristicAI::heuristicNbDesLancersDefenses (){}

void HeuristicAI::heuristicGainCartes (int idJoueur, bool victoire, state::State state){
  if(victoire){
    state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
    std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
    state::Element* ptr_carte = 0;
    std::vector<state::Element*> listeJoueur;

    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if (ptr_carte->getIdJoueur() == idJoueur){
        listeJoueur.push_back(ptr_carte);
      }
    }

    if (listeJoueur.size() > 4){
      int comptTANK = 0;
      int comptCANON = 0;
      int comptSOLDAT = 0;
      for(size_t i=0; i<listeJoueur.size(); i++){
        ptr_carte = listeEnjeu[i].get();
        switch (ptr_carte->getCarteForce()) {
          case 0 : break; //NONIDENTIFIE
          case 1 : comptTANK +=1; break; //TANK
          case 2 : comptCANON +=1; break; //CANON
          case 3 : comptSOLDAT +=1; break; //SOLDAT
        }
      }

      if (comptSOLDAT == 1 || comptSOLDAT == 4 || comptSOLDAT == 5){
        for(size_t i=0; i<listeJoueur.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getCarteForce() == 3){
            engine::GestionCartes::defausser (ptr_carte->getNumero(), state);
            break;
          }
        }
      }

      else if (comptTANK == 1 || comptTANK == 4 || comptTANK == 5){
        for(size_t i=0; i<listeJoueur.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getCarteForce() == 1){
            engine::GestionCartes::defausser (ptr_carte->getNumero(), state);
            break;
          }
        }
      }

      else if (comptCANON == 1 || comptCANON == 2 || comptCANON == 5){
        for(size_t i=0; i<listeJoueur.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getCarteForce() == 2){
            engine::GestionCartes::defausser (ptr_carte->getNumero(), state);
            break;
          }
        }
      }

      else if (comptSOLDAT == 2){
        for(size_t i=0; i<listeJoueur.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getCarteForce() == 3){
            engine::GestionCartes::defausser (ptr_carte->getNumero(), state);
            break;
          }
        }
      }

      else if (comptTANK == 2){
        for(size_t i=0; i<listeJoueur.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getCarteForce() == 1){
            engine::GestionCartes::defausser (ptr_carte->getNumero(), state);
            break;
          }
        }
      }
    }

    engine::GestionCartes::piocher(idJoueur, state);
  }
}

int HeuristicAI::heuristicEchange (int idJoueur, state::State state){
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
  }
  return -1;
}

//void HeuristicAI::heuristicPlacerNouvellesArmees (int idJoueur, int nouvellesArmees, state::State state){}

//void HeuristicAI::heuristicDeplacerArmees (int idJoueur, state::State state){}

//void HeuristicAI::heuristicJouer (int numeroTour, int idJoueur, state::State state){}

}
