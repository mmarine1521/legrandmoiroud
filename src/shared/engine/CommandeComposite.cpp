#include "CommandeComposite.h"

namespace engine {

CommandeComposite::CommandeComposite (int idJoueurCommande) : Commande(idJoueurCommande){
}

CommandeComposite::~CommandeComposite (){
}

void CommandeComposite::pushCommandeComposite (Commande* commande){
  this->listeCommandes.push_back(commande);
}

void CommandeComposite::exec (state::State& state){
  while(!this->listeCommandes.empty()){
    Commande* c = this->listeCommandes.front();
    this->listeCommandes.pop_front();
    c->exec(state);
    if(c->getIdCommande() != PASSER_c){
      this->listeUndos.push_back(c);
    }
  }
}

void CommandeComposite::undo (state::State& state){
  while(!this->listeUndos.empty()){
    Commande* c = this->listeUndos.back();
    this->listeCommandes.pop_back();
    c->undo(state);
    delete(c);
  }
}

}
