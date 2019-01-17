#include "HeuristicAI.h"

#include <map>
#include <algorithm>    // std::find

namespace ai{

HeuristicAI::HeuristicAI(int idJoueurAI) : AI(idJoueurAI){
}


engine::Commande* HeuristicAI::aiRepartitionArmees (state::State& state){
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
    if (ptr_armee->getIdJoueur() == this->idJoueurAI){
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
        if (engine::ChoixPaysAttaque::estFrontalier(ptr_pays->getPays(), ptr_paysFrontalier->getPays(), state)){
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

  int ok = 28;
  engine::CommandeComposite* comp = new engine::CommandeComposite(this->idJoueurAI);
  while(ok != 0){
    nbFrontaliers[paysMini] += 1;
    ok -= 1;
    comp->pushCommandeComposite(new engine::PlacementArmees(this->idJoueurAI, paysMini, 1));
    mini = 100;
    for (std::map<std::string, int>::iterator it = nbFrontaliers.begin(); it != nbFrontaliers.end(); ++it){
      if (it->second < mini){
        mini = it->second;
        paysMini = it->first;
      }
    }
  }
  return (comp);
}

engine::Commande* HeuristicAI::aiChoixPaysAttaquant (state::State& state){
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
    return (new engine::Passer(this->idJoueurAI, 0));
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
      return (new engine::ChoixPaysAttaquant(this->idJoueurAI, armeeMaxi.front()));
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
      return (new engine::ChoixPaysAttaquant(this->idJoueurAI, paysOpti));
    }
  }
}

engine::Commande* HeuristicAI::aiChoixPaysAttaque (state::State& state){
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ptr_pays = 0;

  for(size_t i=0; i<listePays.size(); i++){
    ptr_pays = listePays[i].get();
    if (ptr_pays->getPays() == state.getPaysAttaquant()){
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
    return (new engine::ChoixPaysAttaque(this->idJoueurAI, armeeMini.front()));
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
    return (new engine::ChoixPaysAttaque(this->idJoueurAI, paysOpti));
  }
}

engine::Commande* HeuristicAI::aiDesAttaquant (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;

  int nbArmeeAttaquant = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getPays() == state.getPaysAttaquant()){
      nbArmeeAttaquant = ptr_armee->getNombre();
      break;
    }
  }

  if (nbArmeeAttaquant >= 4){
    return (new engine::DesAttaquant(this->idJoueurAI, 3));
  }
  else if (nbArmeeAttaquant == 3){
    return (new engine::DesAttaquant(this->idJoueurAI, 2));
  }
  else if (nbArmeeAttaquant == 2){
    return (new engine::DesAttaquant(this->idJoueurAI, 1));
  }
  else{
    return (new engine::DesAttaquant(this->idJoueurAI, 0));
  }
}

engine::Commande* HeuristicAI::aiDesAttaque (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;

  int nbArmee = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getPays() == state.getPaysAttaque()){
      nbArmee = ptr_armee->getNombre();
      break;
    }
  }

  if (nbArmee > 2){
    return (new engine::DesAttaque(this->idJoueurAI, 2));
  }
  else{
    return (new engine::DesAttaque(this->idJoueurAI, 1));
  }
}

