// Generated by dia2code
#ifndef ENGINE__DES__H
#define ENGINE__DES__H

#include <vector>

namespace engine {
  class Commande;
}

#include "Commande.h"

namespace engine {

  /// class Des - 
  class Des : public engine::Commande {
    // Attributes
  protected:
    int nbDes;
    // Operations
  public:
    Des (int idJoueurCommande, int nbDes);
    virtual ~Des ();
    int getNbDes ();
    static std::vector<int> lancerDes (int nbDes);
    // Setters and Getters
    void setNbDes(int nbDes);
  };

};

#endif
