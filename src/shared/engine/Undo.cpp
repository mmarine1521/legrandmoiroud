#include "Undo.h"

#include <fstream>

namespace engine {

Undo::Undo(int idJoueurCommande) : Commande(idJoueurCommande){
}

Undo::~Undo (){
}

IdCommande const Undo::getIdCommande (){
  return UNDO_c;
}

void Undo::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::app);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"Undo\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
}

}