engine::Commande* HeuristicAI::aiDefausser (state::State& state){
  if (state.getVictoire() != 0){
    state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
    std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
    state::Element* ptr_carte = 0;
    std::vector<state::Element*> listeJoueur;

    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if (ptr_carte->getIdJoueur() == this->idJoueurAI){
        listeJoueur.push_back(ptr_carte);
      }
    }

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
          break;
        }
      }
      return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
    }

    else if (comptTANK == 1 || comptTANK == 4 || comptTANK == 5){
      for(size_t i=0; i<listeJoueur.size(); i++){
        ptr_carte = listeEnjeu[i].get();
        if (ptr_carte->getCarteForce() == 1){
          break;
        }
      }
      return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
    }

    else if (comptCANON == 1 || comptCANON == 2 || comptCANON == 5){
      for(size_t i=0; i<listeJoueur.size(); i++){
        ptr_carte = listeEnjeu[i].get();
        if (ptr_carte->getCarteForce() == 2){
          break;
        }
      }
      return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
    }

    else if (comptSOLDAT == 2){
      for(size_t i=0; i<listeJoueur.size(); i++){
        ptr_carte = listeEnjeu[i].get();
        if (ptr_carte->getCarteForce() == 3){
          break;
        }
      }
      return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
    }

    else if (comptTANK == 2){
      for(size_t i=0; i<listeJoueur.size(); i++){
        ptr_carte = listeEnjeu[i].get();
        if (ptr_carte->getCarteForce() == 1){
          break;
        }
      }
      return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
    }
    else{
      return (new engine::Passer(this->idJoueurAI, 0));
    }
  }
}

engine::Commande* HeuristicAI::aiEchange (state::State& state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::Element* ptr_carte = 0;

  if(state.getTypeCartes().size() == 0){
    int comptTANK = 0;
    int comptCANON = 0;
    int comptSOLDAT = 0;
    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if (ptr_carte->getIdJoueur() == this->idJoueurAI){
        switch (ptr_carte->getCarteForce()) {
          case 0 : break; //NONIDENTIFIE
          case 1 : comptTANK +=1; break; //TANK
          case 2 : comptCANON +=1; break; //CANON
          case 3 : comptSOLDAT +=1; break; //SOLDAT
        }
      }
    }
    if (comptTANK < 3 && comptCANON < 3 && comptSOLDAT < 3){
      return (new engine::Passer(this->idJoueurAI, 0));
    }
    else{
      //5 cartes max
      if (comptTANK >= 3){
        for(size_t i=0; i<listeEnjeu.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getIdJoueur() == this->idJoueurAI){
            if (ptr_carte->getCarteForce() == 1){
              state.setTypeCarte(state::TANK);
              break;
            }
          }
        }
        return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
      }

      else if (comptCANON >= 3){
        for(size_t i=0; i<listeEnjeu.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getIdJoueur() == this->idJoueurAI){
            if (ptr_carte->getCarteForce() == 2){
              state.setTypeCarte(state::CANON);
              break;
            }
          }
        }
        return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
      }

      else{ // if (comptSOLDAT >= 3)
        for(size_t i=0; i<listeEnjeu.size(); i++){
          ptr_carte = listeEnjeu[i].get();
          if (ptr_carte->getIdJoueur() == this->idJoueurAI){
            if (ptr_carte->getCarteForce() == 3){
              state.setTypeCarte(state::SOLDAT);
              break;
            }
          }
        }
        return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
      }
    }
  }
  else{//deja des cartes defaussées
    state::CarteForce force = state.getTypeCartes()[0];
    for(size_t i=0; i<listeEnjeu.size(); i++){
      ptr_carte = listeEnjeu[i].get();
      if (ptr_carte->getIdJoueur() == this->idJoueurAI){
        if (ptr_carte->getCarteForce() == force){
          state.setTypeCarte(force);
          break;
        }
      }
    }
    return (new engine::Defausser(this->idJoueurAI, ptr_carte->getNumero()));
  }
}

engine::Commande* HeuristicAI::aiPlacementArmees (state::State& state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;

  std::map<std::string, int> nbArmee;
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getIdJoueur() == this->idJoueurAI){
      nbArmee[ptr_armee->getPays()] = ptr_armee->getNombre();
    }
  }

  engine::CommandeComposite* comp = new engine::CommandeComposite(this->idJoueurAI);
  while(state.getArmeesRepartition(this->idJoueurAI) != 0){
    int mini = 100;
    std::string paysMini;
    for (std::map<std::string, int>::iterator it = nbArmee.begin(); it != nbArmee.end(); ++it){
      if (it->second < mini){
        mini = it->second;
        paysMini = it->first;
      }
    }
    state.setArmeesRepartition(this->idJoueurAI, state.getArmeesRepartition(this->idJoueurAI) - 1);
    comp->pushCommandeComposite(new engine::PlacementArmees(this->idJoueurAI, paysMini, 1));
  }
  return (comp);
}

