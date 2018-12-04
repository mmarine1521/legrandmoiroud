#include "HeuristicAI.h"

#include <map>
#include <string>
#include <algorithm>
#include <list>

namespace ai {

void HeuristicAI::aiRepartitionArmees (int idJoueur, state::State state){
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

std::string HeuristicAI::aiChoixPaysAttaquant (int idJoueur, state::State state){
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

std::string HeuristicAI::aiChoixPaysAttaque (int idJoueur, std::string paysAttaquant, state::State state){
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ptr_pays = 0;

  for(size_t i=0; i<listePays.size(); i++){
    ptr_pays = listePays[i].get();
    if (ptr_pays->getPays() == paysAttaquant){
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
      if (ptr_armee->getIdJoueur() != idJoueur){
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
    return armeeMini.front();
  }
  else{
    std::map<std::string, int> nbFrontaliers;
    int compt;
    for(std::string armee : armeeMini){
      compt = 0;
      for(size_t j=0; j<listePaysJoueurAdversaire.size(); j++){
        if (armee != listePaysJoueurAdversaire[j]){
          if (engine::ChoixPays::estFrontalier(armee, listePaysJoueurAdversaire[j], state)){
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
    return paysOpti;
  }

}

int HeuristicAI::aiNbDesLancersAttaques (std::string paysAttaquant, std::string paysAttaque, state::State state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;

  int nbArmeeAttaquant = 0;
  int nbArmeeAttaque = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getPays() == paysAttaquant){
      nbArmeeAttaquant = ptr_armee->getNombre();
    }
    if (ptr_armee->getPays() == paysAttaque){
      nbArmeeAttaque = ptr_armee->getNombre();
    }
  }

  if (nbArmeeAttaquant >= 4){
    return 3;
  }
  else if (nbArmeeAttaquant == 3){
    if (nbArmeeAttaque <=2){
      return 3;
    }
    else{
      return 2;
    }
  }
  else if (nbArmeeAttaquant == 2){
    if (nbArmeeAttaque >= 2){
      return 1;
    }
    else{
      return 2;
    }
  }
  else{
    return 0;
  }
}

int HeuristicAI::aiNbDesLancersDefenses (std::string paysAttaque, state::State state){
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;

  int nbArmee = 0;
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getPays() == paysAttaque){
      nbArmee = ptr_armee->getNombre();
      break;
    }
  }

  if (nbArmee > 2){
    return 2;
  }
  else{
    return 1;
  }
}

void HeuristicAI::aiGainCartes (int idJoueur, bool victoire, state::State state){
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

int HeuristicAI::aiEchange (int idJoueur, state::State state){
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

void HeuristicAI::aiPlacerNouvellesArmees (int idJoueur, int nouvellesArmees, state::State state){
  int APlacer = nouvellesArmees;
  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;

  std::map<std::string, int> nbArmee;
  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getIdJoueur() == idJoueur){
      nbArmee[ptr_armee->getPays()] = ptr_armee->getNombre();
    }
  }

  while(APlacer != 0){
    int mini = 100;
    std::string paysMini;
    for (std::map<std::string, int>::iterator it = nbArmee.begin(); it != nbArmee.end(); ++it){
      if (it->second < mini){
        mini = it->second;
        paysMini = it->first;
      }
    }

    for(size_t i=0; i<listeArmee.size(); i++){
      ptr_armee = listeArmee[i].get();
      if (ptr_armee->getPays() == paysMini){
        ptr_armee->setNombre(ptr_armee->getNombre() + 1);
        break;
      }
    }

    APlacer -= 1;
  }
}

void HeuristicAI::aiDeplacerArmees (int idJoueur, state::State state){
  state::ElementTab& tabPays = state.getPaysTab();
  std::vector<std::shared_ptr<state::Element>> listePays = tabPays.getElementList();
  state::Element* ptr_pays = 0;

  state::ElementTab& tabArmee = state.getArmeeTab();
  std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
  state::Element* ptr_armee = 0;
  std::vector<std::string> listeArmeeJoueur; // liste des noms des pays appartenant au joueur

  for(size_t i=0; i<listeArmee.size(); i++){
    ptr_armee = listeArmee[i].get();
    if (ptr_armee->getIdJoueur() == idJoueur){
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
            if (ptr_armee->getPays() == frontalier && ptr_armee->getIdJoueur() == idJoueur){
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

  if (ADeplacer.size() == 0){
    return;
  }

  else{
    for(size_t i=0; i<ADeplacer.size(); i++){
      std::string pays = ADeplacer[i];
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
        for(size_t i=0; i<listeArmee.size(); i++){
          ptr_armee = listeArmee[i].get();
          if (ptr_armee->getPays() == paysMini){
            ptr_armee->setNombre(ptr_armee->getNombre() + 1);
            APlacer -= 1;
            break;
          }
        }
      }
    }
  }
}

void HeuristicAI::aiJouer (int numeroTour, int idJoueur, state::State state){
  std::cout << "Début du tour " << numeroTour << " pour le joueur "<< idJoueur << std::endl;
	std::cout << std::endl;

  //initialisation du jeu : uniquement au tour 0 ;
  if (numeroTour == 0){
    //etape 2 de l'initialisation
    engine::AttributionTerritoires::distribution(state, 3);

		//etape 3 de l'initialisation
    std::cout << "Le joueur 1 place ses armées." << std::endl;
    aiRepartitionArmees(1, state);

    std::cout << "Le joueur 2 place ses armées." << std::endl;
    aiRepartitionArmees(2, state);

    std::cout << "Le joueur fictif 3 place ses armées." << std::endl;
    aiRepartitionArmees(3, state);
  }

		//etape 1 du jeu : Choix du pays attaquant
	  std::string paysAttaquant = aiChoixPaysAttaquant(idJoueur, state);
		std::cout << "Le pays attaquant est " << paysAttaquant << "." << std::endl;

		//etape 2 du jeu : Choix du pays que l'on attaque
	  std::string paysAttaque = aiChoixPaysAttaque(idJoueur, paysAttaquant, state);
		std::cout << "Le pays attaqué est " << paysAttaque << "." << std::endl;

		//etape 3 du jeu
	  std::cout << "C'est l'heure de l'attaque !" << std::endl;
	  int nbAttaques = aiNbDesLancersAttaques(paysAttaquant, paysAttaque, state);
		std::cout << "L'attaque lance " << nbAttaques << " dés." << std::endl;

		//etape 5 du jeu
	  std::vector<int> desRouges = engine::Combat::lancerDes(nbAttaques);

		//etape 4 du jeu
	  std::cout << "L'adversaire se défend." << std::endl;
	  int nbDefenses = aiNbDesLancersDefenses(paysAttaque, state);
		std::cout << "La défense lance " << nbDefenses << " dés." << std::endl;

		//etape 6 du jeu
	  std::vector<int> desBleus = engine::Combat::lancerDes(nbDefenses);

	  //etape 7 du jeu
	  bool victoire = engine::IssueDuCombat::victoire(desRouges, desBleus, paysAttaquant,paysAttaque, state);

		//etape 8 du jeu
	  aiGainCartes (idJoueur, victoire, state);
		int nouvellesArmees = 0;

		//etape 9 du jeu
	  int echange = aiEchange (idJoueur, state);
	  while (echange == -1){
	    echange = aiEchange (idJoueur, state);
	  }
	  nouvellesArmees += echange;
		std::cout << "L'échange des cartes rapporte " << echange << " armées." << std::endl;

	  //etape 10 du jeu
		std::cout << "Il y a " << nouvellesArmees << " nouvelles armées à placer." << std::endl;
	  aiPlacerNouvellesArmees (idJoueur, nouvellesArmees, state);
		std::cout << "Les " << nouvellesArmees << " nouvelles armées ont été placées." << std::endl;
	  aiDeplacerArmees (idJoueur, state);
		std::cout << "Le joueur a réalisé les déplacements qu'il souhaitait." << std::endl << std::endl;

	  std::cout << "Fin du tour " << numeroTour << std::endl;
		std::cout << std::endl;
}

}
