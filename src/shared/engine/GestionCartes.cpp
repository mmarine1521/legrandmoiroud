// Initialisation 4
#include "GestionCartes.h"

namespace engine {

GestionCartes::~GestionCartes (){
}

IdCommande const GestionCartes::getIdCommande (){
  return GESTCARTES;
}

void GestionCartes::piocher (int idJoueur, state::State state){
  state::ElementTab& tabPioche = state.getCartePiocheTab();
  std::vector<std::shared_ptr<state::Element>> listePioche = tabPioche.getElementList();
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  if (listePioche.size() == 0){
    state::ElementTab& tabDefausse = state.getCarteDefausseTab();
    std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
    state::Element* eDefausse = 0;
    for(size_t i=0; i<listeDefausse.size(); i++){
      eDefausse = listeDefausse[i].get();
      listePioche.push_back(eDefausse->clone());
    }
    listeDefausse.clear();
    tabPioche.melange();
  }
  state::Element* ePioche = 0;
  ePioche = listePioche[0].get();
  ePioche->setIdJoueur(idJoueur);
  listeEnjeu.push_back(ePioche->clone());
  listePioche.erase(listePioche.begin());
  std::cout << "Vous avez tiré la carte numéro " << ePioche->getNumero() << "." << std::endl;
}

void GestionCartes::defausser (int numeroCarteDefausse, state::State state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::ElementTab& tabDefausse = state.getCarteDefausseTab();
  std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
  state::Element* eEnjeu = 0;
  for(size_t i=0; i<listeEnjeu.size(); i++){
    eEnjeu = listeEnjeu[i].get();
    if (eEnjeu->getNumero() == numeroCarteDefausse){
      eEnjeu->setIdJoueur(0);
      listeDefausse.push_back(eEnjeu->clone());
      listeEnjeu.erase(listeEnjeu.begin() + i);
    }
    break;
  }
}

void GestionCartes::undoPiocher (state::State state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::ElementTab& tabPioche = state.getCartePiocheTab();
  std::vector<std::shared_ptr<state::Element>> listePioche = tabPioche.getElementList();
  state::Element* ptr_carte;

  ptr_carte = (listeEnjeu.back()).get();
  ptr_carte->setIdJoueur(0);
  listeEnjeu.erase(listeEnjeu.end());
  listePioche.push_back(ptr_carte->clone());
  tabPioche.melange();
}

void GestionCartes::undoDefausser (int idJoueur, state::State state){
  state::ElementTab& tabEnjeu = state.getCarteEnjeuTab();
  std::vector<std::shared_ptr<state::Element>> listeEnjeu = tabEnjeu.getElementList();
  state::ElementTab& tabDefausse = state.getCarteDefausseTab();
  std::vector<std::shared_ptr<state::Element>> listeDefausse = tabDefausse.getElementList();
  state::Element* ptr_carte;

  ptr_carte = (listeDefausse.back()).get();
  ptr_carte->setIdJoueur(idJoueur);
  listeDefausse.erase(listeDefausse.end());
  listeEnjeu.push_back(ptr_carte->clone());
}

}
