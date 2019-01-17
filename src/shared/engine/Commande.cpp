#include "Commande.h"

#include <fstream>

namespace engine {

Commande::Commande(int idJoueurCommande) : idJoueurCommande(idJoueurCommande){
}

Commande::~Commande (){
}

int Commande::getIdJoueurCommande(){
  return this->idJoueurCommande;
}

IdCommande const Commande::getIdCommande (){
  return COMMANDE_c;
}

void Commande::writeToJson(){
  std::ofstream fichier("replay.txt", std::ios::out);
  if(fichier){
    fichier << "{" << std::endl;
    fichier << "\"nomCommande\" : \"Commande\"," << std::endl;
    fichier << "\"idJoueurCommande\" : " << this->idJoueurCommande << std::endl;
    fichier << "}" << std::endl;
    fichier.close();
  }
}

bool Commande::verif (state::State& state){
  return 0;
}

int Commande::getNumeroCarte (){
  return -1;
}

int Commande::getNbArmees (){
  return -1;
}

std::string Commande::getPays(){
  return "#pays";
}

int Commande::getNbDes (){
  return -1;
}

void Commande::exec(state::State& state){
}

void Commande::undo(state::State& state){
}

bool Commande::getFin(){
  return 1;
}

}
