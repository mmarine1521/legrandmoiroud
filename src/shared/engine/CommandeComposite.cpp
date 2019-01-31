#include "CommandeComposite.h"

#include <fstream>

namespace engine {

CommandeComposite::CommandeComposite (int idJoueurCommande) : Commande(idJoueurCommande){
}

CommandeComposite::~CommandeComposite (){
}

IdCommande const CommandeComposite::getIdCommande(){
  return COMMANDE_COMPOSITE_c;
}

void CommandeComposite::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::app);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"CommandeComposite\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
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
