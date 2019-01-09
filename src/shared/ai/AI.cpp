#include "AI.h"

namespace ai {

std::list<engine::Commande*> AI::commandes;
std::list<engine::Commande*> AI::undos;
std::list<state::StepId> AI::steps;

void AI::pushCommande(engine::Commande* commande){
  commandes.push_back(commande);
}

}