engine::Commande* HeuristicAI::aiDeplacerArmees (state::State& state){
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ptr_pays = 0;

  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  std::vector<std::string> listeArmeeJoueur; // liste des noms des pays appartenant au joueur

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getIdJoueur() == this->idJoueurAI){
      listeArmeeJoueur.push_back(ptr_armee->getPays());
    }
  }

  std::vector<std::string> ADeplacer; // liste des armees entourées d'alliers
  for(size_t i=0; i<listeArmeeJoueur.size(); i++){
    std::string pays = listeArmeeJoueur[i];
    for(size_t j=0; j<listePays.size(); j++){
      ptr_pays = listePays[j].get();
      if (ptr_pays->getPays() == pays){ // on récupère chaque pays dans les Pays
        std::vector<std::string> paysFrontaliers = ptr_pays->getPaysFrontaliers(); // on récupère les frontaliers du pays
        size_t compt = 0; // on va compter le nombre de ses frontaliers appartenant au joueur
        for(size_t k=0; k<paysFrontaliers.size(); k++){
          std::string frontalier = paysFrontaliers[k];
          for(size_t l=0; l<listeArmee.size(); l++){
            ptr_armee = listeArmee[l].get();
            if (ptr_armee->getPays() == frontalier && ptr_armee->getIdJoueur() == this->idJoueurAI){
              compt += 1;
            }
          }
        }
        if (compt == paysFrontaliers.size()){
          ADeplacer.push_back(pays);
        }
      }
    }
  }

  engine::CommandeComposite* comp = new engine::CommandeComposite(this->idJoueurAI);
  if (ADeplacer.size() != 0){
    for(size_t i=0; i<ADeplacer.size(); i++){
      for(size_t j=0; j<listePays.size(); i++){
        ptr_pays = listePays[j].get();
        if (ptr_pays->getPays() == ADeplacer[i]){
          break;
        }
      }
      std::vector<std::string> paysFrontaliers = ptr_pays->getPaysFrontaliers();
      int APlacer = ptr_pays->getNombre() - 1;

      for(size_t j=0; i<ADeplacer.size(); i++){
        std::vector<std::string>::iterator result = find(paysFrontaliers.begin(), paysFrontaliers.end(), ADeplacer[j]); // renvoie le dernier element si faux
        if (result != paysFrontaliers.end()){// si vrai
          paysFrontaliers.erase(std::remove(paysFrontaliers.begin(), paysFrontaliers.end(), ADeplacer[i]), paysFrontaliers.end());// enlève le pays de ADeplacer dans la liste des frontaliers s'il y est
        }
      }

      std::map<std::string, int> forcePays;
      for(size_t k=0; k<paysFrontaliers.size(); k++){
        std::string frontalier = paysFrontaliers[k];
        for(size_t j=0; j<listeArmee.size(); j++){
          ptr_armee = listeArmee[j].get();
          if (ptr_armee->getPays() == frontalier){
            forcePays[frontalier] = ptr_armee->getNombre();
          }
        }
      }

      while(APlacer != 0){
        int mini = 100;
        std::string paysMini;
        for (std::map<std::string, int>::iterator it = forcePays.begin(); it != forcePays.end(); ++it){
          if (it->second < mini){
            mini = it->second;
            paysMini = it->first;
          }
        }
        comp->pushCommandeComposite(new engine::DeplacerArmees(this->idJoueurAI, ADeplacer[i], paysMini, 1));
      }
    }
  }
  comp->pushCommandeComposite(new engine::Passer(this->idJoueurAI, 1));
  return (comp);
}

}
