#include "AI.h"

namespace ai {

void AI::pushCommande(engine::Commande* commande){
  commandes.push_back(commande);
}

}
