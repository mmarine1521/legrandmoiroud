// Generated by dia2code
#ifndef ENGINE__COMMANDECOMPOSITE__H
#define ENGINE__COMMANDECOMPOSITE__H

#include <list>

namespace engine {
  class Commande;
};
namespace state {
  class State;
}

#include "Commande.h"

namespace engine {

  /// class CommandeComposite - 
  class CommandeComposite : public engine::Commande {
    // Attributes
  private:
    std::list<Commande*> listeCommandes;
    std::list<Commande*> listeUndos;
    // Operations
  public:
    CommandeComposite (int idJoueurCommande);
    virtual ~CommandeComposite ();
    IdCommande const getIdCommande ();
    void writeToJson ();
    void pushCommandeComposite (Commande* commande);
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
