// Generated by dia2code
#ifndef ENGINE__DESATTAQUANT__H
#define ENGINE__DESATTAQUANT__H

#include <vector>

namespace state {
  class State;
};
namespace engine {
  class Des;
}

#include "Des.h"

namespace engine {

  /// class DesAttaquant - 
  class DesAttaquant : public engine::Des {
    // Attributes
  private:
    std::vector<int> desRouges;
    // Operations
  public:
    DesAttaquant (int nbDes);
    DesAttaquant (int nbDes, std::vector<int> desRouges);
    virtual ~DesAttaquant ();
    bool verif (state::State& state);
    void exec (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
  };

};

#endif
